#include "../include/parsing.h"

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

int	check_coma_point(char *line)
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
	if (count_coma(line) == false)
		return (false);
	return (true);
}
