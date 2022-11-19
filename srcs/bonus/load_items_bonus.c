/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_items_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:47:56 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	load_chest(t_datas *d, void *chest[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	chest[0] = mlx_xpm_file_to_image(d->mlx, CHST_1, &w, &h);
	chest[1] = mlx_xpm_file_to_image(d->mlx, CHST_2, &w, &h);
	chest[2] = mlx_xpm_file_to_image(d->mlx, CHST_3, &w, &h);
	chest[3] = mlx_xpm_file_to_image(d->mlx, CHST_4, &w, &h);
	chest[4] = mlx_xpm_file_to_image(d->mlx, CHST_5, &w, &h);
	chest[5] = mlx_xpm_file_to_image(d->mlx, CHST_6, &w, &h);
	chest[6] = mlx_xpm_file_to_image(d->mlx, CHST_7, &w, &h);
	chest[7] = mlx_xpm_file_to_image(d->mlx, CHST_8, &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!chest[i])
			error_handler(E_TEX_ITEM, d);
		i++;
	}
}

static void	load_gems(t_datas *d, void *gems[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	gems[0] = mlx_xpm_file_to_image(d->mlx, GEMS_1, &w, &h);
	gems[1] = mlx_xpm_file_to_image(d->mlx, GEMS_2, &w, &h);
	gems[2] = mlx_xpm_file_to_image(d->mlx, GEMS_3, &w, &h);
	gems[3] = mlx_xpm_file_to_image(d->mlx, GEMS_4, &w, &h);
	gems[4] = mlx_xpm_file_to_image(d->mlx, GEMS_5, &w, &h);
	gems[5] = mlx_xpm_file_to_image(d->mlx, GEMS_6, &w, &h);
	gems[6] = mlx_xpm_file_to_image(d->mlx, GEMS_7, &w, &h);
	gems[7] = mlx_xpm_file_to_image(d->mlx, GEMS_8, &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!gems[i])
			error_handler(E_TEX_ITEM, d);
		i++;
	}
}

static void	load_crystal(t_datas *d, void *crystal[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	crystal[0] = mlx_xpm_file_to_image(d->mlx, CRST_1, &w, &h);
	crystal[1] = mlx_xpm_file_to_image(d->mlx, CRST_2, &w, &h);
	crystal[2] = mlx_xpm_file_to_image(d->mlx, CRST_3, &w, &h);
	crystal[3] = mlx_xpm_file_to_image(d->mlx, CRST_4, &w, &h);
	crystal[4] = mlx_xpm_file_to_image(d->mlx, CRST_5, &w, &h);
	crystal[5] = mlx_xpm_file_to_image(d->mlx, CRST_6, &w, &h);
	crystal[6] = mlx_xpm_file_to_image(d->mlx, CRST_7, &w, &h);
	crystal[7] = mlx_xpm_file_to_image(d->mlx, CRST_8, &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!crystal[i])
			error_handler(E_TEX_ITEM, d);
		i++;
	}
}

static void	load_gold(t_datas *d, void *gold[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	gold[0] = mlx_xpm_file_to_image(d->mlx, GOLD_1, &w, &h);
	gold[1] = mlx_xpm_file_to_image(d->mlx, GOLD_2, &w, &h);
	gold[2] = mlx_xpm_file_to_image(d->mlx, GOLD_3, &w, &h);
	gold[3] = mlx_xpm_file_to_image(d->mlx, GOLD_4, &w, &h);
	gold[4] = mlx_xpm_file_to_image(d->mlx, GOLD_5, &w, &h);
	gold[5] = mlx_xpm_file_to_image(d->mlx, GOLD_6, &w, &h);
	gold[6] = mlx_xpm_file_to_image(d->mlx, GOLD_7, &w, &h);
	gold[7] = mlx_xpm_file_to_image(d->mlx, GOLD_8, &w, &h);
	i = 0;
	while (i < 8)
	{
		if (!gold[i])
			error_handler(E_TEX_ITEM, d);
		i++;
	}
}

void	load_items(t_datas *datas)
{
	load_chest(datas, datas->textures->chest);
	load_gems(datas, datas->textures->gems);
	load_crystal(datas, datas->textures->crystal);
	load_gold(datas, datas->textures->gold);
}
