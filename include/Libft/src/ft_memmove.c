/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:52:16 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*pstr1;
	const char	*pstr2;
	char		*last1;
	const char	*last2;

	pstr1 = str1;
	pstr2 = str2;
	if (!str1 || !str2)
		return (NULL);
	if (str1 != NULL || str2 != NULL)
	{
		if (str1 < str2)
		{
			while (n--)
				*pstr1++ = *pstr2++;
		}
		else
		{
			last1 = pstr1 + (n - 1);
			last2 = pstr2 + (n - 1);
			while (n--)
					*last1-- = *last2--;
		}
	}
	return (str1);
}
