#include "../include/ray.h"

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

t_vector cylinder_intersect_ray(t_cylinder cy, t_ray *r, t_light light)
{
    t_color color;
    color.x = 0;
    color.y = 0;
    color.z = 0;
	t_vector av =  create_vector(r->origin_point.x - cy.origin.x, r->origin_point.z - cy.origin.z,0);
    t_vector bv = create_vector(r->direction.x - r->origin_point.x, r->direction.z - r->origin_point.z, 0);

	float b = (2.0 * av.x * bv.x) +  (2.0 * av.z * bv.z);
	//float       b = 2.0 * dot_vec2d(minus_vec(r->direction,r->origin_point), oc);
    float       c = pow(av.x, 2) + pow(av.z,2) - pow(cy.radius,2);
    float       dis = pow(b, 2) - (4 * c); //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois

    if (dis >= 0)
    {
        // // calcule la valeur de t
        // //float t1 = (-b + sqrt(dis))/2.0f;
        // float t2 = (-b - sqrtf(dis))/(2.0f);
        // // calcule points de collision
        // t_vector h2 = get_ray_point(*r, t2);
        // // calcul normal
        // t_vector normal = normalize(minus_vec(h2, cy.origin)); // x,y,z entre -1 et 1
        // // // calcul lumiere
        // t_vector lightDir = normalize(minus_vec(light.origin, cy.origin));
        // float intensity =  dot_vec(normal, lightDir) / 2;
        // if (intensity < 0)
        //     intensity = 0;
        // color.x = intensity * cy.base_color.x * light.color.x;
        // color.y = intensity * cy.base_color.y * light.color.y;
        // color.z = intensity * cy.base_color.z * light.color.z;
		color = (t_vector){1,0,0};
        r->hit = true;
        return color;
    }
    r->hit = false;
    return color;
}