#ifndef RAY_H
# define RAY_H
# include "stdbool.h"
# include "vector.h"
# include "image.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "color.h"
# include "light.h"
# include "Libft/libft.h"

// types de geometries possibles
typedef enum enum_shape_type
{
	SPHERE,
	CONE,
	CYLINDER,
	PLANE
} e_shape_type;

typedef struct s_plane
{
	t_vector origin;
	t_vector axis;
	t_color base_color;
} t_plane;

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
	t_plane plane;
} u_geom;

// represente une forme 3D quelquonque
typedef struct s_shape
{
	e_shape_type type;
	u_geom geom;
}t_shape;

typedef struct s_ray
{
	bool		hit;
	t_vector	origin_point;
	t_vector	direction;
	t_color		color;
	t_vector	oc;
	float		b;
	float		c;
	float		dis;
	float		t2;
	t_vector	touch_point;
}t_ray;

// tableau de shapes 3D
typedef struct s_shapes_arr
{
	t_shape	shapes[100];
	int		count;
}	t_shapes_arr;

typedef struct s_data
{
	t_viewport		viewport;
	t_viewport		final_viewport;
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_shapes_arr	shapes;
	t_light			light;
	t_light_ambient	alight;
	bool			cam_selected;
	bool			light_selected;
	bool			obj_selected;
	t_vector		avant;
	t_vector		droite;
	t_vector		bas;
	int				id_touch;
}				t_data;

// shapes creation functions
t_sphere	create_sphere(t_vector p_position, float radius, t_color pColor);
t_cylinder	create_cylinder(t_vector p, t_vector r, float d, float h, t_vector c);
t_plane		create_plane(t_vector p_position, t_vector p_axis, t_color p_Color);

//collision.c
bool		ray_collision(t_vector touch, t_data *data, t_shape *shape);

// collision functions
void		sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data, int id);
t_vector	cylinder_intersect_ray(t_cylinder c, t_ray *r);
t_vector	plane_intersect_ray(t_plane p, t_ray *r, t_data *data);

// cam_mouvement.c
void		change_camera(t_data *data, keys_t key);
void		rotate_camera(t_data *data, keys_t key);
void		move_light(t_data *data, keys_t key);
int			special_key(t_data *data, keys_t key);

// obj_mouvement.c
void		move_object(t_data *data, keys_t key);
void		touch_object(mouse_key_t button, action_t action, modifier_key_t mods, void *param);

// rotation.c
t_vector	rotation_x(t_vector vec, float deg);
t_vector	rotation_y(t_vector vec, float deg);
t_vector	rotation_z(t_vector vec, float deg);

// final_viewport.c
void		read_rotation(t_data *data);
void		final_viewport(t_data *data);

void		create_rays(t_data *data);
t_vector	get_ray_point(t_ray r, float t);
t_ray		create_ray(t_vector origin, t_vector dir);

#endif