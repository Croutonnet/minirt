/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:25:15 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 10:28:50 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include <stdio.h>

static void	ambient_light(t_ray *r, t_cylinder cy, t_data *data, t_vector normal)
{
	t_vector	lightdir;
	double		intensity;
	t_color		ambient;

	ambient = mul_vec(add_vec(data->alight.color, cy.base_color),
			data->alight.intensity);
	r->color = ambient;
	r->hit = true;
}

static void	light(t_cylinder cy, t_ray *r, t_data *data, t_vector normal)
{
	t_vector	lightdir;
	double		intensity;
	t_color		ambient;

	ambient = mul_vec(add_vec(data->alight.color, cy.base_color),
			data->alight.intensity);
	lightdir = normalize(minus_vec(data->light.origin, r->touch_point));
	intensity = dot_vec(normal, lightdir) * data->light.intensity;
	r->color = add_vec(mul_vec(cy.base_color, intensity), ambient);
	r->hit = true;
}

t_cylinder create_cylinder(t_vector p, t_vector r, double d, double h, t_vector c)
{
	t_cylinder cylinder;

	cylinder.origin = p;
	cylinder.rotation = r;
	cylinder.radius = d;
	cylinder.height = h;
	cylinder.base_color = c;
	return (cylinder);
}

void	cylinder_intersect_ray(t_cylinder cy, t_ray *r, t_data *data)
{
	double		a;
	t_vector	x;
	double		c;
	double		m;
	double		t;
	t_vector	normal;

	a = dot_vec(r->direction, r->direction) - pow(dot_vec(r->direction, cy.rotation), 2);
	x = minus_vec(r->origin_point, cy.origin);
	r->b = dot_vec(r->direction, x) - dot_vec(r->direction, cy.rotation) * dot_vec(x, cy.rotation);
	c = dot_vec(x, x) - pow(dot_vec(x, cy.rotation), 2) - pow(cy.radius, 2);
	r->dis = pow(r->b, 2) - a * c;
	if (r->dis < 0)
		return ;
	r->t = (-r->b - sqrt(r->dis)) / a;
	m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
	if ((r->t <= 0 || r->t >= INT_MAX) || (m < 0 || m > cy.height))
	{
		r->t = (-r->b + sqrt(r->dis)) / a;
		m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
		if ((r->t <= 0 || r->t >= INT_MAX) || (m < 0 || m > cy.height))
			return ;
	}
	r->touch_point = get_ray_point(*r, r->t);
	normal = normalize(minus_vec(minus_vec(r->touch_point, cy.origin), mul_vec(cy.rotation, m)));
	if (dot_vec(normal, r->direction) > 0)
			normal = mul_vec(normal, -1);
	r->touch_point = get_ray_point(create_ray(r->touch_point, normal), 0.00000000001);
	if (toucher_light(r->touch_point, data) == true)
		light(cy, r, data, normal);
	else
		ambient_light(r, cy, data, normal);
}
