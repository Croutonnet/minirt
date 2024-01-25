/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:34:49 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 14:52:27 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

static double	tistance(t_vector v1, t_vector v2)
{
	double	t;

	t = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	return (t);
}

static bool	cylinder_touchage(t_cylinder cy, t_ray *r, double t_max)
{
	double		a;
	t_vector	x;
	double		c;
	double		m;

	a = dot_vec(r->direction, r->direction) - \
	pow(dot_vec(r->direction, cy.rotation), 2);
	x = minus_vec(r->origin_point, cy.origin);
	r->b = dot_vec(r->direction, x) - dot_vec(r->direction, cy.rotation) * \
	dot_vec(x, cy.rotation);
	c = dot_vec(x, x) - pow(dot_vec(x, cy.rotation), 2) - pow(cy.radius, 2);
	r->dis = pow(r->b, 2) - a * c;
	if (r->dis < 0)
		return (false);
	r->t = (-r->b - sqrt(r->dis)) / a;
	m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
	if ((r->t <= 0 || r->t >= t_max) || (m < 0 || m > cy.height))
	{
		r->t = (-r->b + sqrt(r->dis)) / a;
		m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
		if ((r->t <= 0 || r->t >= t_max) || (m < 0 || m > cy.height))
			return (false);
	}
	return (true);
}

static bool	sphere_touchage(t_ray *r, t_sphere s, double t_max)
{
	t_vector	oc;
	double		c;

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

static bool	plane_touchage(t_plane p, t_ray *r, double t_max)
{
	t_vector	x;
	double		a;
	double		b;

	x = mul_vec(minus_vec(r->origin_point, p.origin), -1);
	a = dot_vec(x, p.axis);
	b = dot_vec(r->direction, p.axis);
	if (a == 0 || b == 0)
		return (false);
	r->t = a / b;
	if (r->t <= 0 || r->t >= t_max)
		return (false);
	return (true);
}

bool	ray_collision(t_vector touch, t_data *data, t_shape *shape)
{
	t_ray	r;
	bool	ret;

	ret = false;
	r = create_ray(touch, normalize(minus_vec(data->light.origin, touch)));
	if (shape->type == SPHERE)
		ret = sphere_touchage(&r, shape->geom.sphere, \
		tistance(touch, data->light.origin));
	else if (shape->type == CYLINDER)
		ret = cylinder_touchage(shape->geom.cylinder, &r, \
		tistance(touch, data->light.origin));
	else if (shape->type == PLANE)
		ret = plane_touchage(shape->geom.plane, &r, \
		tistance(touch, data->light.origin));
	return (ret);
}
