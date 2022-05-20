/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_items_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:47:56 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 19:04:48 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_chest(t_datas *datas)
{
	int	i;

	datas->map->items[0][0] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_1.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][1] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_2.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][2] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_3.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][3] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_4.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][4] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_5.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][5] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_6.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][6] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_7.xpm", TILESIZE, TILESIZE);
	datas->map->items[0][7] = mlx_xpm_file_to_image(datas->mlx,
			"assets/chest_8.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->map->items[0][i])
			ft_e_load(2, datas);
		i++;
	}
}

static void	load_gems(t_datas *datas)
{
	int	i;

	datas->map->items[1][0] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_1.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][2] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_2.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][3] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_3.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][4] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_4.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][5] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_5.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][6] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_6.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][7] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_7.xpm", TILESIZE, TILESIZE);
	datas->map->items[1][8] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gems_8.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->map->items[1][i])
			ft_e_load(2, datas);
		i++;
	}
}

static void	load_crystal(t_datas *datas)
{
	int	i;

	datas->map->items[2][0] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_1.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][2] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_2.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][3] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_3.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][4] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_4.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][5] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_5.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][6] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_6.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][7] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_7.xpm", TILESIZE, TILESIZE);
	datas->map->items[2][8] = mlx_xpm_file_to_image(datas->mlx,
			"assets/crystal_8.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->map->items[2][i])
			ft_e_load(2, datas);
		i++;
	}
}

static void load_gold(t_datas *datas)
{
	int	i;

	datas->map->items[3][0] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_1.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][2] = mlx_xpm_file_to_image(datas->mlx,
			"assets/goldi_2.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][3] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_3.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][4] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_4.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][5] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_5.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][6] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_6.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][7] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_7.xpm", TILESIZE, TILESIZE);
	datas->map->items[3][8] = mlx_xpm_file_to_image(datas->mlx,
			"assets/gold_8.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->map->items[3][i])
			ft_e_load(2, datas);
		i++;
	}
}

void	load_items(t_datas *datas)
{
	load_chest(datas);
	load_gems(datas);
	load_crystal(datas);
	load_gold(datas);
}
