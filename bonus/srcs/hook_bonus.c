/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:38 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/02 13:21:31 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key_hook(int keycode, t_datas *datas)
{
	if (datas->is_moving == 0)
	{
		datas->keycode = keycode;
		datas->is_moving = 1;
	}
	return (0);
}

int	ft_hook(t_datas *datas)
{
	if (datas->keycode == ESC)
		ft_close(datas);
	if (datas->keycode == LETTER_E)
		ft_player_attack(datas);
	else if (datas->is_moving == 1)
		ft_move(datas->keycode, datas);
	if (datas->map->frame == 8)
		datas->map->frame = 0;
	ft_move_foes(datas);
	ft_draw(datas);
	datas->map->frame++;
	usleep(25000);
	return (0);
}