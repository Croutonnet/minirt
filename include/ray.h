#ifndef RAY_H
#define RAY_H
#include "stdbool.h"
#include "vector.h"

typedef struct s_ray
{
    bool hit;
    float t;
    t_vector plane_point;
    t_vector origin_point;
}t_ray;

#endif