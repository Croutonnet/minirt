#ifndef RAY_H
# define RAY_H
# include "stdbool.h"
# include "vector.h"
# include "image.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "color.h"
# include "light.h"

typedef struct s_ray
{
	bool hit;
	t_vector plane_point;
	t_vector origin_point;
	t_vector direction;
}t_ray;

// types de geometries possibles
typedef enum enum_shape_type
{
	SPHERE,
	CONE,
	CYLINDER
} e_shape_type;

typedef struct s_sphere 
{
	t_vector origin;
	float radius;
	t_color base_color;
} t_sphere;

typedef struct s_cylinder
{
	t_vector origin;
	t_vector rotation;
	t_vector base_color;
	float radius;
	float height;
} t_cylinder;

// type Shape Generique
// pouvant etre nimporte quel type de forme 3D
typedef union u_geometry
{
	t_sphere sphere;
	t_cylinder cylinder;
} u_geom;

// represente une forme 3D quelquonque
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

typedef struct s_data
{
	t_viewport		viewport;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_shapes_arr	shapes;
	t_light			light;
	t_light_ambient	alight;
}				t_data;

// shapes creation functions
t_sphere create_sphere(t_vector coord, float radius, t_color pColor);
t_cylinder create_cylinder(t_vector p, t_vector r, float d, float h, t_vector c);

// collision functions
t_vector sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data);
t_vector cylinder_intersect_ray(t_cylinder c, t_ray *r, t_light light);

// cam_mouvement.c
void	change_camera(t_data *data, keys_t key);
int		cam_mouvement_key(mlx_key_data_t keydata, t_data *data);

void create_rays(t_data *data);
t_vector get_ray_point(t_ray r, float t);
t_ray create_ray(t_vector origin, t_vector dir);

#endif