#include "Sphere.h"
#include <algorithm>

Sphere::Sphere(Vec aCenter,double aRadius){
    center = aCenter;
    radius = aRadius;
}

double Sphere::Intersect(Ray ray){
    // https://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
    Vec L = center - ray.origin;
    double t_ca = L.Dot(ray.direction);
    double d2 = L.Dot(L) - (t_ca * t_ca);
    if (d2 > radius * radius) {return 0;}
    double t_hc = sqrt(radius * radius - d2);
    double t0 = t_ca - t_hc;
    double t1 = t_ca + t_hc;

	// printf("t0:%f, T1:%f tca:%f thc: %f radius: %f d2:%f\n",t0,t1,t_ca,t_hc,radius,d2);
    if (t0 > t1) {std::swap(t0,t1);}

    if (t0 < 0){
        t0 = t1;
        if (t0 < 0) return 0;
    }
    return t0;
}
