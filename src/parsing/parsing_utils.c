/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:13:54 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 13:26:30 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int	check_rgb(char *line, int i, int k)
{
	double	nb;

	if (check_coma_point(line, 1) == false)
		return (print_error(BADRGB, BADRGB, false));
	while (k < 3)
	{
		nb = ft_atof(&line[i]);
		while (line[i] && line[i] != ',')
			i++;
		if (nb < 0.0 || nb > 255.0)
			return (print_error(BADRGB, BADRGB, false));
		if (line[i] == ',')
			i++;
		k++;
		if (k == 3 && line[i] != '\0' && line[i] != '\n')
			return (print_error(BADRGB, BADRGB, false));
	}
	return (CORRECT);
}

int	check_ratio(char *line)
{
	int		i;
	double	nb;

	i = 0;
	if (check_coma_point(line, 0) == false)
		return (print_error(BADRATIO, BADRATIO, false));
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false && line[i] != '.' && line[i] != '\n')
			return (print_error(BADRATIO, BADRATIO, false));
		i++;
	}
	nb = ft_atof(line);
	if (nb < 0.0 || nb > 1.0)
		return (print_error(BADRATIO, BADRATIO, false));
	return (CORRECT);
}

int	check_fov(char *line)
{
	int		i;
	double	nb;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false && line[i] != '\n' && line[i] != '.')
			return (print_error(BADFOV, BADFOV, false));
		i++;
	}
	nb = ft_atof(line);
	if (nb < 0 || nb > 180)
		return (print_error(BADFOV, BADFOV, false));
	return (CORRECT);
}

int	check_vector(char *line, int i, int k)
{
	if (check_coma_point(line, 1) == false)
		return (print_error(BADVECTOR, BADVECTOR, false));
	while (k < 3)
	{
		while (line[i] && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == false && line[i] != ','
				&& line[i] != '-' && line[i] != '.')
				return (print_error(BADVECTOR, BADVECTOR, false));
			i++;
		}
		if (line[i] == ',')
			i++;
		k++;
		if (k == 3 && line[i] != '\0' && line[i] != '\n')
			return (print_error(BADORI, BADORI, false));
		if (k != 3 && (line[i] == '\0' || line[i] == '\n'))
			return (print_error(BADORI, BADORI, false));
	}
	return (CORRECT);
}

int	check_vector_orientation(char *line, int i, int k)
{
	double	nb;

	if (check_coma_point(line, 0) == false)
		return (print_error(BADORI, BADORI, false));
	while (k < 3)
	{
		nb = ft_atof(&line[i]);
		while (line[i] && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == false && line[i] != ','
				&& line[i] != '-' && line[i] != '.')
				return (print_error(BADORI, BADORI, false));
			i++;
		}
		if (nb < -1.0 || nb > 1.0)
			return (print_error(BADORI, BADORI, false));
		if (line[i] == ',')
			i++;
		k++;
		if (k == 3 && line[i] != '\0' && line[i] != '\n')
			return (print_error(BADORI, BADORI, false));
		if (k != 3 && (line[i] == '\0' || line[i] == '\n'))
			return (print_error(BADORI, BADORI, false));
	}
	return (CORRECT);
}
