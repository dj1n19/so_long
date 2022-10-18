/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_check_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:34:18 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/18 17:17:30 by bgenie           ###   ########.fr       */
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
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (map->map[y][x] == 'U')
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
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (map->map[y][x] == 'D')
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
	while (y < datas->map->y - 1)
	{
		x = 1;
		while (x < datas->map->x - 1)
		{
			if (datas->map->map[y][x] == 'P')
			{
				if (!datas->player->current)
				{
					datas->player->x = x * TILESIZE;
					datas->player->y = y * TILESIZE;
					datas->player->current = datas->textures->player_right[0];
				}
				else
					datas->map->map[y][x] == '0';
			}
			++x;
		}
		++y;
	}
	if (!datas->player->current)
		exit(EXIT_FAILURE);
}
