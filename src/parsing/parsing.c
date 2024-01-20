/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:02:12 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/19 13:44:59 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static int	check_count(t_count *count)
{
	int	flag;

	flag = 0;
	if (count->cam != 1)
	{
		ft_printf_fd(2, "Trop de caméra ou aucune caméra trouver\n");
		flag++;
	}
	if (count->la != 1)
	{
		ft_printf_fd(2, "Trop de ambient light ou aucune ambient\
		light trouver\n");
		flag++;
	}
	if (count->light != 1)
	{
		ft_printf_fd(2, "Trop de light ou aucune light trouver\n");
		flag++;
	}
	if (flag > 0)
		return (BADCOUNT);
	return (CORRECT);
}

int	parsing(char *file, t_count *count)
{
	int		fd;
	char	*line;
	int		error;

	if (check_file(file) != CORRECT)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error(OPENWRONG, -1, false));
	line = ft_strdup("coucou");
	while (line)
	{
		ft_xfree(line);
		line = get_next_line(fd);
		if (line)
			error = read_line(line, count);
		if (error != CORRECT)
			return (-1);
	}
	if (check_count(count) != CORRECT)
		return (print_error(BADCOUNT, -1, false));
	return (print_error(CORRECT, CORRECT, false));
}

int	p_ambient_light(char *line, t_count *count)
{
	int		err;
	char	**temp;

	err = is_there_tabs(line);
	if (err != CORRECT)
		return (print_error(BADALIGHT, BADALIGHT, false));
	temp = ft_split(line, 32);
	if (!temp[0] || !temp[1] || !temp[2] || temp[3] != NULL)
		return (print_error(BADALIGHT, BADALIGHT, true));
	err = check_syntaxe(temp, 1, 0);
	if (err != CORRECT)
		return (print_error(BADALIGHT, err, false));
	err = check_ratio(temp[1]);
	if (err != 0)
		return (print_error(BADALIGHT, BADALIGHT, false));
	err = check_rgb(temp[2], 0, 0);
	if (err != 0)
		return (print_error(BADALIGHT, BADALIGHT, false));
	ft_xxfree((void **)temp);
	ft_printf_fd (2, "Pour le Ambient Light, ");
	count->la++;
	return (print_error(CORRECT, CORRECT, false));
}

static void	print_error2(int err)
{
	if (err == BADRATIO)
		ft_printf_fd (2, "Error #%d: Problème avec le ratio\n", err);
	else if (err == BADFOV)
		ft_printf_fd (2, "Error #%d: Probleme avec le Fov\n", err);
	else if (err == BADTABS)
		ft_printf_fd (2, "Error #%d: Probleme avec les tabs\n", err);
	else if (err == BADVECTOR)
		ft_printf_fd (2, "Error #%d: Probleme avec le vector\n", err);
	else if (err == BADORI)
		ft_printf_fd (2, "Error #%d: Probleme avec vector\
		 d'orientation\n", err);
	else if (err == BADSYN)
		ft_printf_fd (2, "Error #%d: Probleme avec la syntaxe\n", err);
	else if (err == BADDIA)
		ft_printf_fd (2, "Error #%d: Probleme avec le Diametre\n", err);
	else if (err == BADCOUNT)
		ft_printf_fd (2, "Error #%d: Probleme avec le Count\n", err);
	else if (err == NOEXT)
		ft_printf_fd (2, "Error #%d: Aucun ext pour le ficher (.rt)\n", err);
	else if (err == TOOEXT)
		ft_printf_fd (2, "Error #%d: Trop d'extension pour un seul fichier,\
		se limité à un seul (.rt)\n", err);
	else if (err == WRONGEXT)
		ft_printf_fd (2, "Error #%d : Mauvaise extension, l'extension\
		recherchée est (.rt)\n", err);
}

int	print_error(int err, int ret, int args)
{
	if (err == CORRECT)
		ft_printf_fd (2, "TOUT EST CORRECT\n");
	if (args == true)
		ft_printf_fd (2, "Error #17: Nombre d'arguments incorrect\n");
	if (err == OPENWRONG)
		ft_printf_fd (2, "Error #%d: File non existant\n", err);
	else if (err == BADTYPE)
		ft_printf_fd (2, "Error #%d: Type d'objet non existant\n", err);
	else if (err == BADALIGHT)
		ft_printf_fd (2, "Error #%d: Problème avec la lumière ambiante\n", err);
	else if (err == BADCAMERA)
		ft_printf_fd (2, "Error #%d: Problème avec la caméra\n", err);
	else if (err == BADLIGHT)
		ft_printf_fd (2, "Error #%d: Problème avec la lumière\n", err);
	else if (err == BADPLANE)
		ft_printf_fd (2, "Error #%d: Problème avec le plane\n", err);
	else if (err == BADSPHERE)
		ft_printf_fd (2, "Error #%d: Problème avec la sphère\n", err);
	else if (err == BADCYL)
		ft_printf_fd (2, "Error #%d: Problème avec le cylindre\n", err);
	else if (err == BADRGB)
		ft_printf_fd (2, "Error #%d: Problème avec le RGB\n", err);
	else
		print_error2(err);
	return (ret);
}
