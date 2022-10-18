/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:34:27 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/09 14:57:15 by bgenie           ###   ########.fr       */
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

// int	ft_draw(t_datas *datas)
// {
// 	char	*hp;

// 	draw_corner(datas->map, datas->mlx, datas->win);
// 	draw_edges(datas->map, datas->mlx, datas->win);
// 	draw_ground(datas->map, datas->mlx, datas->win);
// 	ft_draw_map_objects(datas);
// 	ft_draw_characters(datas);
// 	mlx_put_image_to_window(datas->mlx, datas->win,
// 		datas->player->portrait, 0, 0);
// 	if (datas->player->is_attacking == 1 && datas->player->target)
// 		mlx_put_image_to_window(datas->mlx, datas->win,
// 			datas->player->attack[datas->player->frame],
// 			datas->player->target->pos_x, datas->player->target->pos_y);
// 	if (datas->player->is_casting == 1 && datas->player->spell_target != 0)
// 		ft_draw_spell(datas);
// 	hp = ft_itoa(datas->player->hp);
// 	mlx_string_put(datas->mlx, datas->win, 64, 64, 0x0000ff00, hp);
// 	free(hp);
// 	if (datas->player->hp <= 0)
// 		ft_close(datas);
// 	return (0);
// }

void	write_to_img(t_img *dst_img, void *src_datas, int x, int y)
{
	int		i;
	int		j;
	char	*dst;
	char	*src;
	t_img	src_img;

	if (!dst_img || !src_datas)
		return ;
	i = 0;
	src_img.img = src_datas;
	src_img.addr = mlx_get_data_addr(src_img.img,
		&src_img.bpp, &src_img.line_len, &src_img.endian);
	while (i < TILESIZE)
	{
		j = 0;
		while (j < TILESIZE)
		{
			dst = dst_img->addr + ((i + y) * dst_img->line_len
				+ (j + x) * (dst_img->bpp / 8));
			src = src_img.addr + (i * src_img.line_len
				+ j * (src_img.bpp / 8));
			if (*(unsigned int *)src != 0xff000000)
				*(unsigned int *)dst = *(unsigned int *)src;
			++j;
		}
		++i;
	}
}

int	draw(t_datas *datas)
{
	t_img	tmp_img;
	char	*hp;

	tmp_img.img = mlx_new_image(datas->mlx,
		datas->map->x * TILESIZE, datas->map->y * TILESIZE);
	if (!tmp_img.img)
		return (-1);
	tmp_img.addr = mlx_get_data_addr(tmp_img.img,
		&tmp_img.bpp, &tmp_img.line_len, &tmp_img.endian);
	draw_corner(&tmp_img, datas->textures, datas->map);
	draw_edges(&tmp_img, datas->textures, datas->map);
	draw_ground(&tmp_img, datas->textures, datas->map);
	draw_map_objects(&tmp_img, datas);
	draw_characters(&tmp_img, datas->player, datas->foes);
	if (datas->player->target)
		write_to_img(&tmp_img, datas->textures->player_sfx
			[datas->player->frame], datas->player->target->x, datas->player->target->y);
	if (datas->player->spell_target != 0)
		draw_spell(&tmp_img, datas->player, datas->textures);
	ft_memcpy(datas->img, &tmp_img, sizeof(tmp_img));
	mlx_put_image_to_window(datas->mlx, datas->win, tmp_img.img, 0, 0);
	hp = ft_itoa(datas->player->hp);
	mlx_string_put(datas->mlx, datas->win, 64, 64, 0x0000ff00, hp);
	free(hp);
	return (0);
}