/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_objects_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:39:40 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/16 14:53:24 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_exit(t_img *img, t_datas *datas, int x, int y)
{
	if (datas->map->is_portal_open == 0)
	{
		write_to_img(img, datas->textures->portal_close,
			TILESIZE * x, TILESIZE * y);
	}
	else
	{
		write_to_img(img, datas->textures->portal_open[datas->map->frame],
			TILESIZE * x, TILESIZE * y);
	}
}

static void	draw_walls(t_img *img, t_textures *textures, int x, int y)
{
	write_to_img(img, textures->wall, TILESIZE * x, TILESIZE * y);
}

void	draw_map_objects(t_img *img, t_datas *datas)
{
	int		x;
	int		y;
	char	**m;

	m = datas->map->map;
	y = 1;
	while (y < datas->map->y - 1)
	{
		x = 1;
		while (x < datas->map->x - 1)
		{
			if (m[y][x] == 'C' || m[y][x] == 'G'
				|| m[y][x] == 'K' || m[y][x] == 'A')
				draw_items(img, datas, x, y);
			if (m[y][x] == '1')
				draw_walls(img, datas->textures, x, y);
			if (m[y][x] == 'E')
				draw_exit(img, datas, x, y);
			x++;
		}
		y++;
	}
}
