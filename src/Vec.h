#pragma once
#include <math.h>
#include <stdio.h>
#include <string>


class Vec {
    private:
        double x, y, z;
    public:
        Vec();
        Vec(double ax, double ay, double az);
        void PrintObject();
        Vec Norm();
        Vec operator+(const Vec &b);
        Vec operator-(const Vec &b);
        //Scalar multiply
        Vec operator*(double b);
        bool operator==(const Vec &b);
        Vec Multiply(const Vec &b);
        double Dot(const Vec &b);
        Vec Cross(const Vec &b);
        std::string ToRGB();
        double Magnitude();
};