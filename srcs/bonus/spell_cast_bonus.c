/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_cast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:33:31 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	spell_anim(t_player *player, t_textures *textures)
{
	player->current = textures->player_attack[player->frame];
	player->frame++;
}

static int	is_front_wall(t_player *player, t_map *map)
{
	char	**m;

	m = map->map;
	if ((player->dir == 'U' && (player->y - 64) / 64 == 0)
		|| (player->dir == 'D' && (player->y + 64) / 64 == map->y - 1)
		|| (player->dir == 'L' && (player->x - 64) / 64 == 0)
		|| (player->dir == 'R' && (player->x + 64) / 64 == map->x - 1))
		return (0);
	if (player->dir == 'U' && m[(player->y - 64) / 64][player->x / 64] == '1')
		return ('U');
	else if (player->dir == 'D'
		&& m[(player->y + 64) / 64][player->x / 64] == '1')
		return ('D');
	else if (player->dir == 'L'
		&& m[player->y / 64][(player->x - 64) / 64] == '1')
		return ('L');
	else if (player->dir == 'R'
		&& m[player->y / 64][(player->x + 64) / 64] == '1')
		return ('R');
	return (0);
}

void	draw_spell(t_img *img, t_player *p, t_textures *tex)
{
	if (p->spell_target == 'U')
		write_to_img(img, tex->player_spell[p->frame], p->x, p->y - 64);
	else if (p->spell_target == 'D')
		write_to_img(img, tex->player_spell[p->frame], p->x, p->y + 64);
	else if (p->spell_target == 'L')
		write_to_img(img, tex->player_spell[p->frame], p->x - 64, p->y);
	else if (p->spell_target == 'R')
		write_to_img(img, tex->player_spell[p->frame], p->x + 64, p->y);
	else
		p->spell_target = 0;
}

static void	delete_wall(t_datas *d, t_map *map, t_player *player)
{
	if (player->spell_target == 'U')
		map->map[(player->y - 64) / 64][player->x / 64] = '0';
	else if (player->spell_target == 'D')
		map->map[(player->y + 64) / 64][player->x / 64] = '0';
	else if (player->spell_target == 'L')
		map->map[player->y / 64][(player->x - 64) / 64] = '0';
	else if (player->spell_target == 'R')
		map->map[player->y / 64][(player->x + 64) / 64] = '0';
	d->player->spell_target = 0;
	d->player->frame = 0;
	d->pt_running = 0;
	pthread_exit(0);
}

void	*ft_spell_cast(void *dt)
{
	t_datas	*d;

	d = (t_datas *)dt;
	while (1)
	{
		if (d->player->spell_target == 0)
		{
			d->player->spell_target = is_front_wall(d->player, d->map);
			if (d->player->spell_target == 0)
			{
				d->pt_running = 0;
				pthread_exit(0);
			}
		}
		while (d->player->frame < 8)
		{
			spell_anim(d->player, d->textures);
			if (d->player->frame == 7)
			{
				delete_wall(d, d->map, d->player);
			}
			usleep(100000);
		}
	}
	return (d);
}
