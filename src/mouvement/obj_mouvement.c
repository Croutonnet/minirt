/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mouvement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:01:06 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/18 12:39:35 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"
#include "../../include/mouvement.h"

static int search_object(t_ray *ray, t_data *data)
{
	int		id;
	t_shape	*shape;
	float	touch;
	float	temp_touch;
	int		id_of_touch;

	id = 0;
	touch = -2;
	temp_touch = -1;
	id_of_touch = -1;
	while (id < data->shapes.count)
	{
		shape = &data->shapes.shapes[id];
		if (shape->type == SPHERE)
			temp_touch = sphere_intersect_mouv(shape->geom.sphere, ray);
		if (temp_touch != -1)
			return (id);
		// if (temp_touch < touch || (temp_touch != -1 && touch == -2))
		// {
		// 	touch = temp_touch;
		// 	id_of_touch = id;
		// }
		id++;
	}
	return (id_of_touch);
}

void	touch_object(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
	t_data	*data;
	int		x;
	int		y;
	t_mouv	mouv;

	(void)mods;
	data = param;
	if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_LEFT)
	{
		mlx_get_mouse_pos(data->mlx, &x, &y);
		mouv.delta = add_vec(mul_vec(data->final_viewport.pixel_delta_v, x), mul_vec(data->final_viewport.pixel_delta_u, y));
		mouv.point = add_vec(data->final_viewport.pixel00_loc, mouv.delta);
		mouv.dir = normalize(minus_vec(mouv.point, data->final_viewport.camera_center));
		mouv.ray = create_ray(data->final_viewport.camera_center, mouv.dir);
		data->id_touch = search_object(&mouv.ray, data);
		if (data->id_touch > -1 && data->cam_selected == false && data->light_selected == false){
			ft_printf_fd(0, "Object sélectionner: %d!\n", data->id_touch);
			data->obj_selected = true;
		}
	}
	else if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_RIGHT)
	{
		data->id_touch = -1;
		data->obj_selected = false;
		ft_printf_fd(0, "Object déselectionner!\n");
	}
}

static void	move_sphere(t_shape *sphere, keys_t key)
{
	if (key == MLX_KEY_W)
		sphere->geom.sphere.origin.z++;
	else if (key == MLX_KEY_S)
		sphere->geom.sphere.origin.z--;
	else if (key == MLX_KEY_A)
		sphere->geom.sphere.origin.x++;
	else if (key == MLX_KEY_D)
		sphere->geom.sphere.origin.x--;
	else if (key == MLX_KEY_Q)
		sphere->geom.sphere.origin.y++;
	else if (key == MLX_KEY_E)
		sphere->geom.sphere.origin.y--;
	else if (key == MLX_KEY_B)
		sphere->geom.sphere.radius += 0.5;
	else if (key == MLX_KEY_V && sphere->geom.sphere.radius > 0.5)
		sphere->geom.sphere.radius -= 0.5;
	ft_printf_fd(0, "Coord Sphere Sélectionner: ");
	print_vec(sphere->geom.sphere.origin);
}

static void	move_cyl(t_shape *cyl, keys_t key)
{
	if (key == MLX_KEY_W)
		cyl->geom.cylinder.origin.z++;
	else if (key == MLX_KEY_S)
		cyl->geom.cylinder.origin.z--;
	else if (key == MLX_KEY_A)
		cyl->geom.cylinder.origin.x++;
	else if (key == MLX_KEY_D)
		cyl->geom.cylinder.origin.x--;
	else if (key == MLX_KEY_Q)
		cyl->geom.cylinder.origin.y++;
	else if (key == MLX_KEY_E)
		cyl->geom.cylinder.origin.y--;
	else if (key == MLX_KEY_B)
		cyl->geom.cylinder.radius += 0.5;
	else if (key == MLX_KEY_V && cyl->geom.cylinder.radius > 0.5)
		cyl->geom.cylinder.radius -= 0.5;
	else if (key == MLX_KEY_M)
		cyl->geom.cylinder.height += 1;
	else if (key == MLX_KEY_N && cyl->geom.cylinder.radius > 1)
		cyl->geom.cylinder.height -= 1;
	else
		rotate_cyl(cyl, key);
	ft_printf_fd(0, "Coord Cylindre Sélectionner: ");
	print_vec(cyl->geom.cylinder.origin);
}

void	move_object(t_data *data, keys_t key)
{
	if (data->id_touch == -1)
		return ;
	if (data->shapes.shapes[data->id_touch].type == SPHERE)
		move_sphere(&data->shapes.shapes[data->id_touch], key);
	else if (data->shapes.shapes[data->id_touch].type == CYLINDER)
		move_cyl(&data->shapes.shapes[data->id_touch], key);
}
