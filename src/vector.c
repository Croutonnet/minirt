/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:24:58 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 13:21:57 by rapelcha         ###   ########.fr       */
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

double	length_sqr(t_vector vec)
{
	return ((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
}

double	length_vec(t_vector vec)
{
	return (sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

double	dot_vec(t_vector vec1, t_vector vec2)
{
	return ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
}

t_vector	mul_2vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x * vec2.x, vec1.y * vec2.y, vec1.z * vec2.z);
	return (res);
}
