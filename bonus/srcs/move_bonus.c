/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:12:24 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:32:39 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_move(int keycode, t_datas *datas)
{
	ft_move_player(keycode, datas);
	ft_move_foes(datas);
	if (datas->map->blueprint[datas->player->pos_y / TILESIZE]
			[datas->player->pos_x / TILESIZE] == 'C')
	{
		datas->map->blueprint[datas->player->pos_y / TILESIZE]
			[datas->player->pos_x / TILESIZE] = '0';
		datas->collected--;
		if (datas->collected == 0)
			datas->map->portal_open = 1;
	}
	else if (datas->map->blueprint[datas->player->pos_y / TILESIZE]
			[datas->player->pos_x / TILESIZE] == 'E'
			&& datas->map->portal_open == 1)
		ft_close(datas);
	return (0);
}
