/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:21:38 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 13:12:57 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/light.h"

t_sphere	create_sphere(t_vector pPosition, double radius, t_color pColor)
{
	t_sphere	s;

	s.origin.x = pPosition.x;
	s.origin.y = pPosition.y;
	s.origin.z = pPosition.z;
	s.radius = radius;
	s.base_color = pColor;
	return (s);
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

t_vector	get_ray_point(t_ray r, double t)
{
	t_vector	intersec;

	intersec.x = r.origin_point.x + (r.direction.x * t);
	intersec.y = r.origin_point.y + (r.direction.y * t);
	intersec.z = r.origin_point.z + (r.direction.z * t);
	return (intersec);
}
