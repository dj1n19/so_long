/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:38 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/30 15:18:24 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key_up(int keycode, t_datas *datas)
{
	datas->keycode = -1;
	if (datas->mt_running == 1 && (keycode == SOUTH
			|| keycode == NORTH || keycode == EAST || keycode == WEST))
	{
		pthread_cancel(*datas->move_thread);
		datas->mt_running = 0;
	}
	return (0);
}

int	ft_key_down(int keycode, t_datas *datas)
{
	if (datas->pt_running == 0 && datas->mt_running == 0
		&& (keycode == 1 || keycode == 13 || keycode == 0 || keycode == 2))
	{
		datas->mt_running = 1;
		datas->keycode = keycode;
		pthread_create(datas->move_thread, datas->attr, move_player, datas);
	}
	else if (datas->pt_running == 0 && datas->mt_running == 0
		&& keycode == LETTER_E)
	{
		datas->keycode = keycode;
		datas->pt_running = 1;
		pthread_create(datas->player_thread, datas->attr,
			ft_player_attack, datas);
	}
	else if (datas->pt_running == 0 && datas->mt_running == 0
		&& keycode == NUM_1)
	{
		datas->keycode = keycode;
		datas->pt_running = 1;
		pthread_create(datas->player_thread, datas->attr, ft_spell_cast, datas);
	}
	else if (datas->pt_running == 0 && datas->mt_running == 0 && keycode == ESC)
		ft_close(datas);
	return(0);
}

int	ft_hook(t_datas *datas)
{
	if (datas->player->hp <= 0)
		ft_close(datas);
	if (datas->items == 0)
		datas->map->is_portal_open = 1;
	if (datas->map->map[datas->player->y / TILESIZE]
		[datas->player->x / TILESIZE] == 'E' && datas->map->is_portal_open)
		ft_close(datas);
	if (draw(datas) < 0)
		error_handler(E_IMG);
	usleep(25000);
	return (0);
}
