#include "../include/ray.h"
#include <stdio.h>

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

t_sphere create_sphere(float x, float y, float z, float radius)
{
    t_sphere s;
    s.origin.x = x;
    s.origin.y = y;
    s.origin.z = z;
    s.radius = radius;
    return (s);
}

// TODO make this return color
// TODO float to rgba
void sphere_intersect_ray(t_sphere s, t_ray *r)
{
    t_vector    oc = minus_vec(r->origin_point, s.origin); //Direction vers le centre de la sphere
    float       b = 2.0 * dot_vec(minus_vec(r->origin_point, r->direction), oc);
    float       c = pow(length_vec(oc), 2) - pow(s.radius, 2); //
    float       dis = pow(b, 2) - (4 * c); //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois

    if (dis >= 0)
    {
        // calcule la valeur de t
        //float t1 = (-b + sqrt(dis))/2.0f;
        float t2 = (-b - sqrtf(dis))/(2.0f);
        // calcule points de collision
        t_vector h2 = get_ray_point(*r, t2);

        // calcul normal
        t_vector normal = normalize(minus_vec(h2, s.origin));


        // // calcul lumiere
        // t_vector lightTest = normalize(create_vector(10,10,-10));
        // t_vector lightDir = minus_vec(s.origin,lightTest);
        // float intensity =  dot_vec(normal, lightDir) * 60;



        // if (intensity < 0)
        //     intensity = 0;
        // if (intensity > 255)
        //     intensity = 255;
        r->color = ft_pixel((normal.x * 0.5 + 0.5f) * 255,(normal.y * 0.5f + 0.5f) * 255,(normal.z * 0.5f + 0.5f) * 255,255);
        r->hit = true;
    }
    else
        r->hit = false;
}