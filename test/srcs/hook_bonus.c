/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:38 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/10 16:31:21 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key_up(int keycode, t_datas *datas)
{
	datas->keycode = -1;
	if (keycode == SOUTH || keycode == NORTH || keycode == EAST || keycode == WEST)
	{
		pthread_cancel(*datas->move_thread);
		datas->mt_running = 0;
		datas->player->frame = 0;
		printf("THREAD MT: cancel\n");
	}
}

int	ft_key_down(int keycode, t_datas *datas)
{
	if (keycode == 1 || keycode == 13 || keycode == 0 || keycode == 2)
	{
		if (datas->mt_running == 0 && datas->pt_running == 0)
		{
			datas->mt_running = 1;
			datas->keycode = keycode;
			pthread_create(datas->move_thread, datas->attr, ft_move_player, datas);
			printf("THREAD MT: running\n");
		}
	}
	else if (keycode == LETTER_E)
	{
		if (datas->pt_running == 0)
		{
			datas->keycode = keycode;
			datas->pt_running = 1;
			pthread_create(datas->player_thread, datas->attr, ft_player_attack, datas);
			printf("THREAD PT: running\n");
		}
	}
	else if (keycode == NUM_1)
	{
		if (datas->pt_running == 0)
		{
			datas->keycode = keycode;
			datas->pt_running = 1;
			pthread_create(datas->player_thread, datas->attr, ft_spell_cast, datas);
			printf("THREAD PT: running\n");
		}
	}
	else if (keycode == ESC)
		ft_close(datas);
}

int	ft_hook(t_datas *datas)
{
	// if (datas->ft_running == 0)
	// 	pthread_create(datas->foe_thread, datas->attr, ft_move_foes, datas);
	// if (datas->it_running == 0)
	// 	pthread_create(datas->item_thread, datas->attr, test_item_anim, datas);
	if (datas->remaining_items == 0)
		datas->map->portal_open = 1;
	ft_draw(datas);
	usleep(25000);
}
