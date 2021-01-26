#include "Test.h"
#include "Vec.h"
#include "Sphere.h"

Test::Test(){

}
void Test::RunAll(){
    TestVec();
    TestSphereIntersect();
}

bool Test::TestVec(){
    Vec a = Vec(1.0, 2.0, 3.0);
    Vec b = Vec(1.0, 2.0, 3.0);
    bool passing = true;
    if (!((a + b) == Vec(2.0,4.0,6.0))){
        printf("Vec Addition Failed\n");
    }
    if (!((a - b) == Vec(0.0,0.0,0.0))){
        printf("Vec Sub Failed\n");
    }
    if(! (a * 2 == Vec(2,4,6))){
        printf("Vec * Failed\n");
    }
    if (!(a == b)){
        printf("Vec equal Failed\n");
    }
    if (! (a.Multiply(b) == Vec(1,4,9))){
        printf("Vec Multiply Failed\n");
    }
    if (! (a.Dot(b) == 14.0)){
        printf("Vec Dot Failed\n");
    }
    if (! (a.Norm() == a * (1.0 / sqrt(14.0)))){
        printf("Vec Norm Failed\n");
    }
    if (passing){
     printf("All Vec passed\n");
    }
    return passing;
}

bool Test::TestSphereIntersect(){
    bool passing = true;
    // Test 1
    Ray ray = Ray(Vec(0,0,0), Vec(0,0,1));
    Sphere sphere = Sphere(Vec(0,0,2), 1);
    double result = sphere.Intersect(ray);
    if (result != 1){
        printf("Sphere Intersect infront Failed\n");
        passing = false;
    }
    //Test 2
    ray.origin = Vec(0,0,2);
    result = sphere.Intersect(ray);
    if (result != 1){
        printf("Sphere Intersect inside Failed\n");
        passing = false;
    }
    if (passing){
     printf("All Sphere Intersect passing passed\n");
    }
    return passing;
}