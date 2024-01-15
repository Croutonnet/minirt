#ifndef MOUVEMENT_H
# define MOUVEMENT_H

#include "ray.h"
#include "vector.h"

typedef struct s_mouv
{
	t_vector	delta;
	t_vector	point;
	t_vector	dir;
	t_ray		ray;
}			t_mouv;

float	sphere_intersect_mouv(t_sphere sphere, t_ray *ray);

// more_obj_mouvement.c
void	rotate_cyl(t_cylinder *cyl, keys_t key);

#endif