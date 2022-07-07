/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:43:53 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/15 15:39:47 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_north(t_datas *datas)
{
	if (datas->map->blueprint[(datas->player->pos_y - 64) / 64]
			[datas->player->pos_x / 64] == '1' && datas->player->frame == 0)
		datas->player->is_moving = 0;
	else
	{
		if (datas->player->frame == 8)
		{
			datas->move_count++;
			ft_printf("\e[35mmovement count: %d\n\e[0m", datas->move_count);
			datas->player->is_moving = 0;
			datas->player->frame = 0;
		}
		else
			ft_player_anim_north(datas->player);
	}
}

static void	move_east(t_datas *datas)
{
	if (datas->map->blueprint[datas->player->pos_y / 64]
			[(datas->player->pos_x + 64) / 64] == '1'
			&& datas->player->frame == 0)
		datas->player->is_moving = 0;
	else
	{
		if (datas->player->frame == 8)
		{
			datas->move_count++;
			//ft_printf("\e[35mmovement count: %d\n\e[0m", datas->move_count);
			datas->player->is_moving = 0;
			datas->player->frame = 0;
		}
		else
			ft_player_anim_east(datas->player);
	}
}

static void	move_south(t_datas *datas)
{
	if (datas->map->blueprint[(datas->player->pos_y + 64) / 64]
			[datas->player->pos_x / 64] == '1' && datas->player->frame == 0)
		datas->player->is_moving = 0;
	else
	{
		if (datas->player->frame == 8)
		{
			datas->move_count++;
			ft_printf("\e[35mmovement count: %d\n\e[0m", datas->move_count);
			datas->player->is_moving = 0;
			datas->player->frame = 0;
		}
		else
			ft_player_anim_south(datas->player);
	}
}

static void	move_west(t_datas *datas)
{
	if (datas->map->blueprint[datas->player->pos_y / 64]
			[(datas->player->pos_x - 64) / 64] == '1'
			&& datas->player->frame == 0)
		datas->player->is_moving = 0;
	else
	{
		if (datas->player->frame == 8)
		{
			datas->move_count++;
			ft_printf("\e[35mmovement count: %d\n\e[0m", datas->move_count);
			datas->player->is_moving = 0;
			datas->player->frame = 0;
		}
		else
			ft_player_anim_west(datas->player);
	}
}

void    ft_move_player(int keycode, t_datas *datas)
{
    if (keycode == NORTH)
		move_north(datas);
	else if (keycode == EAST)
		move_east(datas);
	else if (keycode == SOUTH)
		move_south(datas);
	else if (keycode == WEST)
		move_west(datas);
	printf("(%d, %d)\n", datas->player->pos_x, datas->player->pos_y);
}
