/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:14:28 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/09 16:29:57 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->map.data[game->map.plr.pos_y - 1][game->map.plr.pos_x] != '1')
	{
		if (game->map.data[game->map.plr.pos_y - 1][game->map.plr.pos_x] == 'M')
			exit_game(game, 0);
		if (game->map.data[game->map.plr.pos_y - 1][game->map.plr.pos_x] == 'C')
		{
			game->map.data[game->map.plr.pos_y - 1][game->map.plr.pos_x] = '0';
			game->map.coins -= 1;
		}
		if (game->map.data[game->map.plr.pos_y - 1][game->map.plr.pos_x] == 'E')
		{
			if (game->img.e == game->img.o_exit)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.plr.pos_y -= 1;
	}
}

void	move_down(t_game *game)
{
	if (game->map.data[game->map.plr.pos_y + 1][game->map.plr.pos_x] != '1')
	{
		if (game->map.data[game->map.plr.pos_y + 1][game->map.plr.pos_x] == 'M')
			exit_game(game, 0);
		if (game->map.data[game->map.plr.pos_y + 1][game->map.plr.pos_x] == 'C')
		{
			game->map.data[game->map.plr.pos_y + 1][game->map.plr.pos_x] = '0';
			game->map.coins -= 1;
		}
		if (game->map.data[game->map.plr.pos_y + 1][game->map.plr.pos_x] == 'E')
		{
			if (game->img.e == game->img.o_exit)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.plr.pos_y += 1;
	}
}

void	move_left(t_game *game)
{
	game->img.p = game->img.l_pr;
	if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x - 1]
		&& game->map.data[game->map.plr.pos_y][game->map.plr.pos_x - 1] != '1')
	{
		if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x - 1] == 'M')
			exit_game(game, 0);
		if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x - 1] == 'C')
		{
			game->map.data[game->map.plr.pos_y][game->map.plr.pos_x - 1] = '0';
			game->map.coins -= 1;
		}
		if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x - 1] == 'E')
		{
			if (game->img.e == game->img.o_exit)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.plr.pos_x -= 1;
	}
}

void	move_right(t_game *game)
{
	game->img.p = game->img.plr;
	if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x + 1] != '1')
	{
		if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x + 1] == 'M')
			exit_game(game, 0);
		if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x + 1] == 'C')
		{
			game->map.data[game->map.plr.pos_y][game->map.plr.pos_x + 1] = '0';
			game->map.coins -= 1;
		}
		if (game->map.data[game->map.plr.pos_y][game->map.plr.pos_x + 1] == 'E')
		{
			if (game->img.e == game->img.o_exit)
				exit_game(game, 1);
		}
		game->steps += 1;
		game->map.plr.pos_x += 1;
	}
}
