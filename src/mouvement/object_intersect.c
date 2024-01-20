/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:02:24 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/20 15:34:40 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/mouvement.h"
#include "../../include/ray.h"

float	sphere_intersect_mouv(t_sphere sphere, t_ray *ray)
{
	t_vector	oc;
	float		b;
	float		c;
	float		dis;
	float		t;

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