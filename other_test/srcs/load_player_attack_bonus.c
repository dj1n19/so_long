/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_attack_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:55:22 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/15 15:41:46 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_player_anim_attack(void *mlx, void *player_attack[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_attack[0] = mlx_xpm_file_to_image(mlx, PAA_1, &w, &h);
	player_attack[1] = mlx_xpm_file_to_image(mlx, PAA_2, &w, &h);
	player_attack[2] = mlx_xpm_file_to_image(mlx, PAA_3, &w, &h);
	player_attack[3] = mlx_xpm_file_to_image(mlx, PAA_4, &w, &h);
	player_attack[4] = mlx_xpm_file_to_image(mlx, PAA_5, &w, &h);
	player_attack[5] = mlx_xpm_file_to_image(mlx, PAA_6, &w, &h);
	player_attack[6] = mlx_xpm_file_to_image(mlx, PAA_7, &w, &h);
	player_attack[7] = mlx_xpm_file_to_image(mlx, PAA_8, &w, &h);
	while (i < 8)
	{
		if (!player_attack[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_player_sfx(void *mlx, void *player_sfx[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_sfx[0] = mlx_xpm_file_to_image(mlx, PAE_1, &w, &h);
	player_sfx[1] = mlx_xpm_file_to_image(mlx, PAE_2, &w, &h);
	player_sfx[2] = mlx_xpm_file_to_image(mlx, PAE_3, &w, &h);
	player_sfx[3] = mlx_xpm_file_to_image(mlx, PAE_4, &w, &h);
	player_sfx[4] = mlx_xpm_file_to_image(mlx, PAE_5, &w, &h);
	player_sfx[5] = mlx_xpm_file_to_image(mlx, PAE_6, &w, &h);
	player_sfx[6] = mlx_xpm_file_to_image(mlx, PAE_7, &w, &h);
	player_sfx[7] = mlx_xpm_file_to_image(mlx, PAE_8, &w, &h);
	while (i < 8)
	{
		if (!player_sfx[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_player_spell(void *mlx, void *player_spell[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_spell[0] = mlx_xpm_file_to_image(mlx, SPL_1, &w, &h);
	player_spell[1] = mlx_xpm_file_to_image(mlx, SPL_2, &w, &h);
	player_spell[2] = mlx_xpm_file_to_image(mlx, SPL_3, &w, &h);
	player_spell[3] = mlx_xpm_file_to_image(mlx, SPL_4, &w, &h);
	player_spell[4] = mlx_xpm_file_to_image(mlx, SPL_5, &w, &h);
	player_spell[5] = mlx_xpm_file_to_image(mlx, SPL_6, &w, &h);
	player_spell[6] = mlx_xpm_file_to_image(mlx, SPL_7, &w, &h);
	player_spell[7] = mlx_xpm_file_to_image(mlx, SPL_8, &w, &h);
	while (i < 8)
	{
		if (!player_spell[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

void	load_player_attack(t_datas *datas)
{
	load_player_anim_attack(datas->mlx, datas->textures->player_attack);
	load_player_sfx(datas->mlx, datas->textures->player_sfx);
	load_player_spell(datas->mlx, datas->textures->player_spell);
}
