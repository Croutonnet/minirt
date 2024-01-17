/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:45 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/17 13:34:44 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include <stdio.h>
#include "../include/light.h"
#include <limits.h>

// static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

t_sphere	create_sphere(t_vector pPosition, float radius, t_color pColor)
{
	t_sphere	s;

	s.origin.x = pPosition.x;
	s.origin.y = pPosition.y;
	s.origin.z = pPosition.z;
	s.radius = radius;
	s.base_color = pColor;
	return (s);
}

//float t1 = (-b + sqrt(dis))/2.0f;
// calcule la valeur de t
// calcule points de collision
// x,y,z entre -1 et 1
// si un object intersecte lightDir, alors le pixel est une ombre...
static t_color	light(t_sphere s, t_ray *r, float t2, t_data *data)
{
	t_vector	normal;
	t_vector	lightdir;
	t_color		color;
	float		intensity;

	normal = normalize(minus_vec(get_ray_point(*r, t2), s.origin));
	lightdir = normalize(minus_vec(data->light.origin, s.origin));
	intensity = dot_vec(normal, lightdir) / 2;
	if (intensity < 0)
		intensity = 0;
	color.x = (data->alight.intensity * data->alight.color.x)
		+ (intensity * s.base_color.x * data->light.color.x);
	color.y = (data->alight.intensity * data->alight.color.y)
		+ (intensity * s.base_color.y * data->light.color.y);
	color.z = (data->alight.intensity * data->alight.color.z)
		+ (intensity * s.base_color.z * data->light.color.z);
	r->t = t2;
	r->hit = true;
	return (color);
}

// If sphere intersect ray
// return a color and put r.hit = true, retunr intersection point.
// oc = Direction vers le centre de la sphere
// dis = Discriminant < 0 si rien toucher, 
// 0 toucher une fois, 1 toucher deux fois
t_color	sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data)
{
	t_vector	oc;
	float		b;
	float		c;
	float		dis;
	float		t2;

	oc = minus_vec(r->origin_point, s.origin);
	b = 2.0 * dot_vec(minus_vec(r->direction, r->origin_point), oc);
	c = pow(length_vec(oc), 2) - pow(s.radius, 2);
	dis = pow(b, 2) - (4 * c);
	if (dis >= 0)
	{
		t2 = (-b - sqrtf(dis)) / (2.0f);
		if (t2 <= 0 || INFINITY <= t2)
		{
			t2 = (-b + sqrt(dis));
			if (t2 <= 0 || INFINITY <= t2)
				return ((t_color){0, 0, 0});
		}
		return (light(s, r, t2, data));
	}
	return ((t_color){0, 0, 0});
}
