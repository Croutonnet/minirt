/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:28:40 by rapelcha          #+#    #+#             */
/*   Updated: 2022/11/03 20:07:53 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ifset(char c, char const *set)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (flag + 1);
		i++;
	}
	return (flag);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		end;
	int		j;
	int		i;
	int		start;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_ifset(s1[i], set) == 1)
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > start && ft_ifset(s1[i - 1], set) == 1)
		i--;
	end = i;
	str = (char *)ft_calloc(((end - start) + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
		str[j++] = s1[start++];
	return (str);
}
