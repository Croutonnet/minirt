/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:11 by rapelcha          #+#    #+#             */
/*   Updated: 2022/11/03 20:05:43 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	find;

	temp = 0;
	find = c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == find)
			temp = (char *)s;
		s++;
	}
	if (*s == find)
		return ((char *)s);
	return (temp);
}
