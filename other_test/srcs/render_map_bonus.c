/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:13:21 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/11 12:13:23 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_ground(t_img *img, t_textures *textures, t_map *map)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->y - 1)
	{
		x = 1;
		while (x < map->x - 1)
		{
			write_to_img(img, textures->ground, TILESIZE * x, TILESIZE * y);
			x++;
		}
		y++;
	}
}

static void	draw_edges(t_img *img, t_textures *textures, t_map *map)
{
	int	i;

	i = 1;
	while (i < map->x - 1)
	{
		write_to_img(img, textures->map_edges[1], TILESIZE * i, 0);
		write_to_img(img, textures->map_edges[5],
			TILESIZE * i, (map->y - 1) * TILESIZE);
		i++;
	}
	i = 1;
	while (i < map->y - 1)
	{
		write_to_img(img, textures->map_edges[3],
			(map->x - 1) * TILESIZE, TILESIZE * i);
		write_to_img(img, textures->map_edges[7], 0, TILESIZE * i);
		i++;
	}
}

static void	draw_corner(t_img *img, t_textures *textures, t_map *map)
{
	write_to_img(img, textures->map_edges[0], 0, 0);
	write_to_img(img, textures->map_edges[2], (map->x - 1) * TILESIZE, 0);
	write_to_img(img, textures->map_edges[4],
		(map->x - 1) * TILESIZE, (map->y - 1) * TILESIZE);
	write_to_img(img, textures->map_edges[6], 0, (map->y - 1) * TILESIZE);
}

void	draw_map(t_img *img, t_textures *textures, t_map *map)
{
	draw_ground(img, textures, map);
	draw_edges(img, textures, map);
	draw_corner(img, textures, map);
}
