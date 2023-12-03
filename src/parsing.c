#include "../include/parsing.h"

int	parsing(char *file)
{
	int		fd;
	char	*line;
	int		error;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (OPENWRONG);
	line = ft_strdup("coucou");
	while (line)
	{
		ft_xfree(line);
		line = get_next_line(fd);
		if (line)
			error = read_line(line);
		if (error != CORRECT)
			return (error);
	}
}

int	is_there_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 9)
			return (-1);
		i++;
	}
	return (CORRECT);
}

int	read_line(char *line)
{
	if (ft_strncmp(line, "A ", 2) == 0)
		return (p_ambient_light(line));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (p_camera(line));
	else if (ft_strncmp(line, "L ", 2) == 0)
		return (p_light(line));
	else if (ft_strncmp(line, "pl ", 2) == 0)
		return (p_plane(line));
	else if (ft_strncmp(line, "sp ", 3) == 0)
		return (p_sphere(line));
	else if (ft_strncmp(line, "cy ", 3) == 0)
		return (p_cylindre(line));
	else if (line[0] == '\n')
		return (CORRECT);
	else
		return (BADTYPE);
}

int	check_rgb(char *line)
{
	int	i;
	int	nb;

	i = 0;
	nb = ft_atoi(line);
	while (line[i] && line[i] > 0 && line[i] < 9)
		i++;
	i++;
	nb = ft_atoi(line);
	while (line[i] && line[i] > 0 && line[i] < 9)
		i++;
	nb = ft_atoi(line);
}

int	p_ambient_light(char *line)
{
	int		err;
	char	**temp;
	int		i;
	double	ratio;
	int		rgb;

	err = is_there_tabs(line);
	i = 0;
	if (err != CORRECT)
		return(err);
	temp = ft_split(line, 32);

	ft_xxfree(temp);
	return (CORRECT);
}

void	print_error()
{

}


// A 0.2 255,255,255
// C -50,0,20 0,0,0 70
// L -40,0,30 0.7 255,255,255
// pl 0,0,0 0,1.0,0 255,0,225
// sp 0,0,20 20 255,0,0
// cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255