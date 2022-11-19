/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:12:52 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 15:19:54 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

static unsigned long	get_exit(t_map *map)
{
	unsigned int	x_exit;
	unsigned int	y_exit;
	unsigned long	exit_pos;

	y_exit = 1;
	while (y_exit < (unsigned)map->size_y - 1)
	{
		x_exit = 1;
		while (x_exit < (unsigned)map->size_x - 1)
		{
			if (map->map[y_exit][x_exit] == 'E')
			{
				exit_pos = ((unsigned long)y_exit << 32);
				exit_pos += (unsigned long)x_exit;
				return (exit_pos);
			}
			++x_exit;
		}
		++y_exit;
	}
	return (0);
}

static unsigned int	calc_cost(unsigned long exit_pos,
	unsigned int x, unsigned int y)
{
	unsigned int	dist;

	if ((unsigned int)(exit_pos >> 32) > y)
		dist = (unsigned int)(exit_pos >> 32) - y;
	else
		dist = y - (unsigned int)(exit_pos >> 32);
	if ((unsigned int)exit_pos > x)
		dist += ((unsigned int)(exit_pos)) - x;
	else
		dist += x - ((unsigned int)(exit_pos));
	return (dist);
}

static unsigned int	**get_cost_map(t_map *map, t_map *map_cpy)
{
	unsigned long	exit_pos;
	unsigned int	x;
	unsigned int	y;
	unsigned int	**cost_map;

	cost_map = (unsigned **) malloc(sizeof(unsigned *) * map->size_y);
	if (!cost_map)
		return (NULL);
	exit_pos = get_exit(map);
	y = -1;
	while (++y < (unsigned)map->size_y)
	{
		x = -1;
		cost_map[y] = (unsigned int *) malloc(sizeof(unsigned) * map->size_x);
		if (!cost_map[y])
		{
			free_all(map_cpy, cost_map, NULL);
			return (NULL);
		}
		while (++x < (unsigned)map->size_x)
				cost_map[y][x] = calc_cost(exit_pos, x, y);
	}
	return (cost_map);
}

static t_map	*copy_map(t_map *map)
{
	t_map	*map_cpy;
	int		y;
	int		x;

	map_cpy = create_map_cpy(map);
	if (!map_cpy)
		return (NULL);
	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		map_cpy->map[y] = (char *) malloc(sizeof(char) * map->size_x);
		if (!map_cpy->map[y])
		{
			free_all(map_cpy, NULL, NULL);
			return (NULL);
		}
		while (x < map->size_x)
		{
			map_cpy->map[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
	return (map_cpy);
}

int	pathfinding(t_datas *datas, t_map *map, unsigned int px, unsigned int py)
{
	unsigned int	**cost_map;	
	t_list_meta		meta;
	t_list			*next;
	t_map			*map_cpy;
	int				res;

	map_cpy = copy_map(map);
	cost_map = get_cost_map(map, map_cpy);
	if (!map_cpy || !cost_map)
		ft_e_path(1, datas);
	next = create_node(px, py);
	meta = create_list(NULL, NULL, &meta);
	res = pathfinding_loop(map_cpy, cost_map, &meta, next);
	free_all(map_cpy, cost_map, &meta);
	return (res);
}
