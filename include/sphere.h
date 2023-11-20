#ifndef SPHERE_H
#define SPHERE_H

#include "../include/vector.h"
#include "../include/ray.h"

typedef struct s_sphere 
{
    t_vector origin; // not used for now
    float radius;
}t_sphere;

t_sphere create_sphere(float x, float y, float z, float radius);
t_vector sphere_intersect_ray(t_sphere s, t_ray r);

#endif