/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:36 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 12:59:45 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include <stdio.h>
#include "../include/light.h"

t_plane	create_plane(t_vector pPosition, t_vector p_axis, t_color p_Color)
{
	t_plane	p;

	p.origin.x = pPosition.x;
	p.origin.y = pPosition.y;
	p.origin.z = pPosition.z;
	p.axis = p_axis;
	p.base_color = p_Color;
	return (p);
}

static void	ambient_light(t_ray *r, t_plane p, t_data *data)
{
	t_color		ambient;

	ambient = mul_vec(add_vec(data->alight.color, p.base_color),
			data->alight.intensity);
	r->color = ambient;
	r->hit = true;
}

static void	light(t_plane p, t_ray *r, t_data *data, t_vector normal)
{
	t_vector	lightdir;
	double		intensity;
	t_color		ambient;

	ambient = mul_vec(add_vec(data->alight.color, p.base_color),
			data->alight.intensity);
	lightdir = normalize(minus_vec(data->light.origin, r->touch_point));
	intensity = dot_vec(normal, lightdir) * data->light.intensity;
	r->color = add_vec(mul_vec(p.base_color, intensity), ambient);
	r->hit = true;
}

void	plane_intersect_ray(t_plane p, t_ray *r, t_data *data)
{
	t_vector	x;
	double		a;
	double		b;
	t_vector	normal;

	x = mul_vec(minus_vec(r->origin_point, p.origin), -1);
	a = dot_vec(x, p.axis);
	b = dot_vec(r->direction, p.axis);
	if (a == 0 || b == 0)
		return ;
	r->t = a / b;
	if (r->t <= 0 || r->t >= INT_MAX)
		return ;
	r->touch_point = get_ray_point(*r, r->t);
	if (b < 0)
		normal = p.axis;
	else
		normal = mul_vec(p.axis, -1);
	r->touch_point = get_ray_point(create_ray(r->touch_point, normal), \
	0.00000000001);
	if (toucher_light(r->touch_point, data) == true)
		light(p, r, data, normal);
	else
		ambient_light(r, p, data);
}
