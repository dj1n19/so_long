/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:53 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

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

void	*move_player(void *datas)
{
	t_datas	*d;

	d = (t_datas *)datas;
	while (1)
	{
		if (d->keycode == NORTH)
			move_north(d->player, d->textures, d->map);
		else if (d->keycode == EAST)
			move_east(d->player, d->textures, d->map);
		else if (d->keycode == SOUTH)
			move_south(d->player, d->textures, d->map);
		else if (d->keycode == WEST)
			move_west(d->player, d->textures, d->map);
		if (d->player->frame > 7)
			reset_player_anim(d);
		loot_item(d);
		if (d->map->map[(d->player->y + 32) / 64]
			[(d->player->x + 32) / 64] == 'E' && d->map->is_portal_open == 1)
		{
			d->mt_running = 0;
			pthread_cancel(*d->move_thread);
		}
		usleep(50000);
	}
	return (d);
}
