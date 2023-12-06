/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xxfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:41:18 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/05 20:01:16 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	**ft_xxfree(void **pointer)
{
	int	i;

	if (!pointer)
		return (NULL);
	i = 0;
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free (pointer);
	return (NULL);
}