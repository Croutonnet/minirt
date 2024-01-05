#include "../include/ray.h"
#include "../include/image.h"
#include <stdio.h>

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

static void	clear_img(mlx_image_t *image)
{
	int	x;
	int	y;
	int	py;

	x = 0;
	y = 0;
	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			py = (y / IMAGE_HEIGHT) * 160;
			mlx_put_pixel(image, x, y, ft_pixel(75 + py, 75 + py, 255, 255));
			x++;
		}
		y++;
	}
}

static bool ray_intersect(t_ray *r, t_data *data)
{
    t_color pixel;
    t_color c;
    t_shape *shape;

    int         min_t;
    int         id;
    t_shape *obj = NULL;
    pixel.x = 0;
    pixel.y = 0;
    pixel.z = 0;
    id = 0;
    min_t = INT32_MAX;
    while (id < data->shapes.count)
    {
        shape = &data->shapes.shapes[id];
        if (shape->type == SPHERE)
            c = sphere_intersect_ray(shape->geom.sphere, r, data);   
        else if (shape->type == PLANE)
            c = plane_intersect_ray(shape->geom.plane, r, data->light, data->alight);
        // else if (shape->type == CYLINDER)
        //     pixel = cylinder_intersect_ray(shape->geom.cylinder, r);
        if (r->hit == true && r->t < min_t)
        {
            obj = shape;
            pixel = c;
            min_t = r->t;
        }
        id++;
    }
    if (obj != NULL)
    {
        r->obj = obj;
        r->color = pixel;
        r->t = min_t;
        return true;
    }
    return false;
}

void create_rays(t_viewport *view, t_data *data,mlx_image_t *image)
{
    int         x;
    int         y;
    t_ray       r;
    t_vector    dest;
    t_vector    temp;
    t_vector point;
    t_color pixel;
    t_ray r_lightDir;
    x = 0;
    y = 0;
    clear_img(image);

    while (y < IMAGE_HEIGHT)
    {
        x = 0;
        while (x < IMAGE_WIDTH)
        {
            temp = add_vec(mul_vec(view->pixel_delta_v, x), mul_vec(view->pixel_delta_u, y));
            point = add_vec(view->pixel00_loc, temp);
            dest = normalize(minus_vec(point, view->camera_center));
            r = create_ray(r, view->camera_center, dest);
            
            if (ray_intersect(&r, data))
            {
                pixel = r.color;
                // calcul lumiere
                t_vector intersect = normalize(minus_vec(get_ray_point(r, r.t),data->light.origin));
                r_lightDir = create_ray(r_lightDir, data->light.origin, intersect);
                bool isShadow = false;
                if (ray_intersect(&r_lightDir, data) && r.obj != r_lightDir.obj)
                {
                    isShadow = true;
                }
                if (isShadow)
                    mlx_put_pixel(image, x, y, ft_pixel(pixel.x * 100, pixel.y * 100,pixel.z * 100 , 255));
                else
                    mlx_put_pixel(image, x, y, ft_pixel(pixel.x * 255, pixel.y * 255, pixel.z * 255, 255));
            }
            x++;
        }
        y++;
    }
}

t_ray	create_ray(t_ray r, t_vector origin, t_vector dir)
{
	r.hit = false;
	r.origin_point = origin;
	r.direction = dir;
	return (r);
}

// renvoi le point p (x,y,z) dintersection du rayon a la distance t
t_vector	get_ray_point(t_ray r, float t)
{
	t_vector	intersec;

	intersec.x = r.origin_point.x + (r.direction.x * t);
	intersec.y = r.origin_point.y + (r.direction.y * t);
	intersec.z = r.origin_point.z + (r.direction.z * t);

	return (intersec);
}