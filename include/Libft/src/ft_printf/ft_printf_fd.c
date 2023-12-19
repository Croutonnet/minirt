/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:06:48 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 15:55:32 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_formats(const char type, va_list args, int fd)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += ft_printfc_fd(va_arg(args, int), fd);
	else if (type == 'd' || type == 'i')
		count += ft_printfd_fd(va_arg(args, int), fd);
	else if (type == 'p')
		count += ft_printfp_fd(va_arg(args, void *), fd);
	else if (type == 's')
		count += ft_printfs_fd(va_arg(args, char *), fd);
	else if (type == 'u')
		count += ft_printfu_fd(va_arg(args, unsigned int), fd);
	else if (type == 'x')
		count += ft_printfx_fd(va_arg(args, unsigned int), fd);
	else if (type == 'X')
		count += ft_printfxx_fd(va_arg(args, unsigned int), fd);
	else if (type == '%')
		count += ft_printfc_fd('%', fd);
	return (count);
}

int	ft_printf_fd(int fd, const char *type, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start (args, type);
	while (type[i])
	{
		if (type[i] != '%')
			count += ft_printfc_fd(type[i], fd);
		else
		{
			i++;
			count += ft_formats(type[i], args, fd);
		}
		i++;
	}
	va_end(args);
	return (count);
}
