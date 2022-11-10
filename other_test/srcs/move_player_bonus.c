/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dj1n <dj1n@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:53 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/10 22:30:26 by dj1n             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_north(t_player *player, t_textures *textures, t_map *map)
{
	int	px;
	int	py;

	px = (player->x + 32) / 64;
	py = (player->y + 32) / 64;
	if (map->map[py - 1][px] == '1' && player->y - 8 < ((py - 1) * 64) + 64)
	{
		player->dir = 'U';
		player->current = textures->player_up[player->frame];
	}
	else
	{
		player->y -= 8;
		player->current = textures->player_up[player->frame];
		player->frame++;
	}
}

static void	move_east(t_player *player, t_textures *textures, t_map *map)
{
	int	px;
	int	py;

	px = (player->x + 32) / 64;
	py = (player->y + 32) / 64;
	if (map->map[py][px + 1] == '1' && player->x + 8 > px * 64)
	{
		player->dir = 'R';
		player->current = textures->player_right[player->frame];
	}
	else
	{
		player->x += 8;
		player->current = textures->player_right[player->frame];
		player->frame++;
	}
}

static void	move_south(t_player *player, t_textures *textures, t_map *map)
{
	int	px;
	int	py;

	px = (player->x + 32) / 64;
	py = (player->y + 32) / 64;
	if (map->map[py + 1][px] == '1' && player->y + 8 > py * 64)
	{
		player->dir = 'D';
		player->current = textures->player_down[player->frame];
	}
	else
	{
		player->y += 8;
		player->current = textures->player_down[player->frame];
		player->frame++;
	}
}

static void	move_west(t_player *player, t_textures *textures, t_map *map)
{
	int	px;
	int	py;

	px = (player->x + 32) / 64;
	py = (player->y + 32) / 64;
	if (map->map[py][px - 1] == '1' && player->x - 8 < ((px - 1) * 64) + 64)
	{
		player->dir = 'L';
		player->current = textures->player_left[player->frame];
	}
	else
	{
		player->x -= 8;
		player->current = textures->player_left[player->frame];
		player->frame++;
	}
}

static void	loot_item(t_datas *datas)
{
	char		**map;
	int			x;
	int			y;

	map = datas->map->map;
	x = datas->player->x;
	y = datas->player->y;
	if (map[(y + 32) / 64][(x + 32) / 64] == 'C'
		|| map[(y + 32) / 64][(x + 32) / 64] == 'G'
		|| map[(y + 32) / 64][(x + 32) / 64] == 'K'
		|| map[(y + 32) / 64][(x + 32) / 64] == 'A')
	{
		--datas->items;
		map[(y + 32) / 64][(x + 32) / 64] = '0';
	}
}

void	move_player(t_datas *datas)
{
	while (1)
	{
		if (datas->keycode == NORTH)
			move_north(datas->player, datas->textures, datas->map);
		else if (datas->keycode == EAST)
			move_east(datas->player, datas->textures, datas->map);
		else if (datas->keycode == SOUTH)
			move_south(datas->player, datas->textures, datas->map);
		else if (datas->keycode == WEST)
			move_west(datas->player, datas->textures, datas->map);
		if (datas->player->frame > 7)
		{
			datas->player->move_count++;
			datas->player->frame = 0;
		}
		loot_item(datas);
		if (datas->map->map[(datas->player->y + 32) / 64]
			[(datas->player->x + 32) / 64] == 'E'
			&& datas->map->is_portal_open == 1)
		{
			datas->mt_running = 0;
			pthread_cancel(*datas->move_thread);
		}
		usleep(20000);
	}
}
