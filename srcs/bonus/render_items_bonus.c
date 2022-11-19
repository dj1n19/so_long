/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_items_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:45:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	draw_chest(t_img *img, t_datas *datas, int x, int y)
{
	write_to_img(img, datas->textures->chest[datas->map->frame],
		TILESIZE * x, TILESIZE * y);
}

static void	draw_gems(t_img *img, t_datas *datas, int x, int y)
{
	write_to_img(img, datas->textures->gems[datas->map->frame],
		TILESIZE * x, TILESIZE * y);
}

static void	draw_crystal(t_img *img, t_datas *datas, int x, int y)
{
	write_to_img(img, datas->textures->crystal[datas->map->frame],
		TILESIZE * x, TILESIZE * y);
}

static void	draw_gold(t_img *img, t_datas *datas, int x, int y)
{
	write_to_img(img, datas->textures->gold[datas->map->frame],
		TILESIZE * x, TILESIZE * y);
}

void	draw_items(t_img *img, t_datas *datas, int x, int y)
{
	if (datas->map->map[y][x] == 'C')
		draw_chest(img, datas, x, y);
	else if (datas->map->map[y][x] == 'G')
		draw_gems(img, datas, x, y);
	else if (datas->map->map[y][x] == 'K')
		draw_crystal(img, datas, x, y);
	else if (datas->map->map[y][x] == 'A')
		draw_gold(img, datas, x, y);
}
