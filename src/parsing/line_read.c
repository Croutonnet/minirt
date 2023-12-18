#include "../../include/parsing.h"

int	p_camera(char *line, t_count *count)
{
	int		err;
	char	**temp;

	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (print_error(BADCAMERA, -1, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err, false));
	err = check_vector(temp[1], 0 ,0);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err, false));
	err = check_vector_orientation(temp[2], 0 ,0);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err, false));
	err = check_fov(temp[3]);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err, false));
	ft_xxfree((void **)temp);
	printf ("Pour la Camera, ");
	count->cam++;
	return (print_error(CORRECT, CORRECT, false));
}

int	p_light(char *line, t_count *count)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (print_error(BADLIGHT, -1, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err, false));
	err = check_vector(temp[1], 0, 0);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err, false));
	err = check_ratio(temp[2]);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err, false));
	err = check_rgb(temp[3], 0, 0);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err, false));
	ft_xxfree((void **)temp);
	printf ("Pour la lumière, ");
	count->light++;
	return (print_error(CORRECT, CORRECT, false));
}

int	p_plane(char *line, t_count *count)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADPLANE, err, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (print_error(BADPLANE, -1, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err, false));
	err = check_vector(temp[1], 0, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err, false));
	err = check_vector_orientation(temp[2], 0, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err, false));
	err = check_rgb(temp[3], 0, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err, false));
	ft_xxfree((void **)temp);
	printf ("Pour le plane, ");
	count->plane++;
	return (print_error(CORRECT, CORRECT, false));
}

int	p_sphere(char *line, t_count *count)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (print_error(BADSPHERE, -1, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err, false));
	err = check_vector(temp[1], 0, 0);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err, false));
	err = check_diametre(temp[2]);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err, false));
	err = check_rgb(temp[3], 0, 0);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err, false));
	ft_xxfree((void **)temp);
	printf ("Pour la sphère, ");
	count->sphere++;
	return (print_error(CORRECT, CORRECT, false));
}

int	p_cylindre(char *line, t_count *count)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || !temp[4])
		return (print_error(BADCYL, -1, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	err = check_vector(temp[1], 0, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	err = check_vector_orientation(temp[2], 0, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	err = check_diametre(temp[3]);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	err = check_diametre(temp[4]);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	err = check_rgb(temp[5], 0, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err, false));
	ft_xxfree((void **)temp);
	printf ("Pour le cylindre, ");
	count->cyl++;
	return (print_error(CORRECT, CORRECT, false));
}
