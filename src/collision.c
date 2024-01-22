/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:34:49 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/22 14:13:44 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include <stdio.h>

static float tistance(t_vector v1, t_vector v2)
{
	float t;

	t = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	return (t);
}

static bool	cylinder_touchage(t_cylinder cy, t_ray *r, float t_max)
{
	float		a;
	t_vector	x;
	float		b;
	float		c;
	float		m;

	a = dot_vec(r->direction, r->direction) - pow(dot_vec(r->direction, cy.rotation), 2);
	x = minus_vec(r->origin_point, cy.origin);
	b = dot_vec(r->direction, x) - dot_vec(r->direction, cy.rotation) * dot_vec(x, cy.rotation);
	c = dot_vec(x, x) - pow(dot_vec(x, cy.rotation), 2) - pow(cy.radius, 2);
	r->dis = pow(b, 2) - a * c;
	if (r->dis < 0)
		return (false);
	r->t = (-r->b - sqrt(r->dis)) / a;
	m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
	if ((r->t <= 0 || r->t >= INT_MAX) || (m < 0 || m > cy.height))
	{
		r->t = (-r->b + sqrt(r->dis)) / a;
		m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
		if ((r->t <= 0 || r->t >= INT_MAX) || (m < 0 || m > cy.height))
			return (false);
	}
	return (true);
}


static bool sphere_touchage(t_ray *r, t_sphere s, float t_max)
{
	t_vector oc;
	float c;

	oc = minus_vec(r->origin_point, s.origin);
	r->b = dot_vec(r->direction, oc);
	c = pow(length_vec(oc), 2) - pow(s.radius, 2);
	r->dis = pow(r->b, 2) - c;
	if (r->dis >= 0)
	{
		r->t = (-r->b - sqrt(r->dis));
		if (r->t <= 0 || t_max <= r->t)
		{
			r->t = (-r->b + sqrt(r->dis));
			if (r->t <= 0 || t_max <= r->t)
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	toucher_light(t_vector touche_point, t_data *data)
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

bool ray_collision(t_vector touch, t_data *data, t_shape *shape)
{
	t_ray r;
	bool ret;

	ret = false;
	r = create_ray(touch, normalize(minus_vec(data->light.origin, touch)));
	if (shape->type == SPHERE)
		ret = sphere_touchage(&r, shape->geom.sphere, tistance(touch, data->light.origin));
	else if (shape->type == CYLINDER)
		ret = cylinder_touchage(shape->geom.cylinder, &r, tistance(touch, data->light.origin));
	return (ret);
}
