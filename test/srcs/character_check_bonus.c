/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:34:18 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/02 15:24:56 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_check_unicorns(t_map *map)
{
	int	x;
	int	y;
	int	unicorn_count;

	unicorn_count = 0;
	y = 1;
	while (y < map->size_y - 1)
	{
		x = 1;
		while (x < map->size_x - 1)
		{
			if (map->blueprint[y][x] == 'U')
				unicorn_count++;
			x++;
		}
		y++;
	}
	return (unicorn_count);
}

int	ft_check_dragons(t_map *map)
{
	int	x;
	int	y;
	int	dragon_count;

	dragon_count = 0;
	y = 1;
	while (y < map->size_y - 1)
	{
		x = 1;
		while (x < map->size_x - 1)
		{
			if (map->blueprint[y][x] == 'D')
				dragon_count++;
			x++;
		}
		y++;
	}
	return (dragon_count);
}

void	ft_check_player(t_datas *datas)
{
	int	x;
	int	y;

	y = 1;
	while (y < datas->map->size_y - 1)
	{
		x = 1;
		while (x < datas->map->size_x - 1)
		{
			if (datas->map->blueprint[y][x] == 'P')
			{
				datas->player->pos_x = x * TILESIZE;
				datas->player->pos_y = y * TILESIZE;
				datas->player->current = datas->player->player_right[0];
				return ;
			}
		}
	}
	ft_e_map(5, datas);
}
