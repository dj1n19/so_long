/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:34:27 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/15 15:47:53 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_ground(t_map *map, void *mlx, void *win)
{
	int	x;
	int	y;

	y = 1;
	while (y < map->size_y - 1)
	{
		x = 1;
		while (x < map->size_x - 1)
		{
			mlx_put_image_to_window(mlx, win, map->ground,
				TILESIZE * x, TILESIZE * y);
			x++;
		}
		y++;
	}	
}

static void	draw_edges(t_map *map, void *mlx, void *win)
{
	int	i;

	i = 1;
	while (i < map->size_x - 1)
	{
		mlx_put_image_to_window(mlx, win, map->edges[1], TILESIZE * i, 0);
		mlx_put_image_to_window(mlx, win, map->edges[5], TILESIZE * i,
			(map->size_y * TILESIZE) - TILESIZE);
		i++;
	}
	i = 1;
	while (i < map->size_y - 1)
	{
		mlx_put_image_to_window(mlx, win, map->edges[3],
			(map->size_x * TILESIZE) - TILESIZE, TILESIZE * i);
		mlx_put_image_to_window(mlx, win, map->edges[7], 0, TILESIZE * i);
		i++;
	}
}

static void	draw_corner(t_map *map, void *mlx, void *win)
{
	mlx_put_image_to_window(mlx, win, map->edges[0], 0, 0);
	mlx_put_image_to_window(mlx, win, map->edges[2],
		(map->size_x * TILESIZE) - TILESIZE, 0);
	mlx_put_image_to_window(mlx, win, map->edges[4],
		(map->size_x * TILESIZE) - TILESIZE,
		(map->size_y * TILESIZE) - TILESIZE);
	mlx_put_image_to_window(mlx, win, map->edges[6], 0,
		(map->size_y * TILESIZE) - TILESIZE);
}

int	ft_draw(t_datas *datas)
{
	char	*mc;
	static int		timer;

	draw_corner(datas->map, datas->mlx, datas->win);
	draw_edges(datas->map, datas->mlx, datas->win);
	draw_ground(datas->map, datas->mlx, datas->win);
	ft_draw_map_objects(datas);
	ft_draw_characters(datas);
	mlx_put_image_to_window(datas->mlx, datas->win, datas->player->portrait, 0, 0);
	if (datas->player->is_attacking == 1 && datas->player->target)
		mlx_put_image_to_window(datas->mlx, datas->win, datas->player->attack[datas->player->frame],datas->player->target->pos_x, datas->player->target->pos_y);
	if (datas->player->is_casting == 1 && datas->player->spell_target != 0)
		{printf("==(%d, %d)\n", datas->player->pos_x, datas->player->pos_y);ft_draw_spell(datas);}
	mc = ft_itoa(datas->move_count);
	mlx_string_put(datas->mlx, datas->win, 64, 64, 0x0000ff00, mc);
	free(mc);
	if (datas->player->hp <= 0)
	{
		timer++;
		mlx_string_put(datas->mlx, datas->win, 128, 128, 0x00ff0000, "WASTED");
		if (timer > 8)
			ft_close(datas);
	}
	return (0);
}
