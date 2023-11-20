#include "../include/sphere.h"

t_sphere create_sphere(float x, float y, float z, float radius)
{
    t_sphere s;
    s.origin.x = x;
    s.origin.y = y;
    s.origin.z = z;
    s.radius = radius;

    return (s);
}

static float find_a(t_ray r)
{
    float a;
    a = pow(r.plane_point.x,2) + pow(r.plane_point.y,2) + pow(r.plane_point.z,2);
    return a;
}

static float find_b(t_sphere s, t_ray r)
{
    float b;
    b = (2*(r.origin_point.x + r.plane_point.x)) + 
    (2*(r.origin_point.y + r.plane_point.y)) + 
    (2*(r.origin_point.z + r.plane_point.z));
    return b;
}

static float find_c(t_sphere s, t_ray r)
{
    float c;
    c = pow(r.origin_point.x,2) + pow(r.origin_point.y,2) + 
    pow(r.origin_point.z,2) - pow(s.radius,2);
    return c;
}

t_vector sphere_intersect_ray(t_sphere s, t_ray r)
{
    float a = find_a(r);
    float b = find_b(s, r);
    float c = find_c(s, r);

    // calcul du determinant
    // ...
    // calcul de t
    // ...
    // calcul du point dintersection
    // ...
}