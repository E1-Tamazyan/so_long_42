/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:10:37 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 17:24:42 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

int	ft_strncmp(const char *s1, const char *s2, int limit)
{
	int	i;
	int	res;

	i = 0;
	while (((s1[i] || s2[i]) && (i < limit)))
	{
		if (s1[i] != s2[i])
		{
			res = (int)(unsigned char)s1[i] - (int)(unsigned char)s2[i];
			return (res);
		}
		i++;
	}
	return (0);
}

void	is_fd_valid(char *argv)
{
	while (*argv != '.')
		argv++;
	if (ft_strncmp(".ber", argv, 4) != 0)
		exit(write(2, "Invalid file\n", 13));
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	fd = 0;
	if (argc != 2)
		return (write(2, "Invalid amount of arguments\n", 28));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (write(2, "Invalid file.\n", 14));
	is_fd_valid(argv[1]);
	map.data = fd_parse(fd);
	is_map_valid(&map);
	run_game(&map);
	return (0);
}
