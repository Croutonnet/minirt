/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:42:02 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	count;

	count = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (s[i++] && count < len)
			count++;
	}
	i = 0;
	str = (char *)ft_calloc((count + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str[i] = '\0';
		return (str);
	}
	while (s[start] && i < len)
		str[i++] = s[start++];
	return (str);
}
