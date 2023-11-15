#ifndef IMAGE_H
# define IMAGE_H

#include "vector.h"
typedef struct s_viewport
{
	double		width;
	double		height;
	double		ratio;
	t_vector	*v;
	t_vector	*u;
}			t_viewport;


#endif