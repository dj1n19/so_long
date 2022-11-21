/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:07:27 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/21 14:01:13 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

int	pathfinding_loop(t_map *map_cpy, unsigned int **cost_map,
	t_list_meta *meta, t_list *next)
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

t_map	*create_map_cpy(t_map *map)
{
	t_map	*map_cpy;

	map_cpy = malloc(sizeof(t_map));
	if (!map_cpy)
		return (NULL);
	map_cpy->map = (char **) malloc(sizeof(char *) * map->y);
	if (!map_cpy->map)
	{
		free(map_cpy);
		return (NULL);
	}
	map_cpy->x = map->x;
	map_cpy->y = map->y;
	return (map_cpy);
}

unsigned long	get_item(t_map *map)
{
	unsigned int	x_item;
	unsigned int	y_item;
	unsigned long	item_pos;

	y_item = 1;
	while (y_item < (unsigned)map->y - 1)
	{
		x_item = 1;
		while (x_item < (unsigned)map->x - 1)
		{
			if (map->map[y_item][x_item] == 'C' || map->map[y_item][x_item] == 'K' || map->map[y_item][x_item] == 'G' || map->map[y_item][x_item] == 'A')
			{
				item_pos = ((unsigned long)y_item << 32);
				item_pos += (unsigned long)x_item;
				map->map[y_item][x_item] = '0';
				return (item_pos);
			}
			x_item++;
		}
		y_item++;
	}
	return (0);
}

int	pathfinding_item(t_datas *datas, t_map *map_cpy, unsigned int ix, unsigned int iy)
{
	unsigned int	**cost_map;
	t_list_meta		meta;
	t_list			*next;
	int				res;

	cost_map = get_cost_map(datas->map, map_cpy);
	if (!map_cpy || !cost_map)
		error_handler(E_MALLOC, datas);
	next = create_node(ix, iy);
	meta = create_list(NULL, NULL, &meta);
	res = pathfinding_loop(map_cpy, cost_map, &meta, next);
	free_all(map_cpy, cost_map, &meta, 0);
	return (res);
}

void	is_item_valid(t_datas *datas)
{
	t_map			*map_cpy;
	unsigned long	item_pos;

	map_cpy = copy_map(datas->map);
	item_pos = get_item(map_cpy);
	while (item_pos != 0)
	{
		if (!pathfinding_item(datas, map_cpy, (unsigned)item_pos, (unsigned)(item_pos >> 32)))
		{
			free_map(map_cpy);
			free(map_cpy);
			error_handler(E_PATH, datas);
		}
		item_pos = get_item(map_cpy);
	}
	free_map(map_cpy);
	free(map_cpy);
}
