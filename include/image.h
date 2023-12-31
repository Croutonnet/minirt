#ifndef IMAGE_H
# define IMAGE_H

#include "vector.h"

#define IMAGE_WIDTH 1920.00
#define IMAGE_HEIGHT 1080.00

typedef struct s_viewport
{
	double		width;
	double		height;
	double		ratio;
	t_vector	camera_center;
	t_vector	v;
	t_vector	u;
	t_vector	pixel_delta_u;
	t_vector	pixel_delta_v;
	t_vector	upper_left;
	t_vector	pixel00_loc;
}			t_viewport;


#endif