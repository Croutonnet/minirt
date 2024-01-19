/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:25:04 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/19 15:40:22 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/image.h"
#include <stdio.h>
#include <math.h>

static int32_t ft_pixel(float r, float g, float b)
{
	r = fmin(255, r * 255);
	g = fmin(255, g * 255);
	b = fmin(255, b * 255);
	
	return ((int)r << 24 | (int)g << 16 | (int)b << 8 | 255);
}

static void	clear_img(mlx_image_t *image)
{
	int		x;
	int		y;
	int		py;
	t_color	oui;

	x = 0;
	y = 0;
	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			py = (y / IMAGE_HEIGHT) * 160;
			oui = normalize(create_vector(75 + py, 75 + py, 255));
			mlx_put_pixel(image, x, y, ft_pixel(oui.x, oui.y, oui.z));
			x++;
		}
		y++;
	}
}

void create_rays(t_data *data)
{
	int			x;
	int			y;
	int			id;
	t_ray		r;
	t_vector	dir;
	t_vector	delta;
	t_vector	point;
	t_ray		close_ray;

	y = 0;
	clear_img(data->image);
	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			close_ray.hit = false;
			close_ray.t2 = INFINITY;
			delta = add_vec(mul_vec(data->final_viewport.pixel_delta_v, x), mul_vec(data->final_viewport.pixel_delta_u, y));
			point = add_vec(data->final_viewport.pixel00_loc, delta);
			dir = normalize(minus_vec(point, data->final_viewport.camera_center));
			r = create_ray(data->final_viewport.camera_center, dir);
			id = 0;
			while (id < data->shapes.count) 
			{
				t_shape	*shape;
				shape = &data->shapes.shapes[id];
				if (shape->type == SPHERE)
					sphere_intersect_ray(shape->geom.sphere, &r, data, id);
				// else if (shape->type == CYLINDER)
				// 	cylinder_intersect_ray(shape->geom.cylinder, &r);
				// else if (shape->type == PLANE)
				// 	pixel = plane_intersect_ray(shape->geom.plane, &r, data);
				if (r.hit == true && r.t2 < close_ray.t2)
					close_ray = r;
				id++;
			}
			if (close_ray.hit == true)
				mlx_put_pixel(data->image, x, y, ft_pixel(close_ray.color.x, close_ray.color.y, close_ray.color.z));
			x++;
		}
		y++;
	}
}

t_ray	create_ray(t_vector origin, t_vector dir)
{
	t_ray	temp_ray;

	temp_ray.hit = false;
	temp_ray.origin_point = origin;
	temp_ray.direction = dir;
	temp_ray.t2 = INFINITY;
	return (temp_ray);
}

t_vector	get_ray_point(t_ray r, float t)
{
	t_vector	intersec;

	intersec.x = r.origin_point.x + (r.direction.x * t);
	intersec.y = r.origin_point.y + (r.direction.y * t);
	intersec.z = r.origin_point.z + (r.direction.z * t);

	return (intersec);
}
