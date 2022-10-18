/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:25:04 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/15 15:18:12 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_player_up(void *mlx, void *player_up[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_up[0] = mlx_xpm_file_to_image(mlx, PMU_1, &w, &h);
	player_up[1] = mlx_xpm_file_to_image(mlx, PMU_2, &w, &h);
	player_up[2] = mlx_xpm_file_to_image(mlx, PMU_3, &w, &h);
	player_up[3] = mlx_xpm_file_to_image(mlx, PMU_4, &w, &h);
	player_up[4] = mlx_xpm_file_to_image(mlx, PMU_5, &w, &h);
	player_up[5] = mlx_xpm_file_to_image(mlx, PMU_6, &w, &h);
	player_up[6] = mlx_xpm_file_to_image(mlx, PMU_7, &w, &h);
	player_up[7] = mlx_xpm_file_to_image(mlx, PMU_8, &w, &h);
	while (i < 8)
	{
		if (!player_up[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_player_right(void *mlx, void *player_right[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_right[0] = mlx_xpm_file_to_image(mlx, PMR_1, &w, &h);
	player_right[1] = mlx_xpm_file_to_image(mlx, PMR_2, &w, &h);
	player_right[2] = mlx_xpm_file_to_image(mlx, PMR_3, &w, &h);
	player_right[3] = mlx_xpm_file_to_image(mlx, PMR_4, &w, &h);
	player_right[4] = mlx_xpm_file_to_image(mlx, PMR_5, &w, &h);
	player_right[5] = mlx_xpm_file_to_image(mlx, PMR_6, &w, &h);
	player_right[6] = mlx_xpm_file_to_image(mlx, PMR_7, &w, &h);
	player_right[7] = mlx_xpm_file_to_image(mlx, PMR_8, &w, &h);
	while (i < 8)
	{
		if (!player_right[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_player_down(void *mlx, void *player_down[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_down[0] = mlx_xpm_file_to_image(mlx, PMD_1, &w, &h);
	player_down[1] = mlx_xpm_file_to_image(mlx, PMD_2, &w, &h);
	player_down[2] = mlx_xpm_file_to_image(mlx, PMD_3, &w, &h);
	player_down[3] = mlx_xpm_file_to_image(mlx, PMD_4, &w, &h);
	player_down[4] = mlx_xpm_file_to_image(mlx, PMD_5, &w, &h);
	player_down[5] = mlx_xpm_file_to_image(mlx, PMD_6, &w, &h);
	player_down[6] = mlx_xpm_file_to_image(mlx, PMD_7, &w, &h);
	player_down[7] = mlx_xpm_file_to_image(mlx, PMD_8, &w, &h);
	while (i < 8)
	{
		if (!player_down[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_player_left(void *mlx, void *player_left[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	player_left[0] = mlx_xpm_file_to_image(mlx, PML_1, &w, &h);
	player_left[1] = mlx_xpm_file_to_image(mlx, PML_2, &w, &h);
	player_left[2] = mlx_xpm_file_to_image(mlx, PML_3, &w, &h);
	player_left[3] = mlx_xpm_file_to_image(mlx, PML_4, &w, &h);
	player_left[4] = mlx_xpm_file_to_image(mlx, PML_5, &w, &h);
	player_left[5] = mlx_xpm_file_to_image(mlx, PML_6, &w, &h);
	player_left[6] = mlx_xpm_file_to_image(mlx, PML_7, &w, &h);
	player_left[7] = mlx_xpm_file_to_image(mlx, PML_8, &w, &h);
	while (i < 8)
	{
		if (!player_left[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

void	load_player(t_datas *datas)
{
	load_player_left(datas->mlx, datas->textures->player_left);
	load_player_right(datas->mlx, datas->textures->player_right);
	load_player_up(datas->mlx, datas->textures->player_up);
	load_player_down(datas->mlx, datas->textures->player_down);
}
