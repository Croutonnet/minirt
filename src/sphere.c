#include "../include/ray.h"
#include <stdio.h>

t_sphere create_sphere(float x, float y, float z, float radius)
{
    t_sphere s;
    s.origin.x = x;
    s.origin.y = y;
    s.origin.z = z;
    s.radius = radius;
    return (s);
}


void sphere_intersect_ray(t_sphere s, t_ray *r)
{
    t_vector    oc = minus_vec(r->origin_point, s.origin); //Direction vers le centre de la sphere
    float       b = 2.0 * dot_vec(minus_vec(r->origin_point, r->plane_point), oc);
    float       c = pow(length_vec(oc), 2) - pow(s.radius, 2); //
    float       dis = pow(b, 2) - (4 * c); //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois

    if (dis >= 0)
        r->hit = true;
    else
        r->hit = false;
}