/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/25 15:02:08 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int     is_at_range(t_foe *f, t_player *p)
{
    if ((f->pos_y == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y - 64 == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y + 64 == p->pos_y && f->pos_x == p->pos_x)
        || (f->pos_y == p->pos_y && f->pos_x - 64 == p->pos_x)
        || (f->pos_y == p->pos_y && f->pos_x + 64 == p->pos_x))
        return (1);
    return (0);
}

void    ft_player_attack(t_datas *datas, t_foe *target)
{
    datas->player->current = datas->player->attack;
    target->hp -= datas->player->damage;
    if (target->hp <= 0)
        ft_foe_death(datas->foes, target);
}

void    ft_foe_attack(t_datas *datas)
{
    int     i;

    i = 0;
    while (datas->foes[i])
    {
        if (is_at_range(datas->foes[i], datas->player))
        {
            if (datas->foes[i]->type == 'U')
                ft_unicorn_anim_attack(datas->foes[i]);
            else if (datas->foes[i]->type == 'D')
                ft_dragon_anim_attack(datas->foes[i]);
            if (datas->foes[i]->frame == 8)
                datas->player->hp -= datas->foes[i]->damage;
            if (datas->player->hp <= 0)
            {
                mlx_string_put(datas->mlx, datas->win,
                    datas->map->size_x / 2 * TILESIZE,
                    datas->map->size_y / 2 * TILESIZE,
                    0x00ff0000, "WASTED");
                ft_close(datas);
            }
        }
    }
}