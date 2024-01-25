/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_mouvement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:00:58 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 14:32:22 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"
#include "../../include/mouvement.h"

int	return_and_message(int ret, int message, int set, bool *getset)
{
	if (set != -1)
		*getset = (bool)set;
	if (message == CAMSELECT)
		ft_printf_fd(1, "Caméra sélectionner!\n");
	else if (message == CAMDESLECT)
		ft_printf_fd(1, "Caméra désélectionner!\n");
	else if (message == LIGHTSELECT)
		ft_printf_fd(1, "Lumière sélectionner!\n");
	else if (message == LIGHTDESELECT)
		ft_printf_fd(1, "Lumière désélectionner!\n");
	else if (message == SMTHELSE)
		ft_printf_fd(1, "Autre chose est déja sélectionner!\n");
	else if (message == OBJSELECT)
		ft_printf_fd(1, "Objet sélectionner!\n");
	else if (message == OBJDESELECT)
		ft_printf_fd(1, "Objet désélectionner!\n");
	else if (message == NOSELECT)
		ft_printf_fd(1, "Il n'y a rien de sélectionner\n");
	return (ret);
}

int	special_key(t_data *data, keys_t key)
{
	if (key == MLX_KEY_C)
	{
		if (data->light_selected == true || data->obj_selected == true)
			return (return_and_message(false, SMTHELSE, -1, NULL));
		if (data->cam_selected == true)
			return (return_and_message(true, CAMDESLECT, false,
					&data->cam_selected));
		else
			return (return_and_message(true, CAMSELECT, true,
					&data->cam_selected));
	}
	else if (key == MLX_KEY_L)
	{
		if (data->cam_selected == true || data->obj_selected == true)
			return (return_and_message(false, SMTHELSE, -1, NULL));
		if (data->light_selected == true)
			return (return_and_message(true, LIGHTDESELECT, false,
					&data->light_selected));
		else
			return (return_and_message(true, LIGHTSELECT, true,
					&data->light_selected));
	}
	return (false);
}

void	rotate_camera(t_data *data, keys_t key)
{
	if (key == MLX_KEY_UP)
		data->final_viewport.cam_pitch += 5;
	else if (key == MLX_KEY_DOWN)
		data->final_viewport.cam_pitch -= 5;
	else if (key == MLX_KEY_LEFT)
		data->final_viewport.cam_yaw += 5;
	else if (key == MLX_KEY_RIGHT)
		data->final_viewport.cam_yaw -= 5;
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
	ft_printf_fd(1, "Coordonnée de la lumière\n");
	print_vec(data->light.origin);
}

void	change_camera(t_data *data, keys_t key)
{
	if (key == MLX_KEY_W || key == MLX_KEY_S || key == MLX_KEY_D || \
		key == MLX_KEY_A || key == MLX_KEY_E || key == MLX_KEY_Q)
	{
		if (key == MLX_KEY_W)
			data->final_viewport.camera_center = \
			add_vec(data->final_viewport.camera_center, data->avant);
		else if (key == MLX_KEY_S)
			data->final_viewport.camera_center = \
		add_vec(data->final_viewport.camera_center, mul_vec(data->avant, -1));
		else if (key == MLX_KEY_D)
			data->final_viewport.camera_center = \
			add_vec(data->final_viewport.camera_center, data->droite);
		else if (key == MLX_KEY_A)
			data->final_viewport.camera_center = \
		add_vec(data->final_viewport.camera_center, mul_vec(data->droite, -1));
		else if (key == MLX_KEY_E)
			data->final_viewport.camera_center = \
			add_vec(data->final_viewport.camera_center, data->bas);
		else if (key == MLX_KEY_Q)
			data->final_viewport.camera_center = \
			add_vec(data->final_viewport.camera_center, mul_vec(data->bas, -1));
		ft_printf_fd (1, "Camera Center: ");
		print_vec(data->final_viewport.camera_center);
	}
}
