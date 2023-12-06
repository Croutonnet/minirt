#include "../include/parsing.h"

int	p_camera(char *line)
{
	int		err;
	char	**temp;

	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (BADCAMERA);
	err = check_vector(temp[1], 0 ,0 ,0);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err));
	err = check_vector_orientation(temp[2], 0 ,0 ,0);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err));
	err = check_fov(temp[3]);
	if (err != CORRECT)
		return (print_error(BADCAMERA, err));
	ft_xxfree(temp);
	printf ("Pour la Camera, ");
	return (print_error(CORRECT, CORRECT));
}

int	p_light(char *line)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (BADLIGHT);
	err = check_vector(temp[1], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err));
	err = check_ratio(temp[2]);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err));
	err = check_rgb(temp[3], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADLIGHT, err));
	ft_xxfree(temp);
	printf ("Pour la lumière, ");
	return (print_error(CORRECT, CORRECT));
}

int	p_plane(char *line)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADPLANE, err));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (BADPLANE);
	err = check_vector(temp[1], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err));
	err = check_vector_orientation(temp[2], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err));
	err = check_rgb(temp[3], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADPLANE, err));
	ft_xxfree(temp);
	printf ("Pour le plane, ");
	return (print_error(CORRECT, CORRECT));
}

int	p_sphere(char *line)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || temp[4] != NULL)
		return (BADSPHERE);
	err = check_vector(temp[1], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err));
	// err = check_vector_orientation(temp[2], 0, 0, 0);
	// if (err != CORRECT)
	// 	return (print_error(BADSPHERE, err));
	err = check_rgb(temp[3], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADSPHERE, err));
	ft_xxfree(temp);
	printf ("Pour la sphère, ");
	return (print_error(CORRECT, CORRECT));
}

int	p_cylindre(char *line)
{
	int		err;
	char	**temp;
	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADCYL, err));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || !temp[3] || !temp[4] || temp[5] != NULL)
		return (BADCYL);
	err = check_vector(temp[1], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err));
	err = check_vector_orientation(temp[2], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err));
	// err = check_vector_orientation(temp[3], 0, 0, 0);
	// if (err != CORRECT)
	// 	return (print_error(BADCYL, err));
	// err = check_vector_orientation(temp[4], 0, 0, 0);
	// if (err != CORRECT)
	// 	return (print_error(BADCYL, err));
	err = check_rgb(temp[5], 0, 0, 0);
	if (err != CORRECT)
		return (print_error(BADCYL, err));
	ft_xxfree(temp);
	printf ("Pour le cylindre, ");
	return (print_error(CORRECT, CORRECT));
}
