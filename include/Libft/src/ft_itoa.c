/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:19:33 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			i;

	nb = n;
	i = ft_size(nb);
	str = (char *)ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (i-- > 0)
	{
		if (nb < 0)
		{
			str[0] = '-';
			nb *= -1;
		}
		while (nb > 9 && i > 0)
		{
			str[i--] = (nb % 10) + 48;
			nb /= 10;
		}
		str[i--] = nb + 48;
	}
	return (str);
}
