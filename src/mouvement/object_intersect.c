/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:24 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 08:57:18 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mouvement.h"
#include "../../include/ray.h"

double	cylinder_intersect_mouv(t_cylinder cy, t_ray *r)
{
	double		a;
	t_vector	x;
	double		c;
	double		m;

	a = dot_vec(r->direction, r->direction) - pow(dot_vec(r->direction, cy.rotation), 2);
	x = minus_vec(r->origin_point, cy.origin);
	r->b = dot_vec(r->direction, x) - dot_vec(r->direction, cy.rotation) * dot_vec(x, cy.rotation);
	c = dot_vec(x, x) - pow(dot_vec(x, cy.rotation), 2) - pow(cy.radius, 2);
	r->dis = pow(r->b, 2) - a * c;
	if (r->dis < 0)
		return (-1);
	r->t = (-r->b - sqrt(r->dis)) / a;
	m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
	if ((r->t <= 0 || r->t >= INT_MAX) || (m < 0 || m > cy.height))
	{
		r->t = (-r->b + sqrt(r->dis)) / a;
		m = dot_vec(r->direction, cy.rotation) * r->t + dot_vec(x, cy.rotation);
		if ((r->t <= 0 || r->t >= INT_MAX) || (m < 0 || m > cy.height))
			return (-1);
	}
	return (r->t);
}

double	plane_intersect_mouv(t_plane p, t_ray *r)
{
	t_vector	x;
	double		a;
	double		b;

	x = mul_vec(minus_vec(r->origin_point, p.origin), -1);
	a = dot_vec(x, p.axis);
	b = dot_vec(r->direction, p.axis);
	if (a == 0 || b == 0)
		return (-1);
	r->t = a / b;
	if (r->t <= 0 || r->t >= INT_MAX)
		return (-1);
	return (r->t);
}

double	sphere_intersect_mouv(t_sphere sphere, t_ray *ray)
{
	t_vector	oc;
	double		b;
	double		c;
	double		dis;
	double		t;

	oc = minus_vec(ray->origin_point, sphere.origin);
	b = dot_vec(ray->direction, oc);
	c = pow(length_vec(oc), 2) - pow(sphere.radius, 2);
	dis = pow(b, 2) - c;
	if (dis >= 0)
	{
		t = (-b - sqrtf(dis));
		if (t <= 0 || INFINITY <= t){
			t = (-b + sqrt(dis));
			if (t <= 0 || INFINITY <= t)
				return (-1);
		}
		return (t);
	}
	return (-1);
}