/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_objects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:39:40 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/19 15:58:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_items(t_map *map, void *mlx, void *win)
{
	int	x;
	int	y;
	int	i;

	y = 1;
	i = 0;
	while (y < map->size_y - 1)
	{
		x = 1;
		while (x < map->size_x - 1)
		{
			if (map->blueprint[y][x] == 'C')
			{
				mlx_put_image_to_window(mlx, win, map->item,
					TILESIZE * x, TILESIZE * y);
			}
			x++;
		}
		y++;
	}
}

static void	draw_exit(t_map *map, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->size_y - 1)
	{
		x = 0;
		while (++x < map->size_x - 1)
		{
			if (map->blueprint[y][x] == 'E')
			{
				if (map->portal_open == 0)
				{
					mlx_put_image_to_window(mlx, win, map->exit_close,
						TILESIZE * x, TILESIZE * y);
				}
				else
				{
					mlx_put_image_to_window(mlx, win, map->exit_open,
						TILESIZE * x, TILESIZE * y);
				}
			}
		}
		y++;
	}
}

static void	draw_walls(t_map *map, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->size_y - 1)
	{
		x = 1;
		while (x < map->size_x - 1)
		{
			if (map->blueprint[y][x] == '1')
			{
				mlx_put_image_to_window(mlx, win, map->wall,
					TILESIZE * x, TILESIZE * y);
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_map_objects(t_map *map, void *mlx, void *win)
{
	draw_walls(map, mlx, win);
	draw_exit(map, mlx, win);
	draw_items(map, mlx, win);
}
