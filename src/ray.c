#include "../include/ray.h"
#include "../include/image.h"


void create_rays()
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < IMAGE_HEIGHT)
    {
        x = 0;
        while (x < IMAGE_WIDTH)
        {
            t_ray r;

            //create_ray(r, )
            x++;
        }
        y++;
    }
}

t_ray create_ray(t_ray r, t_vector origin, t_vector plane_point)
{
    r.hit = false;
    r.t = 0;
    r.origin_point = origin;
    r.plane_point = plane_point;

    return (r);
}

// renvoi le point p (x,y,z) dintersection du rayon a la distance t
t_vector get_ray_point(t_ray r)
{
    t_vector intersec;

    intersec.x = r.origin_point.x + (r.plane_point.x * r.t);
    intersec.y = r.origin_point.y + (r.plane_point.y * r.t);
    intersec.z = r.origin_point.z + (r.plane_point.z * r.t);

    return (intersec);
}