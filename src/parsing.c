#include "../include/parsing.h"

int	parsing(char *file)
{
	int		fd;
	char	*line;
	int		error;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (print_error(OPENWRONG, OPENWRONG));
	line = ft_strdup("coucou");
	while (line)
	{
		ft_xfree(line);
		line = get_next_line(fd);
		if (line)
			error = read_line(line);
		if (error != CORRECT)
			return (print_error(error, -1));
	}
	return (print_error(CORRECT, CORRECT));
}

int	is_there_tabs(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 9)
			return (print_error(BADTABS, BADTABS));
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
		return (print_error(CORRECT, CORRECT));
	else
		return (print_error(BADTYPE, BADTYPE));
}

int	p_ambient_light(char *line)
{
	int		err;
	char	**temp;

	err = is_there_tabs(line);
	if (err != CORRECT)
		return(print_error(BADALIGHT, BADALIGHT));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || temp[3] != NULL)
		return(print_error(BADALIGHT, BADALIGHT));
	err = check_ratio(temp[1]);
	if (err != 0)
		return(print_error(BADALIGHT, BADALIGHT));
	err = check_rgb(temp[2], 0, 0, 0);
	if (err != 0)
		return(print_error(BADALIGHT, BADALIGHT));
	ft_xxfree(temp);
	printf ("Pour le Ambient Light, ");
	return (print_error(CORRECT, CORRECT));
}

int	print_error(int err, int ret)
{
	if (err == CORRECT)
		printf ("TOUT EST CORRECT\n");
	else if (err == OPENWRONG)
		printf ("Error #%d : File non existant\n", err);
	else if (err == BADTYPE)
		printf ("Error #%d : Type d'objet non existant\n", err);
	else if (err == BADALIGHT)
		printf ("Error #%d : Problème avec la lumière ambiante\n", err);
	else if (err == BADCAMERA)
		printf ("Error #%d : Problème avec la caméra\n", err);
	else if (err == BADLIGHT)
		printf ("Error #%d : Problème avec la lumière\n", err);
	else if (err == BADPLANE)
		printf ("Error #%d : Problème avec le plane\n", err);
	else if (err == BADSPHERE)
		printf ("Error #%d : Problème avec la sphère\n", err);
	else if (err == BADCYL)
		printf ("Error #%d : Problème avec le cylindre\n", err);
	else if (err == BADRGB)
		printf ("Error #%d : Problème avec le RGB\n", err);
	else if (err == BADRATIO)
		printf ("Error #%d : Problème avec le Ratio\n", err);
	else if (err == BADFOV)
		printf ("Error #%d : Probleme avec le FOV\n", err);
	else if (err == BADTABS)
		printf ("Error #%d : Probleme avec les Tabs\n", err);
	else if (err == BADVECTOR)
		printf ("Error #%d : Probleme avec le Vector\n", err);
	else if (err == BADORI)
		printf ("Error #%d : Probleme avec le Vector d'orientation\n", err);
	return (ret);
}


// A 0.2 255,255,255\n
// C -50,0,20 0,0,0 70\n
// L -40,0,30 0.7 255,255,255\n
// pl 0,0,0 0,1.0,0 255,0,225\n
// sp 0,0,20 20 255,0,0\n
// cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255\n