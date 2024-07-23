/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:27:42 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/16 12:09:51 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_str(char **arr, int i)
{
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

int	press_exit(t_game *game)
{
	exit_game(game, 0);
	return (0);
}

void	exit_game(t_game *game, int out)
{
	if (out == 1)
		write(1, "SUCCESS!!!\n", 11);
	else if (out == 0)
		write(1, "GAME OVER\n", 10);
	mlx_destroy_image(game->img.mlx, game->img.coin);
	mlx_destroy_image(game->img.mlx, game->img.rcoin);
	mlx_destroy_image(game->img.mlx, game->img.walls);
	mlx_destroy_image(game->img.mlx, game->img.monster);
	mlx_destroy_image(game->img.mlx, game->img.ground);
	mlx_destroy_image(game->img.mlx, game->img.plr);
	mlx_destroy_image(game->img.mlx, game->img.l_pr);
	mlx_destroy_image(game->img.mlx, game->img.o_exit);
	mlx_destroy_image(game->img.mlx, game->img.c_exit);
	mlx_destroy_image(game->img.mlx, game->img.win);
	clean_str(game->map.data, game->map.raws);
	exit(0);
}
