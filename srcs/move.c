/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:12:24 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 16:03:39 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	move_north(t_datas *datas)
{
	if (datas->map->blueprint[datas->player->pos_y - 1][datas->player->pos_x]
			!= '1')
	{
		datas->player->pos_y -= 1;
		datas->move_count++;
	}
	datas->player->current = datas->player->player[0];
}

static void	move_east(t_datas *datas)
{
	if (datas->map->blueprint[datas->player->pos_y][datas->player->pos_x + 1]
			!= '1')
	{
		datas->player->pos_x += 1;
		datas->move_count++;
	}
	datas->player->current = datas->player->player[1];
}

static void	move_south(t_datas *datas)
{
	if (datas->map->blueprint[datas->player->pos_y + 1][datas->player->pos_x]
			!= '1')
	{
		datas->player->pos_y += 1;
		datas->move_count++;
	}
	datas->player->current = datas->player->player[2];
}

static void	move_west(t_datas *datas)
{
	if (datas->map->blueprint[datas->player->pos_y][datas->player->pos_x - 1]
			!= '1')
	{
		datas->player->pos_x -= 1;
		datas->move_count++;
	}
	datas->player->current = datas->player->player[3];
}

int	ft_move(int keycode, t_datas *datas)
{
	if (keycode == NORTH)
		move_north(datas);
	else if (keycode == EAST)
		move_east(datas);
	else if (keycode == SOUTH)
		move_south(datas);
	else if (keycode == WEST)
		move_west(datas);
	if (datas->map->blueprint[datas->player->pos_y][datas->player->pos_x]
			== 'C')
	{
		datas->map->blueprint[datas->player->pos_y][datas->player->pos_x] = '0';
		datas->collected--;
		if (datas->collected == 0)
			datas->map->portal_open = 1;
	}
	ft_printf("\e[35mmovement count: %d\n\e[0m", datas->move_count);
	if (datas->map->blueprint[datas->player->pos_y][datas->player->pos_x]
			== 'E' && datas->map->portal_open == 1)
		ft_close(datas);
	return (0);
}
