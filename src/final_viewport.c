/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_viewport.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:50:25 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 14:52:35 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ray.h"

void	read_rotation(t_data *data)
{
	data->final_viewport.cam_pitch = data->viewport.cam_rot.y * 90;
	data->final_viewport.cam_yaw = atan2(-data->viewport.cam_rot.x,
			-data->viewport.cam_rot.z);
	data->final_viewport.cam_yaw = data->final_viewport.cam_yaw * 180.0 / M_PI;
}

static void	pitch(t_data *data)
{
	data->final_viewport.pixel_delta_u
		= rotation_x(data->viewport.pixel_delta_u,
			data->final_viewport.cam_pitch);
	data->final_viewport.pixel_delta_v
		= rotation_x(data->viewport.pixel_delta_v,
			data->final_viewport.cam_pitch);
	data->final_viewport.viewport_center
		= rotation_x(data->viewport.viewport_center,
			data->final_viewport.cam_pitch);
	data->final_viewport.pixel00_loc
		= rotation_x(data->viewport.pixel00_loc,
			data->final_viewport.cam_pitch);
}

static void	yaw(t_data *data)
{
	data->final_viewport.pixel_delta_u
		= rotation_y(data->final_viewport.pixel_delta_u,
			data->final_viewport.cam_yaw);
	data->final_viewport.pixel_delta_v
		= rotation_y(data->final_viewport.pixel_delta_v,
			data->final_viewport.cam_yaw);
	data->final_viewport.viewport_center
		= rotation_y(data->final_viewport.viewport_center,
			data->final_viewport.cam_yaw);
	data->final_viewport.pixel00_loc
		= rotation_y(data->final_viewport.pixel00_loc,
			data->final_viewport.cam_yaw);
}

void	final_viewport(t_data *data)
{
	pitch(data);
	yaw(data);
	data->final_viewport.pixel00_loc = \
	add_vec(data->final_viewport.camera_center, \
	data->final_viewport.pixel00_loc);
	data->final_viewport.viewport_center = \
	add_vec(data->final_viewport.camera_center, \
	data->final_viewport.viewport_center);
	data->avant = \
	normalize(mul_vec(minus_vec(data->final_viewport.viewport_center, \
	data->final_viewport.camera_center), -1));
	data->droite = normalize(data->final_viewport.pixel_delta_v);
	data->bas = normalize(data->final_viewport.pixel_delta_u);
}
