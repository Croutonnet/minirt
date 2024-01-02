#include "../include/ray.h"
#include <stdio.h>
#include "../include/light.h"

t_plane create_plane(t_vector pPosition, t_vector p_axis, t_color p_Color)
{
    t_plane p;
    p.origin.x = pPosition.x;
    p.origin.y = pPosition.y;
    p.origin.z = pPosition.z;
    p.axis = p_axis;
    p.base_color = p_Color;
    return (p);
}

// If plane intersect ray
//return a color and put r.hit = true
t_vector plane_intersect_ray(t_plane p, t_ray *r, t_light light, t_light_ambient light_amb)
{
	t_color color;
	color.x = 0;
	color.y = 0;
	color.z = 0;

	float num;
	float denom;
	float t;

	num = dot_vec(minus_vec(p.origin, r->origin_point), p.axis);
	denom = dot_vec(r->direction, p.axis);

	if (denom < 0.001)
	{
		r->hit = false;
		return color;
	}

	t = num/denom;
	r->hit = true;
    return p.base_color;
}