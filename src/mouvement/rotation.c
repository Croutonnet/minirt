/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:22:04 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 08:46:39 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"

t_vector	rotation_z(t_vector vec, double deg)
{
	t_vector	result;

	deg = deg * (M_PI / 180);
	result.x = vec.x * cos(deg) + vec.y * -sin(deg);
	result.y = vec.x * sin(deg) + vec.y * cos(deg);
	result.z = vec.z;
	return (result);
}

t_vector	rotation_x(t_vector vec, double deg)
{
	t_vector	result;

	deg = deg * (M_PI / 180);
	result.x = vec.x;
	result.y = vec.y * cos(deg) + vec.z * -sin(deg);
	result.z = vec.y * sin(deg) + vec.z * cos(deg);
	return (result);
}

t_vector	rotation_y(t_vector vec, double deg)
{
	t_vector	result;

	deg = deg * (M_PI / 180);
	result.x = vec.x * cos(deg) + vec.z * sin(deg);
	result.y = vec.y;
	result.z = vec.x * -sin(deg) + vec.z * cos(deg);
	return (result);
}