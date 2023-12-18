#include "../../include/parsing.h"

static int	check_count(t_count *count)
{
	int	flag;

	flag = 0;
	if (count->cam != 1)
	{
		printf("Trop de caméra ou aucune caméra trouver\n");
		flag++;
	}
	if (count->la != 1)
	{
		printf("Trop de ambient light ou aucune ambient light trouver\n");
		flag++;
	}
	if (count->light != 1)
	{
		printf("Trop de light ou aucune light trouver\n");
		flag++;
	}
	if (flag > 0)
		return (BADCOUNT);
	return (CORRECT);
}

int	parsing(char *file)
{
	int		fd;
	char	*line;
	int		error;
	t_count	count;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (print_error(OPENWRONG, OPENWRONG, false));
	line = ft_strdup("coucou");
	ft_bzero(&count, sizeof(count));
	while (line)
	{
		ft_xfree(line);
		line = get_next_line(fd);
		if (line)
			error = read_line(line, &count);
		if (error != CORRECT)
			return (-1);
	}
	if (check_count(&count) != CORRECT)
		return(print_error(BADCOUNT, -1, false));
	return (print_error(CORRECT, CORRECT, false));
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

int	p_ambient_light(char *line, t_count *count)
{
	int		err;
	char	**temp;

	err = is_there_tabs(line);
	if (err != CORRECT)
		return(print_error(BADALIGHT, BADALIGHT, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || temp[3] != NULL)
		return(print_error(BADALIGHT, BADALIGHT, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADALIGHT, err, false));
	err = check_ratio(temp[1]);
	if (err != 0)
		return(print_error(BADALIGHT, BADALIGHT, false));
	err = check_rgb(temp[2], 0, 0);
	if (err != 0)
		return(print_error(BADALIGHT, BADALIGHT, false));
	ft_xxfree((void **)temp);
	printf ("Pour le Ambient Light, ");
	count->la++;
	return (print_error(CORRECT, CORRECT, false));
}

int	print_error(int err, int ret, int args)
{
	if (err == CORRECT)
		printf ("TOUT EST CORRECT\n");
	if (args == true)
		printf ("Error #17 : Nombre d'arguments incorrect\n");
	if (err == OPENWRONG)
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
		printf ("Error #%d : Problème avec le ratio\n", err);
	else if (err == BADFOV)
		printf ("Error #%d : Probleme avec le fOV\n", err);
	else if (err == BADTABS)
		printf ("Error #%d : Probleme avec les tabs\n", err);
	else if (err == BADVECTOR)
		printf ("Error #%d : Probleme avec le vector\n", err);
	else if (err == BADORI)
		printf ("Error #%d : Probleme avec le vector d'orientation\n", err);
	else if (err == BADSYN)
		printf ("Error #%d : Probleme avec la syntaxe\n", err);
	else if (err == BADDIA)
		printf ("Error #%d : Probleme avec le Diametre\n", err);
	else if (err == BADCOUNT)
		printf ("Error #%d : Probleme avec le Count\n", err);
	return (ret);
}
