/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_items_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:45:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/23 15:56:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_chest(t_datas *datas, int x, int y)
{	
	mlx_put_image_to_window(datas->mlx, datas->win,
			datas->map->items[0][datas->map->frame],
			TILESIZE * x, TILESIZE * y);
}

static void	draw_gems(t_datas *datas, int x, int y)
{
	mlx_put_image_to_window(datas->mlx, datas->win,
			datas->map->items[1][datas->map->frame],
			TILESIZE * x, TILESIZE * y);
}

static void	draw_crystal(t_datas *datas, int x, int y)
{
	mlx_put_image_to_window(datas->mlx, datas->win,
			datas->map->items[2][datas->map->frame],
			TILESIZE * x, TILESIZE * y);
}

static void	draw_gold(t_datas *datas, int x, int y)
{
	mlx_put_image_to_window(datas->mlx, datas->win,
			datas->map->items[4][datas->map->frame],
			TILESIZE * x, TILESIZE * y);
}

void	ft_draw_items(t_datas *datas, char item, int x, int y)
{
	if (item == 'C')
		draw_chest(datas, x, y);
	else if (item == 'G')
		draw_gems(datas, x, y);
	else if (item == 'K')
		draw_crystal(datas, x, y);
	else if (item == 'A')
		draw_gold(datas, x, y);
}
