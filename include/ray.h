/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:29 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/25 13:18:03 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "stdbool.h"
# include "vector.h"
# include "image.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "color.h"
# include "light.h"
# include "Libft/libft.h"

typedef enum enum_shape_type
{
	SPHERE,
	CONE,
	CYLINDER,
	PLANE
}	t_eshape_type;

typedef struct s_plane
{
	t_vector	origin;
	t_vector	axis;
	t_color		base_color;
}	t_plane;

typedef struct s_sphere
{
	t_vector	origin;
	double		radius;
	t_color		base_color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	rotation;
	t_vector	base_color;
	double		radius;
	double		height;
}	t_cylinder;

typedef union t_ugeometry
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}	t_ugeom;

typedef struct s_shape
{
	t_eshape_type	type;
	t_ugeom			geom;
}	t_shape;

typedef struct s_ray
{
	bool		hit;
	t_vector	origin_point;
	t_vector	direction;
	t_color		color;
	double		b;
	double		dis;
	double		t;
	t_vector	touch_point;
}	t_ray;

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
	t_vector		dir;
	t_vector		delta;
	t_vector		point;
	t_ray			close_ray;
}				t_data;

// shapes creation functions
t_sphere	create_sphere(t_vector p_position, double radius, t_color pColor);
t_plane		create_plane(t_vector p_position, t_vector p_axis, t_color p_Color);

//collision.c
bool		toucher_light(t_vector touche_point, t_data *data);
bool		ray_collision(t_vector touch, t_data *data, t_shape *shape);

// plane.c
void		plane_intersect_ray(t_plane p, t_ray *r, t_data *data);

// cylinder.c
void		cylinder_intersect_ray(t_cylinder c, t_ray *r, t_data *data);

// sphere.c
void		sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data);

// cam_mouvement.c
void		change_camera(t_data *data, keys_t key);
void		rotate_camera(t_data *data, keys_t key);
void		move_light(t_data *data, keys_t key);
int			special_key(t_data *data, keys_t key);

// obj_mouvement.c
void		move_object(t_data *data, keys_t key);
void		touch_object(mouse_key_t button, action_t action, \
modifier_key_t mods, void *param);

// rotation.c
t_vector	rotation_x(t_vector vec, double deg);
t_vector	rotation_y(t_vector vec, double deg);
t_vector	rotation_z(t_vector vec, double deg);

// final_viewport.c
void		read_rotation(t_data *data);
void		final_viewport(t_data *data);

void		create_rays(t_data *data);
t_vector	get_ray_point(t_ray r, double t);
t_ray		create_ray(t_vector origin, t_vector dir);

#endif