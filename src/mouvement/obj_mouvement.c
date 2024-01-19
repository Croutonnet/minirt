/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_mouvement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:01:06 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/19 16:01:34 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ray.h"
#include "../../include/mouvement.h"

static void	move_sphere(t_shape *sphere, keys_t key)
{
	if (key == MLX_KEY_W || key == MLX_KEY_S || key == MLX_KEY_D ||
		key == MLX_KEY_A || key == MLX_KEY_E || key == MLX_KEY_Q)
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
		ft_printf_fd(1, "Coord Sphere Sélectionner: ");
		print_vec(sphere->geom.sphere.origin);
	}
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
	ft_printf_fd(1, "Coord Cylindre Sélectionner: ");
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
