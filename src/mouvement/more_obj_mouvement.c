/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_obj_mouvement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:41:28 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 12:38:54 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"
#include "../../include/mouvement.h"

void	rotate_cyl(t_shape *cyl, keys_t key)
{
	if (key == MLX_KEY_UP)
		cyl->geom.cylinder.rotation = \
		rotation_y(cyl->geom.cylinder.rotation, 5);
	if (key == MLX_KEY_DOWN)
		cyl->geom.cylinder.rotation = \
		rotation_y(cyl->geom.cylinder.rotation, -5);
	if (key == MLX_KEY_RIGHT)
		cyl->geom.cylinder.rotation = \
		rotation_x(cyl->geom.cylinder.rotation, 5);
	if (key == MLX_KEY_LEFT)
		cyl->geom.cylinder.rotation = \
		rotation_x(cyl->geom.cylinder.rotation, -5);
	if (key == MLX_KEY_KP_ADD)
		cyl->geom.cylinder.rotation = \
		rotation_z(cyl->geom.cylinder.rotation, 5);
	if (key == MLX_KEY_KP_SUBTRACT)
		cyl->geom.cylinder.rotation = \
		rotation_z(cyl->geom.cylinder.rotation, -5);
	ft_printf_fd(1, "Orientation du cylindre sélectionner: ");
	print_vec(cyl->geom.cylinder.rotation);
}

void	rotate_plane(t_shape *p, keys_t key)
{
	if (key == MLX_KEY_UP)
		p->geom.plane.axis = rotation_y(p->geom.plane.axis, 5);
	else if (key == MLX_KEY_DOWN)
		p->geom.plane.axis = rotation_y(p->geom.plane.axis, -5);
	else if (key == MLX_KEY_RIGHT)
		p->geom.plane.axis = rotation_x(p->geom.plane.axis, 5);
	else if (key == MLX_KEY_LEFT)
		p->geom.plane.axis = rotation_x(p->geom.plane.axis, -5);
	else if (key == MLX_KEY_KP_ADD)
		p->geom.plane.axis = rotation_z(p->geom.plane.axis, 5);
	else if (key == MLX_KEY_KP_SUBTRACT)
		p->geom.plane.axis = rotation_z(p->geom.plane.axis, -5);
	ft_printf_fd(1, "Orientation du plane sélectionner: ");
	print_vec(p->geom.plane.axis);
}

void	move_plane(t_shape *p, keys_t key)
{
	if (key == MLX_KEY_W)
		p->geom.plane.origin.z++;
	else if (key == MLX_KEY_S)
		p->geom.plane.origin.z--;
	else if (key == MLX_KEY_A)
		p->geom.plane.origin.x++;
	else if (key == MLX_KEY_D)
		p->geom.plane.origin.x--;
	else if (key == MLX_KEY_Q)
		p->geom.plane.origin.y++;
	else if (key == MLX_KEY_E)
		p->geom.plane.origin.y--;
	else
		rotate_plane(p, key);
	ft_printf_fd(1, "Coordonner du plane sélectionner: ");
	print_vec(p->geom.plane.origin);
}
