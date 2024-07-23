/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_pt2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:10:56 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 19:43:21 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_existence(t_map **map, char c)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < (*map)->raws)
	{
		j = 1;
		while (j < (*map)->cols)
		{
			if ((*map)->data[i][j] == c)
				count += 1;
			j++;
		}
		i++;
	}
	if (count < 1 && c == 'E')
		exit(write(2, "There is no exit\n", 17));
	if (count != 1 && c == 'E')
		exit(write(2, "More than one exit\n", 19));
	if (count < 1 && c == 'C')
		exit(write(2, "There is no coin\n", 17));
	if (c == 'C' && count >= 1)
		(*map)->coins = count;
}

void	plr_existence(t_map *map)
{
	int		i;
	int		j;
	int		count;

	i = 1;
	count = 0;
	while (i < map->raws)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->data[i][j] == 'P')
			{
				count += 1;
				map->plr.pos_y = i;
				map->plr.pos_x = j;
			}
			j++;
		}
		i++;
	}
	if (count < 1)
		exit(write(2, "There is no player\n", 19));
	if (count > 1)
		exit(write(2, "More than one player\n", 21));
}
