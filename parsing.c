/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:21:20 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 17:24:14 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fd_parse(int fd)
{
	char	*each_line;
	char	*temp;
	char	**res;

	each_line = get_next_line(fd);
	temp = each_line;
	if (!each_line)
		return (NULL);
	while (temp)
	{
		temp = get_next_line(fd);
		each_line = ft_strjoin(each_line, temp);
		free(temp);
	}
	each_line = check_newline2(each_line);
	check_newline(each_line);
	res = ft_split(each_line, '\n');
	check_whitespaces(res);
	free (each_line);
	return (res);
}
