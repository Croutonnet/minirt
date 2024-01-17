/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:30:01 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/17 14:30:10 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vector.h"

t_vector	normalize(t_vector vec)
{
	float	vec_length;

	vec_length = length_vec(vec);
	return (div_vec(vec, vec_length));
}

t_vector	div_2vec(t_vector vec1, t_vector vec2)
{
	t_vector	res;

	res = create_vector(vec1.x / vec2.x, vec1.y / vec2.y, vec1.z / vec2.z);
	return (res);
}