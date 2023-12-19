/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfu_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:35:50 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 15:54:17 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_size(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_printfu_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + 48, fd);
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	return (ft_size(n));
}
