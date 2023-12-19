/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:20:29 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 17:17:48 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	read_map(char *file_path, t_count *count)
{
	int	fd;
	int	i;
	char *line;

	fd = open(file_path, O_RDONLY);
	line = "coucou";
	while (line)
	{
		line = get_next_line(fd);
	}
}
