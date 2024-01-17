/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:39:29 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/17 14:48:17 by bbouchar         ###   ########.fr       */
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

// types de geometries possibles
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
	float		radius;
	t_color		base_color;
}	t_sphere;

typedef struct s_cylinder
{
	t_vector	origin;
	t_vector	rotation;
	t_vector	base_color;
	float		radius;
	float		height;
}	t_cylinder;

// type Shape Generique
// pouvant etre nimporte quel type de forme 3D
typedef union t_ugeometry
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
}	t_ugeom;

// represente une forme 3D quelquonque
typedef struct s_shape
{
	t_eshape_type	type;
	t_ugeom			geom;
}	t_shape;

//t_color color; // couleur de retour
//t_shape* obj; // retour de lobjet
//int t; // distance t du point dintersection
typedef struct s_ray
{
	bool		hit;
	t_vector	origin_point;
	t_vector	direction;
	t_color		color;
	t_shape		*obj;
	int			t;
}	t_ray;

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

// collision functions
t_vector	sphere_intersect_ray(t_sphere s, t_ray *r, t_data *data);
t_vector	cylinder_intersect_ray(t_cylinder c, t_ray *r);
t_vector	plane_intersect_ray(t_plane p, t_ray *r, t_data *data);

// cam_mouvement.c
void		change_camera(t_data *data, keys_t key);
void		rotate_camera(t_data *data, keys_t key);
void		move_light(t_data *data, keys_t key);
int			special_key(t_data *data, keys_t key);

// obj_mouvement.c
void		move_object(t_data *data, keys_t key);
void		touch_object(mouse_key_t b, action_t a, modifier_key_t m, void *p);

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