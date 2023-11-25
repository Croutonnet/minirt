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
    t_vector    dir;
    t_vector    center;
    t_vector    temp;

    x = 0;
    y = 0;
    center = view->pixel00_loc;
    dir = minus_vec(view->camera_center, center);
    while (y < IMAGE_HEIGHT)
    {
        x = 0;
        while (x < IMAGE_WIDTH)
        {
            r = create_ray(r, view->camera_center, dir); //creer le ray du centre de la camera vers le point choisi
            sphere_intersect_ray(sphere, &r); //envoie le Ray dans la direction, si r.hit est true, c'est qu'il a toucher quelque chose
            if (r.hit == true)
                mlx_put_pixel(image, x, y, ft_pixel(255, 0, 0, 255));
            else
                mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
            temp = add_vec(mul_vec(view->pixel_delta_v, x), mul_vec(view->pixel_delta_u, y)); //calcul la direction vers le prochain pixel
            center = add_vec(view->pixel00_loc, temp); // recentre le centre au centre du prochain pixel a droite
            dir = normalize(minus_vec(center, view->camera_center)); // normalise la direction de la camera vers le pixel
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