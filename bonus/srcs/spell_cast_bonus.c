/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell_cast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:33:31 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/15 16:43:34 by bgenie           ###   ########.fr       */
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
    printf("[%p]\n", player->current);
    printf("[%p]\n", player->player_down[0]);
    printf("[%p]\n", player->player_down[1]);
    printf("[%p]\n", player->player_down[2]);
    printf("[%p]\n", player->player_down[3]);
    printf("[%p]\n", player->player_down[4]);
    printf("[%p]\n", player->player_down[5]);
    printf("[%p]\n", player->player_down[6]);
    printf("[%p]\n", player->player_down[7]);
    printf("%d\n", player->frame);

    char    **bp;

    bp = map->blueprint;
    if ((player->current == player->player_up[7] && (player->pos_y - 64) / 64 == 0)
        || (player->current == player->player_down[7] && (player->pos_y + 64) / 64 == map->size_y - 1)
        || (player->current == player->player_left[7] && (player->pos_x - 64) / 64 == 0)
        || (player->current == player->player_right[7] && (player->pos_x + 64) / 64 == map->size_x - 1))
        return (0);
    if (player->current == player->player_up[7] && bp[(player->pos_y - 64) / 64][player->pos_x / 64] == '1')
        return ('U');
    else if (player->current == player->player_down[7] && bp[(player->pos_y + 64) / 64][player->pos_x / 64] == '1')
        return ('D');
    else if (player->current == player->player_left[7] && bp[player->pos_y / 64][(player->pos_x - 64) / 64] == '1')
        return ('L');
    else if (player->current == player->player_right[7] && bp[player->pos_y / 64][(player->pos_x + 64) / 64] == '1')
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
}

void    ft_spell_cast(t_datas *datas)
{
    if (datas->player->spell_target == 0)
    {
        datas->player->spell_target = is_front_wall(datas->player, datas->map);
        printf(">>%c\n", datas->player->spell_target);
        if (datas->player->spell_target == 0)
        {
            datas->player->is_casting = 0;
            return ;
        }
    }
    else if (datas->player->frame == 8)
    {
        if (datas->player->spell_target == 'U')
            datas->map->blueprint[(datas->player->pos_y - 64) / 64][datas->player->pos_x / 64] = '0';
        else if (datas->player->spell_target == 'D')
            datas->map->blueprint[(datas->player->pos_y + 64) / 64][datas->player->pos_x / 64] = '0';
        else if (datas->player->spell_target == 'L')
            datas->map->blueprint[datas->player->pos_y / 64][(datas->player->pos_x - 64) / 64] = '0';
        else if (datas->player->spell_target == 'R')
            datas->map->blueprint[datas->player->pos_y / 64][(datas->player->pos_x + 64) / 64] = '0';
        datas->player->spell_target = 0;
        datas->player->is_casting = 0;
        datas->player->frame = 0;
        return ;
    }
    spell_anim(datas->player);
}