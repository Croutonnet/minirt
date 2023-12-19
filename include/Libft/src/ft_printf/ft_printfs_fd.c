/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfs_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:35:49 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 15:53:56 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_printfs_fd(char *str, int fd)
{
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
