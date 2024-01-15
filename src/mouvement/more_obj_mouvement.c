/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_obj_mouvement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:41:28 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/11 14:47:11 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"
#include "../../include/mouvement.h"

// void	rotate_plane()
// {
	
// }

void	rotate_cyl(t_cylinder *cyl, keys_t key)
{
	if (key == MLX_KEY_UP)
		rotation_y(cyl->rotation, 1);
	if (key == MLX_KEY_DOWN)
		rotation_y(cyl->rotation, -1);
	if (key == MLX_KEY_RIGHT)
		rotation_x(cyl->rotation, 1);
	if (key == MLX_KEY_LEFT)
		rotation_x(cyl->rotation, -1);
	if (key == MLX_KEY_KP_ADD)
		rotation_z(cyl->rotation, 1);
	if (key == MLX_KEY_KP_SUBTRACT)
		rotation_z(cyl->rotation, -1);
}

// void	move_plane()
// {
	
// }