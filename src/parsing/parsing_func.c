#include "../../include/parsing.h"

static int count_coma(char *line)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			nb++;
		i++;
	}
	if (nb == 2)
		return (true);
	else
		return (false);
}

static int count_point(char *line)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (line[i])
	{
		nb = 0;
		while (line[i] && line[i] != ',')
		{
			if (nb > 1)
				return (false);
			if (line[i] == '.')
				nb++;
			i++;
		}
		if (line[i])
			i++;
	}
	return (true);
}

static int	check_minus(char *line, int i)
{
	if (i == 0)
		return (false);
	if (line[i - 1])
	{
		if (line[i - 1] == ' ' || line[i - 1] == ',')
			return (false);
	}
	return (true);
}

int	check_coma_point(char *line, int id)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '.' && (i == 0 || line[i + 1] == '\n'))
			return (false);
		else if (line[i] == '.' && (line[i + 1] == ',' || line[i + 1] == '.'))
			return (false);
		else if (line[i] == '.' && (line[i + 1] == ',' || line[i + 1] == '.'))
			return (false);
		else if (line[i] == ',' && (i == 0 || line[i + 1] == '\n'))
			return (false);
		else if (line[i] == ',' && (line[i + 1] == ',' || line[i + 1] == '.'))
			return (false);
		else if (line[i] == ',' && (line[i + 1] == ',' || line[i + 1] == '.'))
			return (false);
		i++;
	}
	if (id == 1 && count_coma(line) == false)
		return (false);
	if (count_point(line) == false)
		return (false);
	return (true);
}

int	check_syntaxe(char **input, int i, int j)
{
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] != '-' && input[i][j] != '.'
				&& input[i][j] != ',' && ft_isdigit(input[i][j]) == false
				&& input[i][j] != '\n')
			{
				printf("Char Problematique : |%c|	dans a str: %s\n", input[i][j], input[i]);
				return (print_error(BADSYN, -1, false));
			}
			if (input[i][j] == '-' && check_minus(input[i], j) == true)
			{
				printf("Char Problematique : |%c|	dans a str: %s\n", input[i][j], input[i]);
				return (print_error(BADSYN, -1, false));
			}
			j++;
		}
		i++;
	}
	return (CORRECT);
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
