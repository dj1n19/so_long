/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:25:04 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	load_player_up(t_datas *d, void *player_up[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_up[0] = mlx_xpm_file_to_image(d->mlx, PMU_1, &w, &h);
	player_up[1] = mlx_xpm_file_to_image(d->mlx, PMU_2, &w, &h);
	player_up[2] = mlx_xpm_file_to_image(d->mlx, PMU_3, &w, &h);
	player_up[3] = mlx_xpm_file_to_image(d->mlx, PMU_4, &w, &h);
	player_up[4] = mlx_xpm_file_to_image(d->mlx, PMU_5, &w, &h);
	player_up[5] = mlx_xpm_file_to_image(d->mlx, PMU_6, &w, &h);
	player_up[6] = mlx_xpm_file_to_image(d->mlx, PMU_7, &w, &h);
	player_up[7] = mlx_xpm_file_to_image(d->mlx, PMU_8, &w, &h);
	while (i < 8)
	{
		if (!player_up[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

static void	load_player_right(t_datas *d, void *player_right[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_right[0] = mlx_xpm_file_to_image(d->mlx, PMR_1, &w, &h);
	player_right[1] = mlx_xpm_file_to_image(d->mlx, PMR_2, &w, &h);
	player_right[2] = mlx_xpm_file_to_image(d->mlx, PMR_3, &w, &h);
	player_right[3] = mlx_xpm_file_to_image(d->mlx, PMR_4, &w, &h);
	player_right[4] = mlx_xpm_file_to_image(d->mlx, PMR_5, &w, &h);
	player_right[5] = mlx_xpm_file_to_image(d->mlx, PMR_6, &w, &h);
	player_right[6] = mlx_xpm_file_to_image(d->mlx, PMR_7, &w, &h);
	player_right[7] = mlx_xpm_file_to_image(d->mlx, PMR_8, &w, &h);
	while (i < 8)
	{
		if (!player_right[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

static void	load_player_down(t_datas *d, void *player_down[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_down[0] = mlx_xpm_file_to_image(d->mlx, PMD_1, &w, &h);
	player_down[1] = mlx_xpm_file_to_image(d->mlx, PMD_2, &w, &h);
	player_down[2] = mlx_xpm_file_to_image(d->mlx, PMD_3, &w, &h);
	player_down[3] = mlx_xpm_file_to_image(d->mlx, PMD_4, &w, &h);
	player_down[4] = mlx_xpm_file_to_image(d->mlx, PMD_5, &w, &h);
	player_down[5] = mlx_xpm_file_to_image(d->mlx, PMD_6, &w, &h);
	player_down[6] = mlx_xpm_file_to_image(d->mlx, PMD_7, &w, &h);
	player_down[7] = mlx_xpm_file_to_image(d->mlx, PMD_8, &w, &h);
	while (i < 8)
	{
		if (!player_down[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

static void	load_player_left(t_datas *d, void *player_left[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_left[0] = mlx_xpm_file_to_image(d->mlx, PML_1, &w, &h);
	player_left[1] = mlx_xpm_file_to_image(d->mlx, PML_2, &w, &h);
	player_left[2] = mlx_xpm_file_to_image(d->mlx, PML_3, &w, &h);
	player_left[3] = mlx_xpm_file_to_image(d->mlx, PML_4, &w, &h);
	player_left[4] = mlx_xpm_file_to_image(d->mlx, PML_5, &w, &h);
	player_left[5] = mlx_xpm_file_to_image(d->mlx, PML_6, &w, &h);
	player_left[6] = mlx_xpm_file_to_image(d->mlx, PML_7, &w, &h);
	player_left[7] = mlx_xpm_file_to_image(d->mlx, PML_8, &w, &h);
	while (i < 8)
	{
		if (!player_left[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

void	load_player(t_datas *datas)
{
	load_player_left(datas, datas->textures->player_left);
	load_player_right(datas, datas->textures->player_right);
	load_player_up(datas, datas->textures->player_up);
	load_player_down(datas, datas->textures->player_down);
}
