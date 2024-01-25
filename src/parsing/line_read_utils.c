/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:53:08 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/21 13:56:39 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

int	p_cylindre_2(char **temp, int err)
{
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
	return (err);
}
