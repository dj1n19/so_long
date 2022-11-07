/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:14:09 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/05 14:35:24 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_edge(char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y][x] != 10)
	{
		if (map[y][x++] != '1')
			return (2);
	}
	while (map[y])
	{
		if (!map[y + 1])
		{
			x = 0;
			while (map[y][x] != 10)
			{
				if (map[y][x++] != '1')
					return (2);
			}
		}
		if (map[y][0] != '1' || map[y++][x - 1] != '1')
			return (2);
	}
	return (0);
}

static int	ft_check_item(char **map)
{
	int	item_count;
	int	x;
	int	y;

	y = 1;
	item_count = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				item_count++;
			x++;
		}
		y++;
	}
	return (item_count);
}

static int	ft_check_exit(char **map)
{
	int	exit_count;
	int	x;
	int	y;

	y = 1;
	exit_count = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				exit_count++;
			x++;
		}
		y++;
	}
	return (exit_count);
}

static int	ft_check_start(char **map)
{
	int	start_count;
	int	x;
	int	y;

	y = 1;
	start_count = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				start_count++;
			x++;
		}
		y++;
	}
	return (start_count);
}

int	ft_check_map(t_datas *datas)
{
	int	items;

	if (ft_check_edge(datas->map->blueprint))
		ft_e_map(2, datas);
	items = ft_check_item(datas->map->blueprint);
	if (!items)
		ft_e_map(3, datas);
	if (!ft_check_exit(datas->map->blueprint))
		ft_e_map(4, datas);
	if (!ft_check_start(datas->map->blueprint))
		ft_e_map(5, datas);
	return (items);
}
