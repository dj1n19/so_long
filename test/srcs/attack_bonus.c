/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/07 15:47:06 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void foe_anim_attack(t_foe *foe)
{
    if (foe->frame == 8)
        foe->frame = 0;
    if (foe->direction == 'R')
        foe->current = foe->sprites_attack_right[foe->frame];
    else if (foe->direction == 'L')
        foe->current = foe->sprites_attack_left[foe->frame];
    foe->frame++;

}

static void player_anim_attack(t_player *player)
{
    // if (player->frame == 8)
    // {
    //     player->frame = 0;
    //     player->is_attacking = 0;
    //     return ;
    // }
    player->current = player->player_attack[player->frame];
    player->frame++;

}

static int     is_at_range(t_foe *f, t_player *p)
{
    // if (f->is_dead == 0 && ((f->pos_y == p->pos_y && f->pos_x == p->pos_x)
    //     || (f->pos_y - 64 == p->pos_y && f->pos_x == p->pos_x)
    //     || (f->pos_y + 64 == p->pos_y && f->pos_x == p->pos_x)
    //     || (f->pos_y == p->pos_y && f->pos_x - 64 == p->pos_x)
    //     || (f->pos_y == p->pos_y && f->pos_x + 64 == p->pos_x)))
    //     return (1);
    // return (0);
	int	dist_x;
	int	dist_y;

	if (f->is_dead == 0)
	{
		dist_x = f->pos_x - p->pos_x;
		dist_y = f->pos_y - p->pos_y;
		if (dist_x < 0)
			dist_x = -dist_x;
		if (dist_y < 0)
			dist_y = -dist_y;
		//printf("distance: [%p] -> (%d, %d)\n", f, dist_x, dist_y);
		if (dist_x < TILESIZE && dist_y < TILESIZE)
			return (1);
	}
	return (0);
}

void    ft_player_attack(t_datas *datas)
{
    int i;
	void *save;

    i = 0;
	datas->player->is_attacking = 1;
	save = datas->player->current;
	while (datas->player->frame < 8)
	{
    	while (!datas->player->target && datas->foes[i])
    	{
			datas->player->target = NULL;
        	if (is_at_range(datas->foes[i], datas->player))
        	{
            	datas->player->target = datas->foes[i];
            	break ;
        	}
        	i++;
    	}
    //printf("[%p]\n", datas->player->target);
    //printf("<< %p >>\n", datas->foes[0]);
    	if (datas->player->target && datas->player->frame == 7)
    	{
        	datas->player->target->hp -= datas->player->damage;
        	if (datas->player->target->hp <= 0)
        	{
				datas->player->is_attacking = 0;
            	datas->player->target->is_dead = 1;
            	datas->player->target->frame = 0;
            	datas->player->target->is_attacking = 0;
            	datas->player->target = NULL;
				datas->pt_running = 0;
				pthread_exit(0);
        	}
    	}
		player_anim_attack(datas->player);
		//datas->player->frame++;
		//printf("\e[31mHP = %d - %d\e[0m\n", datas->player->target->hp, datas->player->frame);
		usleep(100000);
	}
	datas->player->frame = 0;
	datas->player->current = save;
	datas->player->is_attacking = 0;
	datas->pt_running = 0;
}

void    ft_foe_attack(t_datas *datas)
{
    int     i;

    i = 0;
    while (datas->foes[i])
    {
        if (is_at_range(datas->foes[i], datas->player) && datas->foes[i]->is_dead == 0)
        {
            datas->foes[i]->is_attacking = 1;
            if (datas->foes[i]->frame == 8)
                datas->player->hp -= datas->foes[i]->damage;
            foe_anim_attack(datas->foes[i]);
        }
        else
            datas->foes[i]->is_attacking = 0;
        i++;
    }
}
