#include "../include/parsing.h"

int	check_rgb(char *line, int j, int i, int k)
{
	float	nb;

	if (check_coma_point(line) == false)
		return(print_error(BADRGB, BADRGB));
	while (k < 3)
	{
		nb = ft_atof(&line[i]);
		while (line[i] && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == false && line[i] != ','
				&& line[i] != '\n' && line[i] != '.')
				return(print_error(BADRGB, BADRGB));
			i++;
		}
		if (nb < 0.0 || nb > 255.0)
			return(print_error(BADRGB, BADRGB));
		if (line[i] == ',')
			i++;
		k++;
		if (k == 3 && line[i] != '\0' && line[i] != '\n')
			return(print_error(BADRGB, BADRGB));
	}
	return (CORRECT);
}

int	check_ratio(char *line)
{
	int		i;
	double	nb;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false && line[i] != '.')
		{
			return(print_error(BADRATIO, BADRATIO));
		}
		i++;
	}
	nb = ft_atof(line);
	if (nb < 0.0 || nb > 1.0)
		return(print_error(BADRATIO, BADRATIO));
	return (CORRECT);
}

int	check_vector(char *line, int i, int j, int k)
{
	double	nb;

	while (k < 3)
	{
		nb = ft_atof(&line[i]);
		while (line[i] && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == false && line[i] != ',' && line[i] != '-' && line[i] != '.')
				return(print_error(BADVECTOR, BADVECTOR));
			i++;
		}
		if (line[i] == ',')
			i++;
		k++;
		if (k == 3 && line[i] != '\0' && line[i] != '\n')
			return(print_error(BADVECTOR, BADVECTOR));
	}
	return (CORRECT);
}

int check_fov(char *line)
{
	int	i;
	int	nb;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == false && line[i] != '\n')
			return(print_error(BADFOV, BADFOV));
		i++;
	}
	nb = ft_atoi(line);
	if (nb < 0 || nb > 180)
		return(print_error(BADFOV, BADFOV));
	return (CORRECT);
}

int	check_vector_orientation(char *line, int i, int j, int k)
{
	double	nb;

	while (k < 3)
	{
		nb = ft_atof(&line[i]);
		while (line[i] && line[i] != ',')
		{
			if (ft_isdigit(line[i]) == false && line[i] != ',' && line[i] != '-' && line[i] != '.')
				return(print_error(BADVECTOR, BADVECTOR));
			i++;
		}
		if (nb < 0.0 || nb > 1.0)
			return (print_error(BADORI, BADORI));
		if (line[i] == ',')
			i++;
		k++;
		if (k == 3 && line[i] != '\0' && line[i] != '\n')
			return(print_error(BADVECTOR, BADVECTOR));
	}
	return (CORRECT);
}