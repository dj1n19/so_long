/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_foes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:44:35 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/23 18:44:37 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void place_unicorns(t_unicorn **unicorns, t_map *map)
{
    int x;
    int y;
    int i;

    i = 0;
    y = 1;
    while (y < map->size_y - 1)
    {
        x = 0;
        while (x < map->size_x - 1)
        {
            if (map->blueprint[y][x] == 'U')
            {
                unicorns[i]->pos_x = x * TILESIZE;
                unicorns[i]->pos_y = y * TILESIZE;
                i++;
            }
            x++;
        }
        y++;
    }
}

static void place_dragons(t_dragon **dragons, t_map *map)
{
    int x;
    int y;
    int i;

    i = 0;
    y = 1;
    while (y < map->size_y - 1)
    {
        x = 1;
        while (y < map->size_x - 1)
        {
            if (map->blueprint[y][x] == 'D')
            {
                dragons[i]->pos_x = x * TILESIZE;
                dragons[i]->pos_y = y * TILESIZE;
                i++;
            }
            x++;
        }
        y++;
    }
}

void    ft_place_foes(t_datas *datas)
{
    place_unicorns(datas->unicorns, datas->map);
    place_dragons(datas->dragons, datas->map);
}