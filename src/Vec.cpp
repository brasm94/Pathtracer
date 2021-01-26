#include "Vec.h"


Vec::Vec(){
    x = 0;
    y = 0;
    z = 0;
}
Vec::Vec(double ax, double ay, double az){
    x = ax;
    y = ay;
    z = az;
}
Vec Vec::operator+(const Vec &b){
    return Vec(x + b.x, y + b.y, z + b.z);
}
Vec Vec::operator-(const Vec &b){
    return Vec(x - b.x, y - b.y, z - b.z);
}
//Scalar multiply
Vec Vec::operator*(double b){
    return Vec(x * b, y * b, z * b);
}
bool Vec::operator==(const Vec &b){
    return (x == b.x) && (y == b.y) && (z == b.z); 
}
Vec Vec::Multiply(const Vec &b){
    return Vec(x * b.x, y * b.y, z * b.z);
}
double Vec::Dot(const Vec &b){
    return x * b.x + y * b.y + z * b.z;
}
Vec Vec::Cross(const Vec &b){
    return Vec( (y * b.z) - (z * b.y),
                (z * b.x) - (x * b.z),
                (x * b.y) - (y * b.x));
}
Vec Vec::Norm(){
    double bottom = sqrt(x*x + y*y + z*z);
    return Vec(x/bottom, y/bottom, z/bottom);
}
void Vec::PrintObject(){
    printf("X: %f Y: %f Z: %f\n",x,y,z);
}
std::string Vec::ToRGB(){
    return std::to_string(int(x)) + " " + std::to_string(int(y)) + " " + std::to_string(int(z)) + " ";
}
double Vec::Magnitude(){
    return sqrt(x*x + y*y + z*z);
}