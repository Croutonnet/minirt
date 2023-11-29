#include "../include/ray.h"
#include "../include/image.h"
#include <stdio.h>

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void clear_img(mlx_image_t *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < IMAGE_HEIGHT)
	{
	x = 0;
	while (x < IMAGE_WIDTH)
	{
			mlx_put_pixel(image, x, y, ft_pixel(0, 0, 0, 255));
			x++;
		}
		y++;
	}
}

void create_rays(t_viewport *view, t_shapes_arr *arr,mlx_image_t *image)
{
	int			x;
	int			y;
	t_ray		r;
	t_vector	dest;
	t_vector	center;
	t_vector	temp;
	t_hitdata	hitdata;
	int			id;

	id = 0;
	x = 0;
	y = 0;
	clear_img(image);
	center = view->pixel00_loc;
	dest = normalize(minus_vec(view->camera_center, center));

	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			r = create_ray(view->camera_center, dest);
			
			id = 0;
			while (id < arr->count)
			{
				t_shape *shape;
				shape = &arr->shapes[id];
				if (shape->type == SPHERE)
					hitdata = sphere_intersect_ray(shape->geom.sphere, &r);
				if (hitdata.hit == true)
					mlx_put_pixel(image, x, y, r.color);
				else
					mlx_put_pixel(image, x, y, ft_pixel(0,100,0,255));
				temp = add_vec(mul_vec(view->pixel_delta_v, x), mul_vec(view->pixel_delta_u, y));
				center = add_vec(view->pixel00_loc, temp);
				dest = normalize(minus_vec(center, view->camera_center));
				if (hitdata.hit == true)
					break;
				id++;
			}
			x++;
		}
		y++;
	}
	}

t_ray create_ray(t_vector origin, t_vector ray_dir)
{
	t_ray	r;

	r.origin_point = origin;
	r.ray_dir = ray_dir;

	return (r);
}

// renvoi le point p (x,y,z) dintersection du rayon a la distance t
t_vector get_ray_point(t_ray r, float t)
{
	t_vector intersec;

	intersec.x = r.origin_point.x + (r.ray_dir.x * t);
	intersec.y = r.origin_point.y + (r.ray_dir.y * t);
	intersec.z = r.origin_point.z + (r.ray_dir.z * t);

	return (intersec);
}