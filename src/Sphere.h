#include "Vec.h"
#include "Ray.h"

class Sphere{
    private:
        Vec center;
    public:
        double radius;
        Sphere(Vec aCenter, double aRadius);
        double Intersect(Ray ray);

};
