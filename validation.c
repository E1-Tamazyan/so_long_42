/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:10:51 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 20:20:51 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_map_valid(t_map *map)
{
	int		i;
	int		raws;

	raws = 0;
	while (map->data[raws])
		raws++;
	map->raws = raws;
	map->cols = ft_strlen(map->data[0]);
	i = 1;
	if ((map->raws < 3) || (map->cols < 3))
		exit(write(2, "Invalid map\n", 12));
	while (map->data[i])
	{
		if (map->cols != (int)ft_strlen(map->data[i]))
			exit(write(2, "Invalid map\n", 12));
		i++;
	}
	check_chars(map);
	check_walls(map);
	char_existence(&map, 'E');
	char_existence(&map, 'C');
	plr_existence(map);
	flood(map);
}

void	check_chars(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->raws)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->data[i][j] != '1' && map->data[i][j] != '0'
				&& map->data[i][j] != 'P' && map->data[i][j] != 'E'
				&& map->data[i][j] != 'C' && map->data[i][j] != 'M' )
			{
				write (2, "There is an unknown object\n", 27);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_map *map)
{
	int		j;

	j = 0;
	while (map->data[0][j] || map->data[map->raws - 1][j])
	{
		if (map->data[0][j] != '1'
				|| map->data[map->raws - 1][j] != '1')
			exit(write(2, "Invalid map\n", 12));
		j++;
	}
	check_sidewalls(map);
}

void	check_sidewalls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->raws)
	{
		if (map->data[i][0] != '1'
				|| map->data[i][map->cols - 1] != '1')
			exit(write(2, "Invalid map\n", 12));
		i++;
	}
}
