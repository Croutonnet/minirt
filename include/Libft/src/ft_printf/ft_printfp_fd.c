/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfp_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:35:47 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 15:53:22 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	convx(uintptr_t p, int *count, int fd)
{
	if (p > 15)
	{
		convx(p / 16, count, fd);
		convx(p % 16, count++, fd);
	}
	else
	{
		if (p > 9)
			(*count) += ft_printfc_fd(p + 87, fd);
		else
			(*count) += ft_printfc_fd(p + 48, fd);
	}
}

int	ft_printfp_fd(void *p, int fd)
{
	int	count;

	count = 2;
	ft_printfs_fd("0x", fd);
	convx((uintptr_t)p, &count, fd);
	return (count);
}
