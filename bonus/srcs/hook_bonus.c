/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:38 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:31:40 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key_hook(int keycode, t_datas *datas)
{
	datas->keycode = keycode;
	return (0);
}

int	ft_hook(t_datas *datas)
{
	if (datas->keycode == ESC)
		ft_close(datas);
	if (datas->keycode == LETTER_E)
		ft_player_attack(datas);
	else if (datas->keycode != -1)
		ft_move(datas->keycode, datas);
	usleep(150000);
	return (0);
}