/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:43:37 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 15:58:15 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_game *game, void *anim)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.raws)
	{
		j = 0;
		while (j < game->map.cols)
		{
			mlx_put_image_to_window(game->img.mlx, game->img.win,
				game->img.ground, j * SIZE, i * SIZE);
			init_map_pt2(game, anim, i, j);
			init_map_pt3(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

void	init_map_pt2(t_game *game, void *anim, int i, int j)
{
	mlx_put_image_to_window(game->img.mlx, game->img.win,
		game->img.p, game->map.plr.pos_x * SIZE,
		game->map.plr.pos_y * SIZE);
	if (game->map.data[i][j] == 'E')
		mlx_put_image_to_window(game->img.mlx, game->img.win,
			game->img.e, j * SIZE, i * SIZE);
	else if (game->map.data[i][j] == 'C')
		mlx_put_image_to_window(game->img.mlx, game->img.win,
			anim, j * SIZE, i * SIZE);
}

void	init_map_pt3(t_game *game, int i, int j)
{
	if (game->map.data[i][j] == '1')
		mlx_put_image_to_window(game->img.mlx, game->img.win,
			game->img.walls, j * SIZE, i * SIZE);
	else if (game->map.data[i][j] == 'M')
		mlx_put_image_to_window(game->img.mlx, game->img.win,
			game->img.monster, j * SIZE, i * SIZE);
}

int	frame(t_game *game)
{
	void	*animation;

	animation = anim_coin(game);
	if (game->map.coins == 0)
		game->img.e = game->img.o_exit;
	mlx_clear_window(game->img.mlx, game->img.win);
	init_map(game, animation);
	change_point(game);
	return (0);
}
