/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:53 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/07 19:05:19 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

// static int collision(t_datas *datas)
// {
// 	int	px;
// 	int	py;
//
// 	px = (datas->player->pos_x + 32) / 64;
// 	py = (datas->player->pos_y + 32) / 64;
// 	if (datas->map->blueprint[py + 1][px] == '1')
// 		printf("WALL (%d, %d)\n", px, py + 1);
// 	if (datas->map->blueprint[py][px + 1] == '1')
// 		printf("WALL (%d, %d)\n", px + 1, py);
// 	if (datas->map->blueprint[py][px] == '1')
// 		printf("WALL OUPS\n");
// 	if (datas->map->blueprint[py - 1][px] == '1')
// 		printf("WALL (%d, %d)\n", px, py - 1);
// 	if (datas->map->blueprint[py][px - 1] == '1')
// 		printf("WALL (%d, %d)\n", px - 1, py);
// 	return (0);
// }

static void	move_north(t_player *player, t_map *map)
{
	int	px;
	int	py;

	px = (player->pos_x + 32) / 64;
	py = (player->pos_y + 32) / 64;
	if (map->blueprint[py - 1][px] == '1' && player->pos_y - 8 < ((py - 1) * 64) + 64)
	{
		player->dir = 'U';
		player->current = player->player_up[player->frame];
	}
	else
	{
		player->pos_y -= 8;
		player->current = player->player_up[player->frame];
		player->frame++;
	}
}

static void	move_east(t_player *player, t_map *map)
{
	int	px;
	int	py;

	px = (player->pos_x + 32) / 64;
	py = (player->pos_y + 32) / 64;
	if (map->blueprint[py][px + 1] == '1' && player->pos_x + 8 > px * 64)
	{
		player->dir = 'R';
		player->current = player->player_right[player->frame];
	}
	else
	{
		player->pos_x += 8;
		player->current = player->player_right[player->frame];
		player->frame++;
	}
}

static void	move_south(t_player *player, t_map *map)
{
	int	px;
	int	py;

	px = (player->pos_x + 32) / 64;
	py = (player->pos_y + 32) / 64;
	// if (map->blueprint[py + 1][px] == '1')
	// 	printf("DEBUG: P[%d,%d][%d,%d] W[%d,%d]OK\n", px, py, player->pos_x, player->pos_y, px, py + 1);
	// else
	// 	printf("DEBUG: P[%d,%d][%d,%d] W[%d,%d]KO\n", px, py, player->pos_x, player->pos_y, px, py + 1);
	if (map->blueprint[py + 1][px] == '1' && player->pos_y + 8 > py * 64)
	{
		player->dir = 'D';
		player->current = player->player_down[player->frame];
	}
	else
	{
		player->pos_y += 8;
		player->current = player->player_down[player->frame];
		player->frame++;
	}
}

static void	move_west(t_player *player, t_map *map)
{
	int	px;
	int	py;

	px = (player->pos_x + 32) / 64;
	py = (player->pos_y + 32) / 64;
	if (map->blueprint[py][px - 1] == '1' && player->pos_x - 8 < ((px - 1) * 64) + 64)
	{
		player->dir = 'L';
		player->current = player->player_left[player->frame];
	}
	else
	{
		player->pos_x -= 8;
		player->current = player->player_left[player->frame];
		player->frame++;
	}
}

static void loot_item(t_datas *datas)
{
	char		**bp;
	int			x;
	int			y;

	bp = datas->map->blueprint;
	x = datas->player->pos_x;
	y = datas->player->pos_y;
	if (bp[(y + 32) / 64][(x + 32) / 64] == 'C'
		|| bp[(y + 32) / 64][(x + 32) / 64] == 'G'
		|| bp[(y + 32) / 64][(x + 32) / 64] == 'K'
		|| bp[(y + 32) / 64][(x + 32) / 64] == 'A')
	{
		--datas->remaining_items;
		bp[(y + 32) / 64][(x + 32) / 64] = '0';
	}
}

void    ft_move_player(t_datas *datas)
{
    while (1)
	{
		if (datas->keycode == NORTH)
			move_north(datas->player, datas->map);
		else if (datas->keycode == EAST)
			move_east(datas->player, datas->map);
		else if (datas->keycode == SOUTH)
			move_south(datas->player, datas->map);
		else if (datas->keycode == WEST)
			move_west(datas->player, datas->map);
		if (datas->player->frame > 7)
			datas->player->frame = 0;
		loot_item(datas);
		if (datas->map->blueprint[(datas->player->pos_y + 32) / 64][(datas->player->pos_x + 32) / 64] == 'E' && datas->map->portal_open == 1)
		{
			pthread_cancel(datas->player_thread);
			ft_close(datas);
		}
		usleep(20000);
	}
}
