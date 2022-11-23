/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:14:09 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/23 12:04:14 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static int	check_edges(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while ((y == map->y - 1 && x < map->x) || (y == 0 && x < map->x))
		{
			if (map->map[y][x] != '1')
				return (0);
			++x;
		}
		if (y != map->y - 1 && y != 0 && map->map[y][0] != '1'
			&& map->map[y][map->x - 1] != '1')
			return (0);
		++y;
	}
	return (1);
}

static int	check_items(t_map *map, int *items)
{
	int	item_count;
	int	x;
	int	y;

	y = 1;
	item_count = 0;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (map->map[y][x] == 'C' || map->map[y][x] == 'G'
					|| map->map[y][x] == 'K' || map->map[y][x] == 'A')
				item_count++;
			x++;
		}
		y++;
	}
	*items = item_count;
	return (item_count);
}

static int	check_exit(t_map *map)
{
	int	exit_count;
	int	x;
	int	y;

	y = 1;
	exit_count = 0;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (map->map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	return (exit_count);
}

static int	check_start(t_map *map)
{
	int	start_count;
	int	x;
	int	y;

	y = 1;
	start_count = 0;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			if (map->map[y][x] == 'P')
				start_count++;
			x++;
		}
		y++;
	}
	return (start_count);
}

int	map_check(t_map *map, int *items)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] != '0' && map->map[y][x] != '1'
				&& map->map[y][x] != 'P' && map->map[y][x] != 'E'
				&& map->map[y][x] != 'C' && map->map[y][x] != 'K'
				&& map->map[y][x] != 'G' && map->map[y][x] != 'A'
				&& map->map[y][x] != 'U' && map->map[y][x] != 'D'
				&& map->map[y][x] != '\n')
				return (0);
			++x;
		}
		++y;
	}
	if (check_start(map) == 1 && check_items(map, items) > 0
		&& check_exit(map) == 1 && check_edges(map) > 0)
		return (1);
	return (0);
}
