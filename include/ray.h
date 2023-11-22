#ifndef RAY_H
# define RAY_H
# include "stdbool.h"
# include "vector.h"
# include "image.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_ray
{
    bool hit;
    float t;
    t_vector plane_point;
    t_vector origin_point;
}t_ray;

typedef struct s_sphere 
{
    t_vector origin; // not used for now
    float radius;
}              t_sphere;

t_sphere create_sphere(float x, float y, float z, float radius);
void sphere_intersect_ray(t_sphere s, t_ray *r);

void create_rays(t_viewport *view, t_sphere sphere, mlx_image_t *image);
t_vector get_ray_point(t_ray r);
t_ray create_ray(t_ray r, t_vector origin, t_vector plane_point);

#endif