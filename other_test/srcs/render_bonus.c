/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:34:27 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/30 15:23:20 by bgenie           ###   ########.fr       */
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

void	write_to_img(t_img *dst_img, void *src_datas, int x, int y)
{
	int		i;
	int		j;
	char	*dst;
	char	*src;
	t_img	src_img;

	if (!dst_img || !src_datas)
		return ;
	i = -1;
	src_img.img = src_datas;
	src_img.addr = mlx_get_data_addr(src_img.img,
			&src_img.bpp, &src_img.line_len, &src_img.endian);
	while (++i < TILESIZE)
	{
		j = -1;
		while (++j < TILESIZE)
		{
			dst = dst_img->addr + ((i + y) * dst_img->line_len
					+ (j + x) * (dst_img->bpp / 8));
			src = src_img.addr + (i * src_img.line_len
					+ j * (src_img.bpp / 8));
			if (*(unsigned int *)src != 0xff000000)
					*(unsigned int *)dst = *(unsigned int *)src;
		}
	}
}

static void	draw_str(t_datas *datas)
{
	char	*hp;
	char	*mc;

	hp = ft_itoa(datas->player->hp);
	mc = ft_itoa(datas->player->move_count);
	mlx_string_put(datas->mlx, datas->win, 64, 32, 0x0000ff00, hp);
	mlx_string_put(datas->mlx, datas->win, 32, 32, 0x000000ff, mc);
	free(hp);
	free(mc);
}

int	draw(t_datas *d)
{
	t_img	tmp_img;

	tmp_img.img = mlx_new_image(d->mlx,
			d->map->x * TILESIZE, d->map->y * TILESIZE);
	if (!tmp_img.img)
		return (-1);
	tmp_img.addr = mlx_get_data_addr(tmp_img.img,
			&tmp_img.bpp, &tmp_img.line_len, &tmp_img.endian);
	draw_corner(&tmp_img, d->textures, d->map);
	draw_edges(&tmp_img, d->textures, d->map);
	draw_ground(&tmp_img, d->textures, d->map);
	draw_map_objects(&tmp_img, d);
	draw_characters(&tmp_img, d->player, d->foes);
	if (d->player->target)
		write_to_img(&tmp_img, d->textures->player_sfx
		[d->player->frame], d->player->target->x, d->player->target->y);
	if (d->player->spell_target != 0)
		draw_spell(&tmp_img, d->player, d->textures);
	ft_memmove(d->img, &tmp_img, sizeof(tmp_img));
	mlx_put_image_to_window(d->mlx, d->win, d->img->img, 0, 0);
	mlx_destroy_image(d->mlx, tmp_img.img);
	draw_str(d);	
	return (0);
}
