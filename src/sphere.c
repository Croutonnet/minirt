#include "../include/ray.h"
#include <stdio.h>
#include "../include/light.h"
#include <limits.h>

// static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

t_sphere create_sphere(t_vector pPosition, float radius, t_color pColor)
{
    t_sphere s;
    s.origin.x = pPosition.x;
    s.origin.y = pPosition.y;
    s.origin.z = pPosition.z;
    s.radius = radius;
    s.base_color = pColor;
    return (s);
}

// If sphere intersect ray
// return a color and put r.hit = true, retunr intersection point.
t_vector sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data)
{
	t_color color;
	color.x = 0;
	color.y = 0;
	color.z = 0;

	t_vector	oc = minus_vec(r->origin_point, s.origin); //Direction vers le centre de la sphere
	float		b = 2.0 * dot_vec(minus_vec(r->direction,r->origin_point), oc);
	float		c = pow(length_vec(oc), 2) - pow(s.radius, 2); //
	float		dis = pow(b, 2) - (4 * c); //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois

	if (dis >= 0)
	{
		// calcule la valeur de t
		//float t1 = (-b + sqrt(dis))/2.0f;
		float t2 = (-b - sqrtf(dis))/(2.0f);
		// calcule points de collision
		t_vector h2 = get_ray_point(*r, t2);
		// calcul normal
		t_vector normal = normalize(minus_vec(h2, s.origin)); // x,y,z entre -1 et 1
		// // calcul lumiere
		t_vector lightDir = normalize(minus_vec(data->light.origin, s.origin));
		// si un object intersecte lightDir, alors le pixel est une ombre...


		float intensity =  dot_vec(normal, lightDir) / 2;
		if (intensity < 0)
			intensity = 0;
        color.x = (data->alight.intensity * data->alight.color.x) + (intensity * s.base_color.x * data->light.color.x);
        color.y = (data->alight.intensity * data->alight.color.y) + (intensity * s.base_color.y * data->light.color.y);
        color.z = (data->alight.intensity * data->alight.color.z) + (intensity * s.base_color.z * data->light.color.z);
		r->t = t2;
		r->hit = true;
		r->intersect = h2;
		return color;
	}
	return color;
}
