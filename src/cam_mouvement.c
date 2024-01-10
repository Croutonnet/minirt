/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_mouvement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:00:58 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/10 16:49:08 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int special_key(t_data *data, keys_t key)
{
	if (key == MLX_KEY_C){
		if (data->light_selected == true || data->obj_selected == true){
			ft_printf_fd(0, "Deja quelque chose de selectionner!\n");
			return (false);
		}
		if(data->cam_selected == true)
			data->cam_selected = false;
		else
			data->cam_selected = true;
		if (data->cam_selected == true) //A refaire
			ft_printf_fd(0, "Camera selectionner\n"); //A refaire
		if (data->cam_selected == false) //A refaire
			ft_printf_fd(0, "Camera déselectionner\n"); //A refaire
		return (true);
	}
	else if(key == MLX_KEY_R){
		if (data->light_selected == true || data->cam_selected == true){
			ft_printf_fd(0, "Deja quelque chose de selectionner!\n");
			return (false);
		}
		if(data->obj_selected == true)
			data->obj_selected = false;
		else
			data->obj_selected = true;
		if (data->obj_selected == true) //A refaire
			ft_printf_fd(0, "Diamètre d'un object selectionner\n"); //A refaire
		if (data->obj_selected == false) //A refaire
			ft_printf_fd(0, "Diamètre déselectionner\n"); //A refaire
		return (true);
	}
	else if(key == MLX_KEY_L){
		if (data->cam_selected == true || data->obj_selected == true){
			ft_printf_fd(0, "Deja quelque chose de selectionner!\n");
			return (false);
		}
		if(data->light_selected == true)
			data->light_selected = false;
		else
			data->light_selected = true;
		if (data->light_selected == true) //A refaire
			ft_printf_fd(0, "Lumière selectionner\n"); //A refaire
		if (data->light_selected == false) //A refaire
			ft_printf_fd(0, "Lumière déselectionner\n"); //A refaire
		return (true);
	}
	return (false);
}

void	rotate_camera(t_data *data, keys_t key)
{
	if (key == MLX_KEY_UP)
		data->final_viewport.cam_pitch--;
	else if (key == MLX_KEY_DOWN)
		data->final_viewport.cam_pitch++;
	else if (key == MLX_KEY_LEFT)
		data->final_viewport.cam_yaw--;
	else if (key == MLX_KEY_RIGHT)
		data->final_viewport.cam_yaw++;
	return ;
}

void	move_light(t_data *data, keys_t key)
{
	if (key == MLX_KEY_W)
		data->light.origin.z += 1;
	else if (key == MLX_KEY_S)
		data->light.origin.z -= 1;
	else if (key == MLX_KEY_D)
		data->light.origin.x += 1;
	else if (key == MLX_KEY_A)
		data->light.origin.x -= 1;
	else if (key == MLX_KEY_Q)
		data->light.origin.y += 1;
	else if (key == MLX_KEY_E)
		data->light.origin.y -= 1;
	return ;
}

void	change_camera(t_data *data, keys_t key)
{
	if (key == MLX_KEY_W)
		data->final_viewport.camera_center = add_vec(data->final_viewport.camera_center, normalize(mul_vec(minus_vec(data->final_viewport.viewport_center, data->final_viewport.camera_center), -1)));
	else if(key == MLX_KEY_S)
		data->final_viewport.camera_center = add_vec(data->final_viewport.camera_center, normalize(minus_vec(data->final_viewport.viewport_center, data->final_viewport.camera_center)));
	else if(key == MLX_KEY_D)
		data->final_viewport.camera_center = add_vec(data->final_viewport.camera_center, normalize(data->final_viewport.pixel_delta_v));
	else if(key == MLX_KEY_A)
		data->final_viewport.camera_center = add_vec(data->final_viewport.camera_center, mul_vec(normalize(data->final_viewport.pixel_delta_v), -1));
	else if (key == MLX_KEY_E)
		data->final_viewport.camera_center = add_vec(data->final_viewport.camera_center, normalize(data->final_viewport.pixel_delta_u));
	else if (key == MLX_KEY_Q)
		data->final_viewport.camera_center = add_vec(data->final_viewport.camera_center, mul_vec(normalize(data->final_viewport.pixel_delta_u), -1));
}
