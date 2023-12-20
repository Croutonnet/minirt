/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:37:13 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/20 13:01:37 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

t_vector	create_vector_str(char *str)
{
	double nb1;
	double nb2;
	double nb3;
	int		i;
	
	i = 0;
	nb1 = ft_atof(str);
	while (str[i] != ',')
		i++;
	i++;
	nb2 = ft_atof(&str[i]);
	while (str[i] != ',')
		i++;
	i++;
	nb3 = ft_atof(&str[i]);
	return(create_vector(nb1, nb2, nb3));
}

void	pcreate_plane(t_shapes_arr *shapes)
{

}

void	pcreate_sphere(t_shapes_arr *shapes)
{

}

void	pcreate_cylindre(t_shapes_arr *shapes)
{

}

