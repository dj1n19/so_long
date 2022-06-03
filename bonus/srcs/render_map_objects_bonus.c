/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_objects_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:39:40 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/01 16:17:17 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_exit(t_datas *datas, int x, int y)
{
	if (datas->map->blueprint[y][x] == 'E')
	{
		if (datas->map->portal_open == 0)
		{
			mlx_put_image_to_window(datas->mlx, datas->win,
					datas->map->exit_close, TILESIZE * x, TILESIZE * y);
		}
		else
		{
			mlx_put_image_to_window(datas->mlx, datas->win,
					datas->map->exit_open[datas->map->frame],
					TILESIZE * x, TILESIZE * y);
		}
	}
}

static void	draw_walls(t_datas *datas, int x, int y)
{
	mlx_put_image_to_window(datas->mlx, datas->win, datas->map->wall,
			TILESIZE * x, TILESIZE * y);
}

void	ft_draw_map_objects(t_datas *datas)
{
	int		x;
	int		y;
	char	**bp;

	bp = datas->map->blueprint;
	y = 1; 
	while (y < datas->map->size_y - 1)
	{
		x = 1;
		while (x < datas->map->size_x - 1)
		{
			if (bp[y][x] == 'C' || bp[y][x] == 'G' || bp[y][x] == 'K'
					|| bp[y][x] == 'A')
				ft_draw_items(datas, bp[y][x], x, y);
			if (bp[y][x] == '1')
				draw_walls(datas, x, y);
			if (bp[y][x] == 'E')
				draw_exit(datas, x, y);
			x++;
		}
		y++;
	}
}
