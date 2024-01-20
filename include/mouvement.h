/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:49:01 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/17 14:49:21 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUVEMENT_H
# define MOUVEMENT_H

# include "ray.h"
# include "vector.h"

typedef struct s_mouv
{
	t_vector	delta;
	t_vector	point;
	t_vector	dir;
	t_ray		ray;
}			t_mouv;

enum e_mess_mouv
{
	CAMSELECT,
	CAMDESLECT,
	LIGHTSELECT,
	LIGHTDESELECT,
	SMTHELSE,
	OBJSELECT,
	OBJDESELECT
};

float	sphere_intersect_mouv(t_sphere sphere, t_ray *ray);

// more_obj_mouvement.c
void	rotate_cyl(t_shape *cyl, keys_t key);

// cam_mouvement.c
int		return_and_message(int ret, int message, int set, bool *getset);

#endif