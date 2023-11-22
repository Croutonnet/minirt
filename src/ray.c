#include "../include/ray.h"
#include "../include/image.h"
#include <stdio.h>

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void create_rays(t_viewport *view, t_sphere sphere, mlx_image_t *image)
{
    int         x;
    int         y;
    t_ray       r;
    t_vector    dest;
    t_vector    center;
    t_vector    temp;

    x = 0;
    y = 0;
    center = view->pixel00_loc;
    dest = minus_vec(view->camera_center, center);
    while (y < IMAGE_HEIGHT)
    {
        x = 0;
        while (x < IMAGE_WIDTH)
        {
            r = create_ray(r, view->camera_center, dest);
            sphere_intersect_ray(sphere, &r);
            if (r.hit == true)
                mlx_put_pixel(image, x, y, ft_pixel(255, 0, 0, 255));
            else
                mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
            temp = add_vec(mul_vec(view->pixel_delta_v, x), mul_vec(view->pixel_delta_u, y));
            center = add_vec(view->pixel00_loc, temp);
            dest = normalize(minus_vec(center, view->camera_center));
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