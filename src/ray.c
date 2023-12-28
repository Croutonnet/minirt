#include "../include/ray.h"
#include "../include/image.h"
#include <stdio.h>

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
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
		int py = (y/IMAGE_HEIGHT)*160;
			mlx_put_pixel(image, x, y, ft_pixel(75 + py, 75 + py, 255, 255));
			x++;
		}
		y++;
	}
}

void create_rays(t_viewport *view, t_data *data, mlx_image_t *image)
{
	int			x;
	int			y;
	t_ray		r;
	t_vector	dest;
	//t_vector	left_corner;
	t_vector	temp;
	t_vector	point;
	t_color		pixel;
	int			id;

	id = 0;
	x = 0;
	y = 0;
	clear_img(image);
	//left_corner = view->pixel00_loc;
	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			temp = add_vec(mul_vec(view->pixel_delta_v, x), mul_vec(view->pixel_delta_u, y));
			point = add_vec(view->pixel00_loc, temp);
			dest = normalize(minus_vec(point, view->camera_center));
			r = create_ray(r, view->camera_center, dest);
			id = 0;
			while (id < data->shapes.count)
			{
				t_shape *shape;
				shape = &data->shapes.shapes[id];
				if (shape->type == SPHERE)
					pixel = sphere_intersect_ray(shape->geom.sphere, &r, data);
				else if (shape->type == CYLINDER)
					pixel = cylinder_intersect_ray(shape->geom.cylinder, &r, data->light);
				if (r.hit == true)
					mlx_put_pixel(image, x, y, ft_pixel(pixel.x * 255, pixel.y * 255, pixel.z * 255, 255));
				id++;
			}
			x++;
		}
		y++;
	}
}

t_ray create_ray(t_ray r, t_vector origin, t_vector dir)
{
	r.hit = false;
	r.origin_point = origin;
	r.direction = dir;
	return (r);
}

// renvoi le point p (x,y,z) dintersection du rayon a la distance t
t_vector get_ray_point(t_ray r, float t)
{
	t_vector intersec;

	intersec.x = r.origin_point.x + (r.direction.x * t);
	intersec.y = r.origin_point.y + (r.direction.y * t);
	intersec.z = r.origin_point.z + (r.direction.z * t);
	return (intersec);
}
