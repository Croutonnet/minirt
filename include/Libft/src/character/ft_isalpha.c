/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:00:35 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 14:48:19 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_isalpha(int a)
{
	if (a >= 65 && a <= 90)
		return (a);
	else if (a >= 97 && a <= 122)
		return (a);
	else
		return (0);
}
