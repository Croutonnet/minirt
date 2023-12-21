/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:20:29 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/21 13:52:24 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	pcreate_ambient_light(char **line, t_data *data)
{
	data->alight.intensity = ft_atof(line[1]);
	data->alight.color = (t_color)normalize(create_vector_str(line[2]));
	// printf("IN FUNCTION alight intensity: %f\n", data->alight.intensity);
	// printf("IN FUNCTION alight color: ");
	// print_vec(data->alight.color);
	ft_xxfree((void **)line);
}

static void	pcreate_camera(char **line, t_viewport *viewport)
{
	viewport->camera_center = create_vector_str(line[1]);
	viewport->focal_lenght = tan((ft_atof(line[3]) / 2)
			* (viewport->width / 2));
	// printf("Focal_lenght: %f\n", viewport->focal_lenght);
	ft_xxfree((void **)line);
}

static void	pcreate_light(char **line, t_data *data)
{
	data->light.origin = create_vector_str(line[1]);
	data->light.intensity = ft_atof(line[2]);
	data->light.color = create_vector_str(line[3]);
	// printf("IN FUNCTION light origin: ");
	// print_vec(data->light.origin);
	// printf("IN FUNCTION light intensity: %f\n", data->light.intensity);
	// printf("IN FUNCTION light color: ");
	// print_vec(data->light.color);
	ft_xxfree((void **)line);
}

static void	create_line(char *line, t_data *data, t_viewport *viewport)
{
	if (!ft_strncmp(line, "A ", 2))
		pcreate_ambient_light(ft_split(line, ' '), data);
	if (!ft_strncmp(line, "C ", 2))
		pcreate_camera(ft_split(line, ' '), viewport);
	else if (!ft_strncmp(line, "L ", 2))
		pcreate_light(ft_split(line, ' '), data);
	else if (!ft_strncmp(line, "sp ", 3))
		pcreate_sphere(ft_split(line, ' '), data);
	else if (!ft_strncmp(line, "cy ", 3))
		pcreate_cylindre(ft_split(line, ' '), data);
	// else if (!ft_strncmp(line, "pl ", 2))
	// 	pcreate_plane(shapes);
}

void	read_map(char *file_path, t_data *data, t_viewport *viewport)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = "coucou";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			create_line(line, data, viewport);
	}
}
