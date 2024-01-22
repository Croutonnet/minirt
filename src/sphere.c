/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:45 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/22 11:23:15 by rapelcha         ###   ########.fr       */
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
	t_vector	oc;
	float		c;

	oc = minus_vec(r->origin_point, s.origin);
	r->b = 2.0 * dot_vec(r->direction, oc);
	c = pow(length_vec(oc), 2) - pow(s.radius, 2);
	r->dis = pow(r->b, 2) - (4 * c);
}

void	sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data, int id)
{
	t_vector	normal;

	compute_quadratic(r, s);
	if (r->dis >= 0)
	{
		r->t = (-r->b - sqrt(r->dis)) / (2.0f);
		if (r->t <= 0 || INT_MAX <= r->t)
		{
			r->t = (-r->b + sqrt(r->dis)) / (2.0f);
			if (r->t <= 0 || INT_MAX <= r->t)
				return ;
		}
		r->touch_point = get_ray_point(*r, r->t);
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
