/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:38 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/10 17:19:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key_hook(int keycode, t_datas *datas)
{
	if (datas->player->is_moving == 0 && datas->player->is_attacking == 0 && datas->player->is_casting == 0)
	{
		datas->keycode = keycode;
		if (keycode == LETTER_E)
			datas->player->is_attacking = 1;
		else if (keycode == NUM_1)
			datas->player->is_casting = 1;
		else if (keycode == ESC)
			ft_close(datas);
		else
			datas->player->is_moving = 1;
	}
	return (0);
}

int	ft_hook(t_datas *datas)
{
	if (datas->player->is_attacking == 1)
		ft_player_attack(datas);
	else if (datas->player->is_moving == 1)
		ft_move(datas->keycode, datas);
	else if (datas->player->is_casting == 1)
		ft_spell_cast(datas);
	datas->map->frame++;
	if (datas->map->frame == 32)
		datas->map->frame = 0;
	ft_move_foes(datas);
	ft_draw(datas);
	usleep(25000);
	return (0);
}