/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 09:34:49 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/20 15:32:23 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include <stdio.h>

static float	tistance(t_vector v1, t_vector v2)
{
	float	t;

	t = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
	return (t);
}

static bool	sphere_touchage(t_ray *r, t_sphere s, float t_max)
{
	r->oc = minus_vec(r->origin_point, s.origin);
	r->b = dot_vec(r->direction, r->oc);
	r->c = pow(length_vec(r->oc), 2) - pow(s.radius, 2);
	r->dis = pow(r->b, 2) - r->c;
	if (r->dis >= 0)
	{
		r->t2 = (-r->b - sqrt(r->dis));
		if (r->t2 <= 0 || t_max <= r->t2)
		{
			r->t2 = (-r->b + sqrt(r->dis));
			if (r->t2 <= 0 || t_max <= r->t2)
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	ray_collision(t_vector touch, t_data *data, t_shape *shape)
{
	t_ray	r;
	bool	ret;

	ret = false;
	r = create_ray(touch, normalize(minus_vec(data->light.origin, touch)));
	if (shape->type == SPHERE)
		ret = sphere_touchage(&r, shape->geom.sphere, tistance(touch, data->light.origin));
	return (ret);
}
