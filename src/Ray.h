#pragma once
#include "Vec.h"


class Ray{
    private:
    public:
        Vec origin;
        Vec direction;
        Ray();
        Ray(Vec origin, Vec direction);
};