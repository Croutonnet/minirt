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

void create_rays(t_data *data)
{
	int			x;
	int			y;
	t_ray		r;
	t_vector	dir;
	t_vector	delta;
	t_vector	point;
	t_color		pixel;
	int			id;

	y = 0;
	printf("CAM COORD:");
	print_vec(data->viewport.camera_center);
	printf("P_00");
	print_vec(data->viewport.pixel00_loc);
	clear_img(data->image);
	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			delta = add_vec(mul_vec(data->viewport.pixel_delta_v, x), mul_vec(data->viewport.pixel_delta_u, y));
			point = add_vec(data->viewport.pixel00_loc, delta);
			dir = normalize(minus_vec(point, data->viewport.camera_center));
			r = create_ray(data->viewport.camera_center, dir);
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
					mlx_put_pixel(data->image, x, y, ft_pixel(pixel.x * 255, pixel.y * 255, pixel.z * 255, 255));
				id++;
			}
			x++;
		}
		y++;
	}
}

t_ray create_ray(t_vector origin, t_vector dir)
{
	t_ray temp_ray;

	temp_ray.hit = false;
	temp_ray.origin_point = origin;
	temp_ray.direction = dir;
	return (temp_ray);
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
