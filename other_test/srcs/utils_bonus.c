/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:11:32 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/11 12:22:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	loot_item(t_datas *datas)
{
	char		**map;
	int			x;
	int			y;

	map = datas->map->map;
	x = datas->player->x;
	y = datas->player->y;
	if (map[(y + 32) / 64][(x + 32) / 64] == 'C'
		|| map[(y + 32) / 64][(x + 32) / 64] == 'G'
		|| map[(y + 32) / 64][(x + 32) / 64] == 'K'
		|| map[(y + 32) / 64][(x + 32) / 64] == 'A')
	{
		--datas->items;
		map[(y + 32) / 64][(x + 32) / 64] = '0';
	}
}
