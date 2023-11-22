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

// static float find_a(t_ray r)
// {
//     float a;
//     a = pow(r.plane_point.x,2) + pow(r.plane_point.y,2) + pow(r.plane_point.z,2);
//     return a;
// }

// static float find_b(t_sphere s, t_ray r)
// {
//     float b;
//     b = (2*(r.origin_point.x + r.plane_point.x)) + 
//     (2*(r.origin_point.y + r.plane_point.y)) + 
//     (2*(r.origin_point.z + r.plane_point.z));
//     return b;
// }

// static float find_c(t_sphere s, t_ray r)
// {
//     float c;
//     c = pow(r.origin_point.x,2) + pow(r.origin_point.y,2) + 
//     pow(r.origin_point.z,2) - pow(s.radius,2);
//     return c;
// }

void sphere_intersect_ray(t_sphere s, t_ray *r)
{
    // float a = find_a(r);
    // float b = find_b(s, r);
    // float c = find_c(s, r);
    // je fais les calculs de la fonction quadratique pour aller chercher le discriminant et ensuite le point le plus proche touché (si touché)
    t_vector    oc = minus_vec(r->origin_point, s.origin); //Direction vers le centre de la sphere
    float       b = dot_vec(oc, minus_vec(r->origin_point, r->plane_point)); //
    float       c = pow(length_vec(oc), 2) - pow(s.radius, 2); //
    float       dis = pow(b, 2) - c; //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois

    if (dis >= 0)
        r->hit = true;
    else
        r->hit = false;
}