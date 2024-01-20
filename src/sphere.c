/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:45 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/20 15:36:08 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include <stdio.h>
#include "../include/light.h"
#include <limits.h>

static void	ambient_light(t_ray *r, t_sphere s, t_data *data, t_vector normal)
{
	t_vector	lightdir;
	float		intensity;
	t_color		ambient;

	ambient = mul_vec(add_vec(data->alight.color, s.base_color),
			data->alight.intensity);
	r->color = ambient;
	r->hit = true;
}

static bool	toucher_light(t_vector touche_point, t_data *data)
{
	int		id;
	bool	ret;

	id = 0;
	ret = false;
	while (id < data->shapes.count)
	{
		ret = ray_collision(touche_point, data, &data->shapes.shapes[id]);
		if (ret == true)
			return (false);
		id++;
	}
	return (true);
}

// r->color = add_vec(mul_vec(s.base_color, intensity), ambient);
static void	light(t_sphere s, t_ray *r, t_data *data, t_vector normal)
{
	t_vector	lightdir;
	float		intensity;
	t_color		ambient;

	ambient = mul_vec(add_vec(data->alight.color, s.base_color),
			data->alight.intensity);
	lightdir = normalize(minus_vec(data->light.origin, r->touch_point));
	intensity = dot_vec(normal, lightdir) * data->light.intensity;
	r->color = add_vec(mul_vec(s.base_color, intensity), ambient);
	r->hit = true;
}

static void	compute_quadratic(t_ray *r, t_sphere s)
{
	r->oc = minus_vec(r->origin_point, s.origin);
	r->b = 2.0 * dot_vec(r->direction, r->oc);
	r->c = pow(length_vec(r->oc), 2) - pow(s.radius, 2);
	r->dis = pow(r->b, 2) - (4 * r->c);
}

void	sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data, int id)
{
	t_vector	normal;

	compute_quadratic(r, s);
	if (r->dis >= 0)
	{
		r->t2 = (-r->b - sqrt(r->dis)) / (2.0f);
		if (r->t2 <= 0 || INT_MAX <= r->t2)
		{
			r->t2 = (-r->b + sqrt(r->dis)) / (2.0f);
			if (r->t2 <= 0 || INT_MAX <= r->t2)
				return ;
		}
		r->touch_point = get_ray_point(*r, r->t2);
		normal = normalize(minus_vec(r->touch_point, s.origin));
		if (dot_vec(r->direction, normal) > 0)
			normal = mul_vec(normal, -1);
		r->touch_point = get_ray_point(create_ray(r->touch_point, normal), 0.001);
		if (toucher_light(r->touch_point, data) == true)
			light(s, r, data, normal);
		else
			ambient_light(r, s, data, normal);
	}
	else
		r->hit = false;
}
