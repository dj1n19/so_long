/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_cast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:33:31 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/09 14:44:43 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void spell_anim(t_player *player, t_textures *textures)
{
    player->current = textures->player_attack[player->frame];
    player->frame++;
}

static int  is_front_wall(t_player *player, t_map *map)
{
    char    **m;

    m = map->map;
    if ((player->dir == 'U' && (player->y - 64) / 64 == 0)
        || (player->dir == 'D' && (player->y + 64) / 64 == map->y - 1)
        || (player->dir == 'L' && (player->x - 64) / 64 == 0)
        || (player->dir == 'R' && (player->x + 64) / 64 == map->x - 1))
        return (0);
    if (player->dir == 'U' && m[(player->y - 64) / 64][player->x / 64] == '1')
        return ('U');
    else if (player->dir == 'D' && m[(player->y + 64) / 64][player->x / 64] == '1')
        return ('D');
    else if (player->dir == 'L' && m[player->y / 64][(player->x - 64) / 64] == '1')
        return ('L');
    else if (player->dir == 'R' && m[player->y / 64][(player->x + 64) / 64] == '1')
        return ('R');
    return (0);
}

void    draw_spell(t_img *img, t_player *p, t_textures *tex)
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

static void	delete_wall(t_map *map, t_player *player)
{
	if (player->spell_target == 'U')
		map->map[(player->y - 64) / 64][player->x / 64] = '0';
	else if (player->spell_target == 'D')
		map->map[(player->y + 64) / 64][player->x / 64] = '0';
	else if (player->spell_target == 'L')
		map->map[player->y / 64][(player->x - 64) / 64] = '0';
	else if (player->spell_target == 'R')
		map->map[player->y / 64][(player->x + 64) / 64] = '0';
}

void    ft_spell_cast(t_datas *datas)
{
    while (1)
	{
		if (datas->player->spell_target == 0)
	    {
	        datas->player->spell_target = is_front_wall(datas->player, datas->map);
	        if (datas->player->spell_target == 0)
			{
				datas->pt_running = 0;
				pthread_exit(0);
			}
		}
		while (datas->player->frame < 8)
		{
			spell_anim(datas->player, datas->textures);
			if (datas->player->frame == 7)
			{
	    		delete_wall(datas->map, datas->player);
				datas->player->spell_target = 0;
				datas->player->frame = 0;
				datas->pt_running = 0;
				pthread_exit(0);
			}
			usleep(100000);
		}
	}
}
