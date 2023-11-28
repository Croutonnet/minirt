#ifndef LIGHT_H

#define LIGHT_H

#include "vector.h"
#include "color.h"

typedef struct s_light
{
	t_vector origin;
	float intensity;
	t_color color;
} t_light;

typedef struct s_light_ambient
{
	float intensity;
	t_color color;
} t_light_ambient;

#endif