/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:49:01 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 14:31:53 by rapelcha         ###   ########.fr       */
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
	OBJDESELECT,
	NOSELECT
};

// object_intersect.c
double	sphere_intersect_mouv(t_sphere sphere, t_ray *ray);
double	cylinder_intersect_mouv(t_cylinder cy, t_ray *r);
double	plane_intersect_mouv(t_plane p, t_ray *r);

// more_obj_mouvement.c
void	rotate_cyl(t_shape *cyl, keys_t key);
void	move_plane(t_shape *p, keys_t key);

// cam_mouvement.c
int		return_and_message(int ret, int message, int set, bool *getset);

#endif