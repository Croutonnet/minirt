/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:37:13 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 13:16:00 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	add_shape(t_shapes_arr *arr, t_eshape_type type, t_ugeom geo)
{
	if (type == SPHERE)
		arr->shapes[arr->count].type = SPHERE;
	else if (type == CYLINDER)
		arr->shapes[arr->count].type = CYLINDER;
	else if (type == PLANE)
		arr->shapes[arr->count].type = PLANE;
	arr->shapes[arr->count].geom = geo;
	arr->count++;
}

t_vector	create_vector_str(char *str)
{
	double	nb1;
	double	nb2;
	double	nb3;
	int		i;

	i = 0;
	nb1 = ft_atof(str);
	while (str[i] != ',')
		i++;
	i++;
	nb2 = ft_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	nb3 = ft_atof(&str[i]);
	return (create_vector(nb1, nb2, nb3));
}

void	pcreate_plane(char **line, t_data *data)
{
	t_vector	coord;
	t_vector	axis;
	t_color		color;

	coord = create_vector_str(line[1]);
	axis = create_vector_str(line[2]);
	color = (t_color)normalize(create_vector_str(line[3]));
	add_shape(&data->shapes, PLANE, (t_ugeom)create_plane(coord, axis, color));
}

void	pcreate_sphere(char **line, t_data *data)
{
	t_vector	coord;
	double		dia;
	t_color		color;

	coord = create_vector_str(line[1]);
	dia = ft_atof(line[2]) / 2;
	color = (t_color)normalize(create_vector_str(line[3]));
	add_shape(&data->shapes, SPHERE, (t_ugeom)create_sphere(coord, dia, color));
}

void	pcreate_cylindre(char **line, t_data *data)
{
	t_cylinder	cyl;

	cyl.origin = create_vector_str(line[1]);
	cyl.rotation = normalize(create_vector_str(line[2]));
	cyl.radius = ft_atof(line[3]) / 2;
	cyl.height = ft_atof(line[4]);
	cyl.base_color = (t_color)normalize(create_vector_str(line[5]));
	add_shape(&data->shapes, CYLINDER, (t_ugeom)cyl);
}
