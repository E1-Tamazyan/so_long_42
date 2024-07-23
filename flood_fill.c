/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:06:40 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 16:20:45 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_dup(t_map *map, int i, int j)
{
	char	**clone;

	clone = (char **)malloc((map->raws + 1) * sizeof(char *));
	if (!clone)
		return (NULL);
	while (i < map->raws)
	{
		j = 0;
		clone[i] = (char *)malloc((map->cols + 1) * sizeof(char));
		if (!clone[i])
		{
			clean_str(clone, i);
			return (NULL);
		}
		while (j < map->cols)
		{
			clone[i][j] = map->data[i][j];
			j++;
		}
		clone[i][j] = '\0';
		i++;
	}
	clone[i] = NULL;
	return (clone);
}

void	flood(t_map *map)
{
	t_plr		plr_start_pos;
	int			i;
	char		c;
	char		**clone_map;

	i = 0;
	clone_map = NULL;
	clone_map = map_dup(map, 0, 0);
	if (!clone_map)
		exit(0);
	plr_start_pos.pos_y = map->plr.pos_y;
	plr_start_pos.pos_x = map->plr.pos_x;
	c = '0';
	clone_map[plr_start_pos.pos_y][plr_start_pos.pos_x] = c;
	fill(clone_map, map, plr_start_pos, c);
	passable_path(clone_map);
	clean_str(clone_map, map->raws);
}

void	fill(char **d_map, t_map *map, t_plr current, char c)
{
	if (d_map[current.pos_y][current.pos_x] == 'C'
			|| d_map[current.pos_y][current.pos_x] == 'E')
		d_map[current.pos_y][current.pos_x] = '0';
	if (d_map[current.pos_y][current.pos_x] != c)
		return ;
	d_map[current.pos_y][current.pos_x] = 'F';
	fill(d_map, map, (t_plr){current.pos_x - 1, current.pos_y}, c);
	fill(d_map, map, (t_plr){current.pos_x + 1, current.pos_y}, c);
	fill(d_map, map, (t_plr){current.pos_x, current.pos_y - 1}, c);
	fill(d_map, map, (t_plr){current.pos_x, current.pos_y + 1}, c);
	return ;
}

void	passable_path(char **path)
{
	int	i;
	int	j;

	i = 0;
	while (path[i])
	{
		j = 0;
		while (path[i][j])
		{
			if (path[i][j] == 'C')
				exit(write(2, "Some coins are not reachable\n", 29));
			if (path[i][j] == 'E')
				exit(write(2, "Exit is not reachable\n", 22));
			j++;
		}
		i++;
	}
}

void	*anim_coin(t_game *game)
{
	static int	i;

	if (i < 50)
	{
		i++;
		return (game->img.coin);
	}
	if (i < 150)
	{
		i++;
		return (game->img.rcoin);
	}
	i = 0;
	return (game->img.coin);
}
