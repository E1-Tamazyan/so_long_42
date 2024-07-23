/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 12:08:33 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/02 20:35:53 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_filtr(char *buffer)
{
	char	*temp;
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (!buffer || !(*buffer))
		return (NULL);
	while (buffer[size] && buffer[size] != '\n')
		size++;
	temp = (char *)malloc((size + 2) * sizeof(char));
	if (!temp)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		temp[i] = '\n';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_readfd(int fd, char *buffer)
{
	char	*res;
	int		bytes;

	res = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!res)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && ft_strchr(buffer, '\n') == 0)
	{
		bytes = read(fd, res, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(res);
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		res[bytes] = '\0';
		buffer = ft_strjoin(buffer, res);
	}
	free(res);
	res = NULL;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	int			dir;

	dir = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_readfd(fd, buffer);
	if (!buffer)
		return (NULL);
	while (buffer[dir] && buffer[dir] != '\n')
		dir++;
	if (buffer[dir] == '\n')
		dir++;
	res = ft_filtr(buffer);
	if (!res)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_strdup(buffer, dir);
	if (!buffer)
		return (NULL);
	return (res);
}
