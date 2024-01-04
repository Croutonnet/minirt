#include "../include/ray.h"

#define PI 3.141592654

t_cylinder create_cylinder(t_vector p, t_vector r, float d, float h, t_vector c)
{
	t_cylinder cylinder;
	cylinder.origin = p;
	cylinder.base_color = c;
	cylinder.height = h;
	cylinder.radius = d;
	cylinder.rotation = r;

	return (cylinder);
}

t_vector cylinder_intersect_ray(t_cylinder cy, t_ray *r)
{
	t_vector v[2];
	float dist[2];
	t_vector v_cy2ray;
	t_color color;
	color.x = 0;
	color.y = 0;
	color.z = 0;

	v[0] = minus_vec(r->direction, mul_vec(cy.rotation, dot_vec(r->direction, cy.rotation)));
	v[1] = minus_vec(minus_vec(r->origin_point, cy.origin),
	mul_vec(cy.rotation, dot_vec(minus_vec(r->origin_point, cy.origin), cy.rotation)));
	
	float a = length_sqr(v[0]);
	float b = 2.0 * dot_vec(v[0], v[1]);
	float c = length_sqr(v[1]) - pow(cy.radius, 2);
	float dis = pow(b, 2) - (4 * a * c);


	float t1 = (-b - sqrt(dis)) / (2 * a);
	float t2 = (-b + sqrt(dis)) / (2 * a);
	v_cy2ray = minus_vec(cy.origin, r->origin_point);
	dist[0] = dot_vec(cy.rotation, minus_vec(mul_vec(r->direction, t1), v_cy2ray));
	dist[1] = dot_vec(cy.rotation, minus_vec(mul_vec(r->direction, t2), v_cy2ray));


    if (dist[1] < cy.height || dist[0] > cy.height)
    {
		r->hit = true;
		color.x = 1;
		color.y = 1;
		color.z = 1;
		return color;
	}
	r->hit = false;
	return color;
}
