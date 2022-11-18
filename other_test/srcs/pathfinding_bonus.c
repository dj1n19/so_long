/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:12:52 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/13 15:54:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static unsigned long	get_exit(t_map *map)
{
	unsigned int	x_exit;
	unsigned int	y_exit;
	unsigned long	exit_pos;

	y_exit = 1;
	while (y_exit < map->y - 1)
	{
		x_exit = 1;
		while (x_exit < map->x - 1)
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

static unsigned int	**get_cost_map(t_map *map)
{
	unsigned long	exit_pos;
	unsigned int	x;
	unsigned int	y;
	unsigned int	**cost_map;

	cost_map = (unsigned int **) malloc(sizeof(unsigned int *) * map->y);
	if (!cost_map)
		error_handler(NULL);
	exit_pos = get_exit(map);
	y = 0;
	while (y < map->y)
	{
		x = 0;
		cost_map[y] = (unsigned int *) malloc(sizeof(unsigned int) * map->x);
		if (!cost_map[y])
			error_handler(NULL);
		while (x < map->x)
		{
				cost_map[y][x] = calc_cost(exit_pos, x, y);
			++x;
		}
		++y;
	}
	return (cost_map);
}

static t_map	*copy_map(t_map *map)
{
	t_map	*map_cpy;
	int		y;
	int		x;

	map_cpy = malloc(sizeof(t_map));
	if (!map_cpy)
		error_handler(E_MALLOC);
	ft_memmove(map_cpy, map, sizeof(t_map));
	map_cpy->map = (char **) malloc(sizeof(char *) * map->y);
	y = 0;
	while (y < map->y)
	{
		x = 0;
		map_cpy->map[y] = (char *) malloc(sizeof(char) * map->x);
		if (!map_cpy->map[y])
			error_handler(E_MALLOC);
		while (x < map->x)
		{
			map_cpy->map[y][x] = map->map[y][x];
			x++;
		}
		y++;
	}
	return (map_cpy);
}



static int	pathfinding_loop(t_map *map_cpy, unsigned int **cost_map, t_list_meta *meta, t_list *next)
{
	while (1)
	{
		meta = push_back(next, meta);
		if (has_next(map_cpy, meta->tail->x, meta->tail->y) == 0)
			return (0);
		if (cost_map[meta->tail->y][meta->tail->x] == 0)
			return (1);
		next = get_next(map_cpy, cost_map, next, meta->head);
		if (!next)
		{
			map_cpy->map[meta->tail->y][meta->tail->x] = '1';
			meta = pop_back(meta);
			next = meta->tail;
		}
	}
	return (0);
}

int	pathfinding(t_map *map, unsigned int px, unsigned int py)
{
	unsigned int	**cost_map;	
	t_list_meta		meta;
	t_list			*next;
	t_map			*map_cpy;
	int				res;

	map_cpy = copy_map(map);
	cost_map = get_cost_map(map_cpy);
	next = create_node(px, py);
	meta = create_list(NULL, NULL, &meta);
	res = pathfinding_loop(map_cpy, cost_map, &meta, next);
	free_all(map_cpy, cost_map, &meta);
	return (res);
}
