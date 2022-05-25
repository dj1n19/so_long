/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:46:54 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/25 12:46:56 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void move_unicorn_right(t_map *map, t_unicorn *unicorn)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[unicorn->pos_y][(unicorn->pos_x + 64) / 64] != '1')
    {
        unicorn_anim_right(unicorn);
    }
    else
    {
        unicorn->direction = 'L';
        unicorn->frame = 0;
        unicorn_anim_left(unicorn);
    }
}

static void move_unicorn_left(t_map *map, t_unicorn *unicorn)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[unicorn->pos_y][(unicorn->pos_x - 64) / 64] != '1')
        unicorn_anim_left(unicorn);
    else
    {
        unicorn->direction = 'R';
        unicorn->frame = 0;
        unicorn_anim_right(unicorn);
    }
}

static void move_dragon_right(t_map *map, t_dragon *dragon)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[dragon->pos_y][(dragon->pos_x + 64) / 64] != '1')
        dragon_anim_right(dragon);
    else
    {
        dragon->direction = 'L'
        dragon->frame = 0;
        dragon_anim_left(dragon);
    }
}

static void move_dragon_left(t_map *map, t_dragon *dragon)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[dragon->pos_y][(dragon->pos_x - 64) / 64] != '1')
        dragon_anim_left(dragon);
    else
    {
        dragon->direction = 'R';
        dragon->frame = 0;
        dragon_anim_right(dragon);
    }
}

void    ft_move_foes(t_datas *datas)
{
    t_unicorn   *unicorn;
    t_dragon    *dragon;

    while (*datas->unicorn)
    {
        unicorn = *datas->unicorn
        if (unicorn->direction == 'R')
            move_unicorn_right(datas->map, unicorn);
        else if (unicorn->direction == 'L')
            move_unicorn_left(datas->map, unicorn);
        ++datas->unicorn;
    }
    while (*datas->dragon)
    {
        dragon = *datas->dragon;
        if (dragon->direction == 'R')
            move_dragon_right(datas->map, dragon);
        else if (dragon->direction == 'L')
            move_dragon_left(datas->map, dragon);
        ++datas->dragon;
    }
}