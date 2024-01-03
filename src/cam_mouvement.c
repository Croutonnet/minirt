/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_mouvement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:00:58 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/03 12:45:40 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

int cam_mouvement_key(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W)
			return (true);
		else if (keydata.key == MLX_KEY_D)
			return (true);
		else if (keydata.key == MLX_KEY_S)
			return (true);
		else if (keydata.key == MLX_KEY_A)
			return (true);
	}
	return (false);
}

void	change_camera(t_data *data, keys_t key)
{
	// if (key == MLX_KEY_W)
		// data->viewport.camera_center;
	// else if(key == MLX_KEY_S)
		// data->viewport.camera_center.z = ;
	if(key == MLX_KEY_D)
		data->viewport.camera_center = add_vec(data->viewport.camera_center, normalize(data->viewport.pixel_delta_v));
	else if(key == MLX_KEY_A)
		data->viewport.camera_center = add_vec(data->viewport.camera_center, mul_vec(normalize(data->viewport.pixel_delta_v), -1));
}