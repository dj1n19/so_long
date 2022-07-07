/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/16 15:24:44 by bgenie           ###   ########.fr       */
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
    if (player->frame == 8)
    {
        player->frame = 0;
        player->is_attacking = 0;
        return ;
    }
    player->current = player->player_attack[player->frame];
    player->frame++;
    
}

static int     is_at_range(t_foe *f, t_player *p)
{
    if (f->is_dead == 0 && ((f->pos_y == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y - 64 == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y + 64 == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y == p->pos_y && f->pos_x - 64 == p->pos_x)
        || (f->pos_y == p->pos_y && f->pos_x + 64 == p->pos_x)))
        return (1);
    return (0);
}

void    ft_player_attack(t_datas *datas)
{
    int i;
    i = 0;
    printf(">> %p <<\n", datas->foes[0]);
    while (datas->foes[i])
    {
        if (is_at_range(datas->foes[i], datas->player))
        {
            datas->player->target = datas->foes[i];
            break ;
        }
        else
            datas->player->target = NULL;
        i++;
    }
    printf("[%p]\n", datas->player->target);
    printf("<< %p >>\n", datas->foes[0]);
    if (datas->player->target && datas->player->frame == 8)
    {
        datas->player->target->hp -= datas->player->damage;
        printf("\e[31mHP = %d\e[0m\n", datas->player->target->hp);
        if (datas->player->target->hp <= 0)
        {
            datas->player->target->is_dead = 1;
            datas->player->target->frame = 0;
            datas->player->target->is_attacking = 0;
            datas->player->target = NULL;

        }
    }
    player_anim_attack(datas->player);
    
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