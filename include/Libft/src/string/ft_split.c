/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:52 by rapelcha          #+#    #+#             */
/*   Updated: 2024/01/25 13:19:38 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	**freeall(char **strr)
{
	int	i;

	i = 0;
	while (strr[i])
		free(strr[i++]);
	free(strr);
	return (NULL);
}

static	size_t	ft_wordcount(char const *s, char c)
{
	size_t	wc;
	size_t	i;

	wc = 0;
	i = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			wc++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (!(s[i - 1] == c))
		wc++;
	return (wc);
}

static void	ft_row(char **row, size_t *len, char c)
{
	size_t	i;

	*row += *len;
	*len = 0;
	i = 0;
	while (**row && **row == c)
		(*row)++;
	while ((*row)[i])
	{
		if ((*row)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**strr;
	char	*str;
	size_t	len;
	size_t	j;

	str = (char *)s;
	if (!str)
		return (NULL);
	i = ft_wordcount(s, c);
	strr = (char **)ft_calloc((i + 1), sizeof (char *));
	if (!strr)
		return (NULL);
	len = 0;
	j = 0;
	while (j < i)
	{
		ft_row(&str, &len, c);
		strr[j] = malloc((len + 1) * sizeof(char));
		if (!strr[j])
			return (freeall(strr));
		ft_strlcpy(strr[j], str, len + 1);
		j++;
	}
	return (strr);
}
