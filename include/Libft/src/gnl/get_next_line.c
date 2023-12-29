/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:27:09 by rapelcha          #+#    #+#             */
/*   Updated: 2023/12/19 14:45:39 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static char	*ft_trimstorage(char *storage)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = NULL;
	if (*storage == '\0')
		return (storage = ft_xfree(storage));
	while (storage[i])
		if (storage[i++] == '\n')
			break ;
	res = ft_calloc(ft_strlen(storage) - i + 1, sizeof(char));
	while (storage[i] != '\0')
	{
		res[j] = storage[i];
		i++;
		j++;
	}
	return (storage = ft_xfree(storage), res);
}

static char	*ft_writeres(char *storage)
{
	char	*res;
	size_t	len;

	len = 0;
	while (storage[len] != '\n' && storage[len] != '\0')
		len++;
	if (storage[len] == '\n')
		len++;
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (res = ft_xfree(res));
	while (len--)
		res[len] = storage[len];
	return (res);
}

static char	*gnl_strjoin(char *src1, char *src2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src2)
		return (NULL);
	res = ft_calloc(ft_strlen(src1) + ft_strlen(src2) + 1, sizeof(char));
	if (!res)
		return (res = ft_xfree(res));
	while (src1 && src1[i] != '\0')
	{
		res[i] = src1[i];
		i++;
	}
	while (src2[j] != '\0')
	{
		res[i] = src2[j];
		i++;
		j++;
	}
	return (src1 = ft_xfree(src1), res);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	t_var		t_var;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_calloc(1, sizeof(char));
	t_var.ver = 1;
	t_var.buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (t_var.ver > 0 && (ft_searchstr(storage[fd], '\n') == 0))
	{
		ft_bzero(t_var.buffer, BUFFER_SIZE);
		t_var.ver = read(fd, t_var.buffer, BUFFER_SIZE);
		if (t_var.ver <= 0)
			break ;
		storage[fd] = gnl_strjoin(storage[fd], t_var.buffer);
	}
	t_var.buffer = ft_xfree(t_var.buffer);
	if (t_var.ver < 0 || (t_var.ver <= 0 && *storage[fd] == '\0'))
		return (storage[fd] = ft_xfree(storage[fd]), NULL);
	t_var.buffer = ft_writeres(storage[fd]);
	storage[fd] = ft_trimstorage(storage[fd]);
	return (t_var.buffer);
}
