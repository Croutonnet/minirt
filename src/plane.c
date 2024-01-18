/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:36 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/18 11:53:22 by rapelcha         ###   ########.fr       */
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

static t_color	calculate_light(t_data *data, t_plane p)
{
	t_vector	lightdir;
	float		intensity;
	t_color		color;

	lightdir = normalize(minus_vec(data->light.origin, p.origin));
	intensity = dot_vec(p.axis, lightdir) / 2;
	if (intensity < 0)
		intensity = 0;
	color.x = (data->alight.intensity * data->alight.color.x)
		+ (intensity * p.base_color.x);
	color.y = (data->alight.intensity * data->alight.color.y)
		+ (intensity * p.base_color.y);
	color.z = (data->alight.intensity * data->alight.color.z)
		+ (intensity * p.base_color.z);

	return (color);
}

// If plane intersect ray
//return a color and put r.hit = true
t_vector	plane_intersect_ray(t_plane p, t_ray *r, t_data *data)
{
	t_color	color;
	float	num;
	float	denom;
	float	t;

	color.x = 0;
	color.y = 0;
	color.z = 0;
	num = dot_vec(minus_vec(r->origin_point, p.origin), p.axis);
	denom = dot_vec(r->direction, p.axis);

	if (denom < 0.001)
		return (color);
	t = num / denom;
	color = calculate_light(data, p);
	r->hit = true;
	return (color);
}
