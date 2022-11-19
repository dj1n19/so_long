/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:07:27 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 15:29:30 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

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
	map_cpy->map = (char **) malloc(sizeof(char *) * map->size_y);
	if (!map_cpy->map)
	{
		free(map_cpy);
		return (NULL);
	}
	map_cpy->size_x = map->size_x;
	map_cpy->size_y = map->size_y;
	return (map_cpy);
}
