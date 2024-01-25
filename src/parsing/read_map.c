/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:20:29 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 16:30:03 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	pcreate_ambient_light(char **line, t_data *data)
{
	data->alight.intensity = ft_atof(line[1]);
	data->alight.color = (t_color)normalize(create_vector_str(line[2]));
	ft_xxfree((void **)line);
}

static void	pcreate_camera(char **line, t_data *data)
{
	data->final_viewport.camera_center = create_vector_str(line[1]);
	data->viewport.cam_rot = create_vector_str(line[2]);
	data->viewport.focal_lenght = (data->viewport.width / 2)
		/ tan(((ft_atof(line[3]) * M_PI / 180) / 2));
	ft_xxfree((void **)line);
}

static void	pcreate_light(char **line, t_data *data)
{
	data->light.origin = create_vector_str(line[1]);
	data->light.intensity = ft_atof(line[2]);
	ft_xxfree((void **)line);
}

static void	create_line(char *line, t_data *data)
{
	if (!ft_strncmp(line, "A ", 2))
		pcreate_ambient_light(ft_split(line, ' '), data);
	if (!ft_strncmp(line, "C ", 2))
		pcreate_camera(ft_split(line, ' '), data);
	else if (!ft_strncmp(line, "L ", 2))
		pcreate_light(ft_split(line, ' '), data);
	else if (!ft_strncmp(line, "sp ", 3))
		pcreate_sphere(ft_split(line, ' '), data);
	else if (!ft_strncmp(line, "cy ", 3))
		pcreate_cylindre(ft_split(line, ' '), data);
	else if (!ft_strncmp(line, "pl ", 2))
		pcreate_plane(ft_split(line, ' '), data);
}

void	read_map(char *file_path, t_data *data)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	line = "coucou";
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			create_line(line, data);
		free(line);
	}
}
