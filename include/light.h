/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:49:34 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 08:46:39 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H

# define LIGHT_H

# include "vector.h"
# include "color.h"

typedef struct s_light_ambient
{
	double	intensity;
	t_color	color;
}	t_light_ambient;

typedef struct s_light
{
	t_vector origin;
	double intensity;
} t_light;

#endif