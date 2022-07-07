/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_cast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:33:31 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/07 16:41:16 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void spell_anim(t_player *player)
{
    player->current = player->player_attack[player->frame];
    player->frame++;
}

static int  is_front_wall(t_player *player, t_map *map)
{
    char    **bp;

    bp = map->blueprint;
    if ((player->dir == 'U' && (player->pos_y - 64) / 64 == 0)
        || (player->dir == 'D' && (player->pos_y + 64) / 64 == map->size_y - 1)
        || (player->dir == 'L' && (player->pos_x - 64) / 64 == 0)
        || (player->dir == 'R' && (player->pos_x + 64) / 64 == map->size_x - 1))
        return (0);
    if (player->dir == 'U' && bp[(player->pos_y - 64) / 64][player->pos_x / 64] == '1')
        return ('U');
    else if (player->dir == 'D' && bp[(player->pos_y + 64) / 64][player->pos_x / 64] == '1')
        return ('D');
    else if (player->dir == 'L' && bp[player->pos_y / 64][(player->pos_x - 64) / 64] == '1')
        return ('L');
    else if (player->dir == 'R' && bp[player->pos_y / 64][(player->pos_x + 64) / 64] == '1')
        return ('R');
    return (0);
}

void    ft_draw_spell(t_datas *datas)
{
    printf(">>(%d, %d)\n", datas->player->pos_x / 64, datas->player->pos_y / 64);
    if (datas->player->spell_target == 'U')
        mlx_put_image_to_window(datas->mlx, datas->win, datas->player->spell[datas->player->frame], datas->player->pos_x, datas->player->pos_y - 64);
    else if (datas->player->spell_target == 'D')
        mlx_put_image_to_window(datas->mlx, datas->win, datas->player->spell[datas->player->frame], datas->player->pos_x, datas->player->pos_y + 64);
    else if (datas->player->spell_target == 'L')
        mlx_put_image_to_window(datas->mlx, datas->win, datas->player->spell[datas->player->frame], datas->player->pos_x - 64, datas->player->pos_y);
    else if (datas->player->spell_target == 'R')
        mlx_put_image_to_window(datas->mlx, datas->win, datas->player->spell[datas->player->frame], datas->player->pos_x + 64, datas->player->pos_y);
	else
		datas->player->spell_target = 0;
	printf("spell:[%p] %d\n", datas->player->spell[datas->player->frame], datas->player->frame);
}

void    ft_spell_cast(t_datas *datas)
{
	datas->player->is_casting = 1;
    if (datas->player->spell_target == 0)
    {
        datas->player->spell_target = is_front_wall(datas->player, datas->map);
        printf(">>>%c\n", datas->player->spell_target);
        if (datas->player->spell_target == 0)
		{
			datas->player->is_casting = 0;
			datas->pt_running = 0;
            return ;
		}
	}
	while (datas->player->is_casting == 1 && datas->player->frame < 8)
	{
		if (datas->player->frame == 7)
    	{
        	if (datas->player->spell_target == 'U')
            	datas->map->blueprint[(datas->player->pos_y - 64) / 64][datas->player->pos_x / 64] = '0';
        	else if (datas->player->spell_target == 'D')
            	datas->map->blueprint[(datas->player->pos_y + 64) / 64][datas->player->pos_x / 64] = '0';
        	else if (datas->player->spell_target == 'L')
            	datas->map->blueprint[datas->player->pos_y / 64][(datas->player->pos_x - 64) / 64] = '0';
        	else if (datas->player->spell_target == 'R')
            	datas->map->blueprint[datas->player->pos_y / 64][(datas->player->pos_x + 64) / 64] = '0';
    	}
    	spell_anim(datas->player);
		usleep(100000);
	}
	datas->player->spell_target = 0;
	datas->player->is_casting = 0;
	datas->player->frame = 0;
	datas->pt_running = 0;
}
