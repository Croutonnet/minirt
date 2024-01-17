/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:49:34 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/17 14:50:44 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H

# define LIGHT_H

# include "vector.h"
# include "color.h"

typedef struct s_light_ambient
{
	float	intensity;
	t_color	color;
}	t_light_ambient;

typedef struct s_light
{
	t_vector	origin;
	float		intensity;
	t_color		color;
}	t_light;

#endif