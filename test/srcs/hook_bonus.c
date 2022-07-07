/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:38:38 by bgenie            #+#    #+#             */
/*   Updated: 2022/07/07 19:30:16 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_key_hook(int keycode, t_datas *datas)
{
	printf("KEYCODE: %d\n", keycode);
	printf("\e[31mpt_running->%d\nis_moving->%d\nis_attacking->%d\nis_casting->%d\n",datas->pt_running, datas->player->is_moving, datas->player->is_attacking, datas->player->is_casting);
	if (datas->pt_running == 0 && datas->player->is_moving == 0
		&& datas->player->is_attacking == 0
		&& datas->player->is_casting == 0)
	{
		datas->pt_running = 1;
		if (keycode == 1 || keycode == 13 || keycode == 0 || keycode == 2)
		{
			datas->keycode = keycode;
			pthread_create(datas->move_thread, datas->attr, ft_move_player, datas);
		}
		else if (keycode == LETTER_E)
			pthread_create(datas->player_thread, datas->attr, ft_player_attack, datas);
		else if (keycode == NUM_1)
			pthread_create(datas->player_thread, datas->attr, ft_spell_cast, datas);

		else if (keycode == ESC)
			ft_close(datas);
	}
	return (0);
}

static void test_item_anim(t_datas *datas)
{
	datas->it_running = 1;
	datas->map->frame++;
	if (datas->map->frame > 7)
		datas->map->frame = 0;
	usleep(250000);
	datas->it_running = 0;
	pthread_exit(0);
}

int	ft_hook(t_datas *datas)
{
	if (datas->ft_running == 0)
		pthread_create(datas->foe_thread, datas->attr, ft_move_foes, datas);
	if (datas->it_running == 0)
		pthread_create(datas->item_thread, datas->attr, test_item_anim, datas);
	if (datas->collected == 0)
		datas->map->portal_open = 1;
	ft_draw(datas);
	usleep(1000);
}
