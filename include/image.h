/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouchar <bbouchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:50:59 by bbouchar          #+#    #+#             */
/*   Updated: 2024/01/17 14:51:38 by bbouchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "vector.h"

# define IMAGE_WIDTH 1920.00
# define IMAGE_HEIGHT 1080.00

typedef struct s_viewport
{
	float		width;
	float		height;
	float		ratio;
	float		focal_lenght;
	t_vector	viewport_center;
	t_vector	camera_center;
	t_vector	v;
	t_vector	u;
	t_vector	pixel_delta_u;
	t_vector	pixel_delta_v;
	t_vector	upper_left;
	t_vector	pixel00_loc;
	t_vector	cam_rot;
	float		cam_pitch;
	float		cam_yaw;
}			t_viewport;
#endif