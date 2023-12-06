/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:49:30 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{	
	size_t	i;
	size_t	j;

	if (!big || !little)
		return (NULL);
	j = 0;
	i = 0;
	if (!*little)
		return ((char *)big);
	while (j <= len && big[j])
	{
		while (little[i] == big[j + i] && j + i < len && big[j + i] != '\0')
			i++;
		if (little[i] == '\0')
			return ((char *)big + j);
		j++;
		i = 0;
	}
	return (NULL);
}
