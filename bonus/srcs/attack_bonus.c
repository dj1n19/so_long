/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/03 14:51:36 by bgenie           ###   ########.fr       */
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
        player->frame = 0;
    player->current = player->player_attack[player->frame];
    player->frame++;
}

static int     is_at_range(t_foe *f, t_player *p)
{
    if ((f->pos_y == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y - 64 == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y + 64 == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y == p->pos_y && f->pos_x - 64 == p->pos_x)
        || (f->pos_y == p->pos_y && f->pos_x + 64 == p->pos_x))
        return (1);
    return (0);
}

void    ft_player_attack(t_datas *datas)
{
    t_foe   *target;

    while (*datas->foes)
    {
        if (is_at_range(*datas->foes, datas->player))
        {
            target = *datas->foes;
            break;
        }
        datas->foes++;
    }
    player_anim_attack(datas->player);
    if (target)
    {
        target->hp -= datas->player->damage;
        /*if (target->hp <= 0)
            ft_foe_death(datas->foes, target);*/
    }
}

void    ft_foe_attack(t_datas *datas)
{
    int     i;

    i = 0;
    while (datas->foes[i])
    {
        if (is_at_range(datas->foes[i], datas->player))
        {
            datas->foes[i]->is_attacking = 1;
            if (datas->foes[i]->frame == 8)
                datas->player->hp -= datas->foes[i]->damage;
            if (datas->foes[i]->type == 'U')
                foe_anim_attack(datas->foes[i]);
            else if (datas->foes[i]->type == 'D')
                foe_anim_attack(datas->foes[i]);
            if (datas->player->hp <= 0)
            {
                mlx_string_put(datas->mlx, datas->win, datas->map->size_x / 2
                        * 64, datas->map->size_y / 2 * 64, 16711680, "WASTED");
                ft_close(datas);
            }
        }
        else
            datas->foes[i]->is_attacking = 0;
        i++;
    }
}