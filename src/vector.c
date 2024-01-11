/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:58 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/10 13:24:59 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"
#include <stdlib.h>
#include <stdio.h>

t_vector	create_vector(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

float	length_sqr(t_vector vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

float	length_vec(t_vector vec)
{
	return (sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

float	dot_vec(t_vector vec1, t_vector vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_vector	mul_2vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
	return (res);
}

t_vector	normalize(t_vector vec)
{
	float vec_length;

	vec_length = length_vec(vec);
	return (div_vec(vec, vec_length));
}

t_vector	div_2vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
	return (res);
}
