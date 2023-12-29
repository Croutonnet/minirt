/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:54:56 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 14:48:19 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = c;
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == find)
			return ((char *)s);
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (0);
}
