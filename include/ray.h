#ifndef RAY_H
# define RAY_H
# include "stdbool.h"
# include "vector.h"
# include "image.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_ray
{
	int32_t color;
	float dot_normal;
	t_vector normale_dir;
	t_vector ray_dir;
	t_vector origin_point;
}t_ray;

typedef struct s_hitdata
{
	float	t;
	bool	hit;
}				t_hitdata;

typedef enum enum_shape_type
{
	SPHERE,
	CONE
} e_shape_type;

typedef struct s_sphere 
{
	t_vector origin;
	float radius;
} t_sphere;

// TODO implement cone
typedef struct s_cone 
{
	t_vector origin;
} t_cone;

// type Shape Generique
// pouvant contenir nimporte quel type
// de forme 3D
typedef union u_geometry
{
	t_sphere sphere;
	t_cone cone;
} u_geom;
typedef struct s_shape
{
    e_shape_type type;
    u_geom geom;
}t_shape;


// tableau de shapes 3D
typedef struct s_shapes_arr
{
	t_shape shapes[100];
	int count;
} t_shapes_arr;


t_sphere create_sphere(float x, float y, float z, float radius);
t_cone create_cone(float x, float y, float z);

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
t_hitdata sphere_intersect_ray(t_sphere s, t_ray *r);
void create_rays(t_viewport *view, t_shapes_arr *arr,mlx_image_t *image);
t_vector get_ray_point(t_ray r, float t);
t_ray create_ray(t_vector origin, t_vector ray_dir);

#endif