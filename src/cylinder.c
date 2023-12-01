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

static double	deg_to_rad(double deg)
{
	return (deg * (PI / 180.0));
}


void	rotation_matrix_z(double matrix[3][3], double angle)
{
	angle = deg_to_rad(angle);
	matrix[0][0] = cos(angle);
	matrix[0][1] = -sin(angle);
	matrix[0][2] = 0;
	matrix[1][0] = sin(angle);
	matrix[1][1] = cos(angle);
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[2][2] = 1;
}

void	rotation_matrix_x(double matrix[3][3], double angle)
{
	angle = deg_to_rad(angle);
	matrix[0][0] = 1;
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][1] = cos(angle);
	matrix[1][2] = -sin(angle);
	matrix[2][0] = 0;
	matrix[2][1] = sin(angle);
	matrix[2][2] = cos(angle);
}

void	rotation_matrix_y(double matrix[3][3], double angle)
{
	angle = deg_to_rad(angle);
	matrix[0][0] = cos(angle);
	matrix[0][1] = 0;
	matrix[0][2] = sin(angle);
	matrix[1][0] = 0;
	matrix[1][1] = 1;
	matrix[1][2] = 0;
	matrix[2][0] = -sin(angle);
	matrix[2][1] = 0;
	matrix[2][2] = cos(angle);
}

void multiply(double matrix[3][3], t_vector *v)
{
	int		i;
	double	pointresult[3];

	i = 0;
	while (i < 3)
	{
		pointresult[i] = (matrix[i][0] * v->x)
			+(matrix[i][1] * v->y) + (matrix[i][2] * v->z);
		i++;
	}
    v->x = pointresult[0];
    v->y = pointresult[1];
    v->z = pointresult[2];
}



t_vector cylinder_intersect_ray(t_cylinder cy, t_ray *r, t_light light)
{
    t_color color;
    color.x = 0;
    color.y = 0;
    color.z = 0;
	
	double matrix[3][3];
	rotation_matrix_z(matrix, 45);
	t_ray rayonmodif;

	rayonmodif.direction = minus_vec(r->direction, r->origin_point);
	
	multiply(matrix, &rayonmodif.direction);


	t_vector av =  create_vector((r->origin_point.x - 0),0,(r->origin_point.z - cy.origin.z));
    t_vector bv = create_vector(rayonmodif.direction.x - r->origin_point.x,0,rayonmodif.direction.z - r->origin_point.z);
    

	
    float a = pow(bv.x,2) + pow(bv.z,2);
	float b = (2.0 * av.x * bv.x) +  (2.0 * av.z * bv.z);
    float       c = pow(av.x, 2) + pow(av.z,2) - pow(cy.radius,2);
    float       dis = pow(b, 2) - (4 * a * c); //Discriminant < 0 si rien toucher, 0 toucher une fois, 1 toucher deux fois

    if (dis >= 0)
    {
        // // calcule la valeur de t
        //float t1 = (-b + sqrt(dis))/2.0f;
        float t2 = (-b - sqrtf(dis))/(2.0f * a);
        // calcule points de collision
        t_vector h2 = get_ray_point(rayonmodif, t2);

        if (h2.y > cy.height/2 || h2.y < -cy.height/2)
        {
            r->hit = false;
            return color;
        }


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
		color = (t_vector){1,1,0};
        r->hit = true;
        return color;
    }
    r->hit = false;
    return color;
}