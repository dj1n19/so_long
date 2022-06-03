/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_foes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:44:35 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/02 15:25:14 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void place_unicorn(t_foe *unicorn, int x, int y)
{
    unicorn->pos_x = x * TILESIZE;
    unicorn->pos_y = y * TILESIZE;
    unicorn->current = unicorn->sprites_right[0];
}

static void place_dragon(t_foe *dragon, int x, int y)
{
    dragon->pos_x = x * TILESIZE;
    dragon->pos_y = y * TILESIZE;
    dragon->current = dragon->sprites_right[0];
}

void    ft_place_foes(t_datas *datas)
{
    int x;
    int y;
    int i;

    i = 0;
    x = 1;
    y = 1;
    while (y < datas->map->size_y - 1)
    {
        x = 1;
        while (x < datas->map->size_x - 1)
        {
            if (datas->map->blueprint[y][x] == 'D')
                place_dragon(datas->foes[i++], x, y);
            else if (datas->map->blueprint[y][x] == 'U')
                place_unicorn(datas->foes[i++], x, y);
            ++x;
        }
        ++y;
    }
}