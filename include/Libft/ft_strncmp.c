/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:43:56 by rapelcha          #+#    #+#             */
/*   Updated: 2022/11/03 20:00:57 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (n-- > 0)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (c1 != c2)
			return (c1 - c2);
		if (c1 == '\0')
			return (i);
	}
	return (i);
}
