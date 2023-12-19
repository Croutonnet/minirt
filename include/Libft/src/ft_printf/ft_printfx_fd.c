/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfx_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:35:52 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 15:54:47 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_size(unsigned int n)
{
	int	size;

	size = 1;
	while (n > 15)
	{
		n /= 16;
		size++;
	}
	return (size);
}

int	ft_printfx_fd(unsigned int n, int fd)
{
	if (n > 15)
	{
		ft_printfx_fd(n / 16, fd);
		ft_printfx_fd(n % 16, fd);
	}
	else
	{
		if (n > 9)
			ft_printfc_fd(n + 87, fd);
		else
			ft_printfc_fd(n + 48, fd);
	}
	return (ft_size(n));
}
