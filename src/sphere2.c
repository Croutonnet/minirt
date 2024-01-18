/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:21:38 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/18 18:22:19 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"
#include "../include/light.h"

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