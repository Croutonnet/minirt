/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:25:04 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 13:51:00 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/image.h"
#include <stdio.h>
#include <math.h>

static int32_t	ft_pixel(double r, double g, double b)
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

static void	ray_utils(t_data *data)
{
	t_shape	*shape;
	t_ray	r;
	int		id;

	data->close_ray.hit = false;
	data->close_ray.t = INFINITY;
	data->point = \
	add_vec(data->final_viewport.pixel00_loc, data->delta);
	data->dir = normalize(minus_vec(data->point, \
	data->final_viewport.camera_center));
	id = 0;
	while (id < data->shapes.count)
	{
		shape = &data->shapes.shapes[id];
		r = create_ray(data->final_viewport.camera_center, data->dir);
		if (shape->type == SPHERE)
			sphere_intersect_ray(shape->geom.sphere, &r, data);
		else if (shape->type == CYLINDER)
			cylinder_intersect_ray(shape->geom.cylinder, &r, data);
		else if (shape->type == PLANE)
			plane_intersect_ray(shape->geom.plane, &r, data);
		if (r.hit == true && r.t < data->close_ray.t)
			data->close_ray = r;
		id++;
	}
}

void	create_rays(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	clear_img(data->image);
	while (y < IMAGE_HEIGHT)
	{
		x = 0;
		while (x < IMAGE_WIDTH)
		{
			data->delta = \
			add_vec(mul_vec(data->final_viewport.pixel_delta_v, x), \
			mul_vec(data->final_viewport.pixel_delta_u, y));
			ray_utils(data);
			if (data->close_ray.hit == true)
				mlx_put_pixel(data->image, x, y, \
				ft_pixel(data->close_ray.color.x, data->close_ray.color.y, \
				data->close_ray.color.z));
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
	temp_ray.color = create_vector(1, 1, 1);
	temp_ray.t = INFINITY;
	return (temp_ray);
}
