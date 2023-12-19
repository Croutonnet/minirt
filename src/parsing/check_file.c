/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:13:47 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 16:18:05 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static int	multiple_point(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '.')
				nb++;
			i++;
		}
		if (nb > 1)
			return (true);
	}
	return (false);
}

int	check_diametre(char *line)
{
	int	i;
	int	nb;

	i = 0;
	if (check_coma_point(line, 0) == false)
		return (print_error(BADDIA, BADDIA, false));
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false && line[i] != '.')
			return (print_error(BADDIA, BADDIA, false));
		i++;
	}
	nb = ft_atof(line);
	if (nb < 0.0)
		return (print_error(BADDIA, BADDIA, false));
	return (CORRECT);
}

int	check_file(char *file)
{
	if (multiple_point(file) == true)
		return (print_error(TOOEXT, 1, false));
	file = ft_strrchr(file, '.');
	if (!file)
		return (print_error(NOEXT, 1, false));
	else if (ft_strncmp(file, ".rt", 3) != 0)
		return (print_error(WRONGEXT, 1, false));
	return (CORRECT);
}

int	is_there_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 9)
			return (print_error(BADTABS, BADTABS, false));
		i++;
	}
	return (CORRECT);
}

int	read_line(char *line, t_count *count)
{
	if (!ft_strncmp(line, "A ", 2))
		return (p_ambient_light(line, count));
	else if (!ft_strncmp(line, "C ", 2))
		return (p_camera(line, count));
	else if (!ft_strncmp(line, "L ", 2))
		return (p_light(line, count));
	else if (!ft_strncmp(line, "pl ", 2))
		return (p_plane(line, count));
	else if (!ft_strncmp(line, "sp ", 3))
		return (p_sphere(line, count));
	else if (!ft_strncmp(line, "cy ", 3))
		return (p_cylindre(line, count));
	else if (line[0] == '\n')
		return (CORRECT);
	else
		return (print_error(BADTYPE, BADTYPE, false));
}
