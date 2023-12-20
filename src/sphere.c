#include "../include/ray.h"
#include <stdio.h>
#include "../include/light.h"
#include <limits.h>

// static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

t_sphere create_sphere(float x, float y, float z, float radius, t_color pColor)
{
    t_sphere s;
    s.origin.x = x;
    s.origin.y = y;
    s.origin.z = z;
    s.radius = radius;
    s.base_color = pColor;
    return (s);
}

// If sphere intersect ray
// return a color and put r.hit = true
t_vector sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data)
{
    t_color     color = (t_color)create_vector(0,0,0);
    t_vector	oc = minus_vec(r->origin_point, s.origin); //Direction vers le centre de la sphere
	float		b = dot_vec(r->direction, oc);
	float		c = pow(length_vec(oc), 2) - pow(s.radius, 2); //
	float		dis = pow(b, 2) - c; //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois
	float		sqrtd = sqrt(dis);
	r->hit = false;
	double t = -b - sqrtd; // c'est la distance entre le camera et le point toucher par le ray
	if (t <= 0 || t >= INT_MAX){
		t = -b + sqrtd; // c'est la distance entre le camera et le point toucher par le ray
		if (t <= 0 || t >= INT_MAX){
			r->hit = false;
			return (color);
		}
	}
	else if (dis < 0){
		r->hit = false;
		return (color);
	}
	t_vector touch = get_ray_point(*r, t); //Le point qu'on a toucher dans la sphere
	t_vector normale_dir = normalize(minus_vec(touch, s.origin)); //La direction entre le centre de la sphere et le point touché
	if (dot_vec(r->direction, normale_dir) < 0){
		normale_dir = mul_vec(normale_dir, -1);
	}
	touch = get_ray_point(create_ray(*r, touch, normale_dir), 0.00000000001);
	t_vector lumi_dir = minus_vec(touch, data->light.origin);
	lumi_dir = normalize(lumi_dir);
	float	m = dot_vec(normale_dir, lumi_dir);
	if (m >= 0)
    {
		color.x = s.base_color.x * data->light.color.x * m;
		color.z = s.base_color.z * data->light.color.z * m;
		color.y = s.base_color.y * data->light.color.y * m;
    }
	else if (m < 0)
    {
        color.x = data->alight.color.x * data->alight.intensity * 255;
        color.y = data->alight.color.y * data->alight.intensity * 255;
        color.z = data->alight.color.z * data->alight.intensity * 255;
    }
	r->hit = true;
    return (color);
}