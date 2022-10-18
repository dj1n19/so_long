/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/07 18:12:36 by bgenie           ###   ########.fr       */
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

static void	kill_target(t_player *player)
{
	player->is_attacking = 0;
	player->target->is_dead = 1;
	player->target->is_attacking = 0;
	player->target->frame = 0;
	player->target = NULL;
}

void    ft_player_attack(t_datas *datas)
{
    int i;
	void *save;

	save = datas->player->current;
	datas->player->is_attacking = 1;
	while (1)
    {
		i = 0;	
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
		player_anim_attack(datas->player);
		if (datas->player->frame > 7)
		{
			if (datas->player->target)
				datas->player->target->hp -= datas->player->damage;
			if (datas->player->target && datas->player->target->hp <= 0)
			{
				datas->player->is_attacking = 0;
				datas->player->target->is_dead = 1;
				datas->player->target->is_attacking = 0;
				datas->player->target->frame = 0;
				datas->player->target = NULL;
			}
			datas->pt_running = 0;
			datas->player->current = save;
			datas->player->frame = 0;
			printf("THREAD PT: cancel\n");
			pthread_cancel(*datas->player_thread);
		}
		usleep(100000);
	}
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
