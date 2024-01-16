/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:52:28 by rapelcha          #+#    #+#             */
/*   Updated: 2022/12/04 14:06:26 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *pointer, size_t len, size_t size)
{
	void	*new;

	new = ft_calloc(len + 1, size);
	if (!new)
		return (NULL);
	ft_memcpy(new, pointer, len * size);
	ft_xfree(pointer);
	return (new);
}
