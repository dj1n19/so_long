/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:46:54 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/04 17:00:25 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	foe_anim_right(t_foe *foe)
{
	foe->pos_x += 8;
	foe->current = foe->sprites_right[foe->frame];
	foe->frame++;
}

static void	foe_anim_left(t_foe *foe)
{
	foe->pos_x -= 8;
	foe->current = foe->sprites_left[foe->frame];
	foe->frame++;
}

static void move_foe_right(t_map *map, t_foe *foe)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[foe->pos_y / 64][(foe->pos_x + 64) / 64] == '1')
    {
        foe->direction = 'L';
        foe->frame = 0;
        foe_anim_left(foe);
    }
    else
    {
        if (foe->frame == 8)
            foe->frame = 0;
        foe_anim_right(foe);
    }
}

static void move_foe_left(t_map *map, t_foe *foe)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[foe->pos_y / 64][((foe->pos_x - 64) / 64) + 1] == '1')
    {
        foe->direction = 'R';
        foe->frame = 0;
        foe_anim_right(foe);
    }
    else
    {
        if (foe->frame == 8)
            foe->frame = 0;
        foe_anim_left(foe);
    }
}

void    ft_move_foes(t_datas *datas)
{
    t_foe   *foe;
    int     i;

	datas->ft_running = 1;
    i = 0;
    ft_foe_attack(datas);
    while (datas->foes[i])
    {
        foe = datas->foes[i];
        if (foe->is_dead == 1)
            ft_foe_death_anim(foe);
        if (foe->direction == 'R' && foe->is_attacking == 0 && foe->is_dead == 0)
            move_foe_right(datas->map, foe);
        else if (foe->direction == 'L' && foe->is_attacking == 0 && foe->is_dead == 0)
            move_foe_left(datas->map, foe);
        ++i;
    }
	usleep(50000);
	datas->ft_running = 0;
	pthread_exit(0);
}
