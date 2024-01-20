/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:00:58 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/19 16:09:07 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"
#include "../../include/mouvement.h"

static int	search_object(t_ray *ray, t_data *data, float touch, int id)
{
	t_shape	*shape;
	float	temp_touch;
	int		id_of_touch;

	temp_touch = -1;
	id_of_touch = -1;
	while (id < data->shapes.count)
	{
		shape = &data->shapes.shapes[id];
		if (shape->type == SPHERE)
			temp_touch = sphere_intersect_mouv(shape->geom.sphere, ray);
		if ((temp_touch < touch && temp_touch != -1)
			|| (temp_touch != -1 && touch == -2))
		{
			touch = temp_touch;
			id_of_touch = id;
		}
		id++;
	}
	return (id_of_touch);
}

static void	init_data(t_data *data)
{
	t_mouv	mouv;
	int		x;
	int		y;

	mlx_get_mouse_pos(data->mlx, &x, &y);
	mouv.delta = add_vec(mul_vec(data->final_viewport.pixel_delta_v, x),
			mul_vec(data->final_viewport.pixel_delta_u, y));
	mouv.point = add_vec(data->final_viewport.pixel00_loc, mouv.delta);
	mouv.dir = normalize(minus_vec(mouv.point,
				data->final_viewport.camera_center));
	mouv.ray = create_ray(data->final_viewport.camera_center, mouv.dir);
	data->id_touch = search_object(&mouv.ray, data, -2, 0);
}

void	touch_object(mouse_key_t button, action_t action,
	modifier_key_t mods, void *param)
{
	t_data	*data;

	(void)mods;
	data = param;
	// SÉLECTIONNER UN OBJET ET APRES LE VIDE FAIS DE LA MARDE A ARRANGER
	if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_LEFT)
	{
		init_data(data);
		if (data->id_touch > -1 && data->obj_selected == true)
		{
			return_and_message(1, SMTHELSE, -1, NULL);
			return ;
		}
		else if (data->id_touch > -1 && data->cam_selected == false
			&& data->light_selected == false)
			return_and_message(1, OBJSELECT, true, &data->obj_selected);
	}
	else if (action == MLX_PRESS && button == MLX_MOUSE_BUTTON_RIGHT)
	{
		data->id_touch = -1;
		return_and_message(1, OBJDESELECT, false, &data->obj_selected);
	}
}
