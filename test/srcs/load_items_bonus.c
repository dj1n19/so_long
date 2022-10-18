/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_items_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:47:56 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/02 15:09:38 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_chest(t_datas *datas, void *mlx)
{
	int		i;
	int		w;
	int		h;
	void	**m;

	w = TILESIZE;
	h = TILESIZE;
	m = datas->map->item_chest;
	m[0] = mlx_xpm_file_to_image(mlx, "../../assets/chest_1.xpm", &w, &h);
	m[1] = mlx_xpm_file_to_image(mlx, "../../assets/chest_2.xpm", &w, &h);
	m[2] = mlx_xpm_file_to_image(mlx, "../../assets/chest_3.xpm", &w, &h);
	m[3] = mlx_xpm_file_to_image(mlx, "../../assets/chest_4.xpm", &w, &h);
	m[4] = mlx_xpm_file_to_image(mlx, "../../assets/chest_5.xpm", &w, &h);
	m[5] = mlx_xpm_file_to_image(mlx, "../../assets/chest_6.xpm", &w, &h);
	m[6] = mlx_xpm_file_to_image(mlx, "../../assets/chest_7.xpm", &w, &h);
	m[7] = mlx_xpm_file_to_image(mlx, "../../assets/chest_8.xpm", &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!m[i])
			ft_e_load(2, datas);
		i++;
	}
}

static void	load_gems(t_datas *datas, void *mlx)
{
	int		i;
	int		w;
	int		h;
	void	**m;

	w = TILESIZE;
	h = TILESIZE;
	m = datas->map->item_gems;
	m[0] = mlx_xpm_file_to_image(mlx, "../../assets/gems_1.xpm", &w, &h);
	m[1] = mlx_xpm_file_to_image(mlx, "../../assets/gems_2.xpm", &w, &h);
	m[2] = mlx_xpm_file_to_image(mlx, "../../assets/gems_3.xpm", &w, &h);
	m[3] = mlx_xpm_file_to_image(mlx, "../../assets/gems_4.xpm", &w, &h);
	m[4] = mlx_xpm_file_to_image(mlx, "../../assets/gems_5.xpm", &w, &h);
	m[5] = mlx_xpm_file_to_image(mlx, "../../assets/gems_6.xpm", &w, &h);
	m[6] = mlx_xpm_file_to_image(mlx, "../../assets/gems_7.xpm", &w, &h);
	m[7] = mlx_xpm_file_to_image(mlx, "../../assets/gems_8.xpm", &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!m[i])
			ft_e_load(2, datas);
		i++;
	}
}

static void	load_crystal(t_datas *datas, void *mlx)
{
	int		i;
	int		w;
	int		h;
	void	**m;

	w = TILESIZE;
	h = TILESIZE;
	m = datas->map->item_crystal;
	m[0] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_1.xpm", &w, &h);
	m[1] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_2.xpm", &w, &h);
	m[2] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_3.xpm", &w, &h);
	m[3] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_4.xpm", &w, &h);
	m[4] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_5.xpm", &w, &h);
	m[5] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_6.xpm", &w, &h);
	m[6] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_7.xpm", &w, &h);
	m[7] = mlx_xpm_file_to_image(mlx, "../../assets/crystal_8.xpm", &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!m[i])
			ft_e_load(2, datas);
		i++;
	}
}

static void	load_gold(t_datas *datas, void *mlx)
{
	int		i;
	int		w;
	int		h;
	void	**m;

	w = TILESIZE;
	h = TILESIZE;
	m = datas->map->item_gold;
	m[0] = mlx_xpm_file_to_image(mlx, "../../assets/gold_1.xpm", &w, &h);
	m[1] = mlx_xpm_file_to_image(mlx, "../../assets/gold_2.xpm", &w, &h);
	m[2] = mlx_xpm_file_to_image(mlx, "../../assets/gold_3.xpm", &w, &h);
	m[3] = mlx_xpm_file_to_image(mlx, "../../assets/gold_4.xpm", &w, &h);
	m[4] = mlx_xpm_file_to_image(mlx, "../../assets/gold_5.xpm", &w, &h);
	m[5] = mlx_xpm_file_to_image(mlx, "../../assets/gold_6.xpm", &w, &h);
	m[6] = mlx_xpm_file_to_image(mlx, "../../assets/gold_7.xpm", &w, &h);
	m[7] = mlx_xpm_file_to_image(mlx, "../../assets/gold_8.xpm", &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!m[i])
			ft_e_load(2, datas);
		i++;
	}
}

void	ft_load_items(t_datas *datas)
{
	load_chest(datas, datas->mlx);
	load_gems(datas, datas->mlx);
	load_crystal(datas, datas->mlx);
	load_gold(datas, datas->mlx);
}
