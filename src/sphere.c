#include "../include/ray.h"
#include <stdio.h>
#include <limits.h>

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
    float       b = dot_vec(r->ray_dir, oc);
    float       c = pow(length_vec(oc), 2) - pow(s.radius, 2); //
    float       dis = pow(b, 2) - c; //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois
    float       sqrtd = sqrt(dis);
    r->t = -b - sqrtd; // c'est la distance entre le camera et le point toucher par le ray
    if (r->t <= 0 || r->t >= INT_MAX){
        r->t = -b + sqrtd; // c'est la distance entre le camera et le point toucher par le ray
        if (r->t <= 0 || r->t >= INT_MAX){
            r->hit_front = false;
            return ;
        }
    }
    t_vector touch = get_ray_point(*r, r->t); //Le point qu'on a toucher dans la sphere
    r->normale_dir = normalize(minus_vec(touch, s.origin)); //La direction entre le centre de la sphere et le point touché
    if (dot_vec(r->ray_dir, r->normale_dir) > 0){
        r->normale_dir = mul_vec(r->normale_dir, -1);
    }
    touch = get_ray_point(create_ray(touch, r->normale_dir), 0.00000000001);
}