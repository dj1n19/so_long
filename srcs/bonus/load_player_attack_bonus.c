/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_attack_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:55:22 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	load_player_anim_attack(t_datas *d, void *player_attack[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_attack[0] = mlx_xpm_file_to_image(d->mlx, PAA_1, &w, &h);
	player_attack[1] = mlx_xpm_file_to_image(d->mlx, PAA_2, &w, &h);
	player_attack[2] = mlx_xpm_file_to_image(d->mlx, PAA_3, &w, &h);
	player_attack[3] = mlx_xpm_file_to_image(d->mlx, PAA_4, &w, &h);
	player_attack[4] = mlx_xpm_file_to_image(d->mlx, PAA_5, &w, &h);
	player_attack[5] = mlx_xpm_file_to_image(d->mlx, PAA_6, &w, &h);
	player_attack[6] = mlx_xpm_file_to_image(d->mlx, PAA_7, &w, &h);
	player_attack[7] = mlx_xpm_file_to_image(d->mlx, PAA_8, &w, &h);
	while (i < 8)
	{
		if (!player_attack[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

static void	load_player_sfx(t_datas *d, void *player_sfx[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_sfx[0] = mlx_xpm_file_to_image(d->mlx, PAE_1, &w, &h);
	player_sfx[1] = mlx_xpm_file_to_image(d->mlx, PAE_2, &w, &h);
	player_sfx[2] = mlx_xpm_file_to_image(d->mlx, PAE_3, &w, &h);
	player_sfx[3] = mlx_xpm_file_to_image(d->mlx, PAE_4, &w, &h);
	player_sfx[4] = mlx_xpm_file_to_image(d->mlx, PAE_5, &w, &h);
	player_sfx[5] = mlx_xpm_file_to_image(d->mlx, PAE_6, &w, &h);
	player_sfx[6] = mlx_xpm_file_to_image(d->mlx, PAE_7, &w, &h);
	player_sfx[7] = mlx_xpm_file_to_image(d->mlx, PAE_8, &w, &h);
	while (i < 8)
	{
		if (!player_sfx[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

static void	load_player_spell(t_datas *d, void *player_spell[8])
{
	int		i;
	int		w;
	int		h;

	w = TILESIZE;
	h = TILESIZE;
	i = 0;
	player_spell[0] = mlx_xpm_file_to_image(d->mlx, SPL_1, &w, &h);
	player_spell[1] = mlx_xpm_file_to_image(d->mlx, SPL_2, &w, &h);
	player_spell[2] = mlx_xpm_file_to_image(d->mlx, SPL_3, &w, &h);
	player_spell[3] = mlx_xpm_file_to_image(d->mlx, SPL_4, &w, &h);
	player_spell[4] = mlx_xpm_file_to_image(d->mlx, SPL_5, &w, &h);
	player_spell[5] = mlx_xpm_file_to_image(d->mlx, SPL_6, &w, &h);
	player_spell[6] = mlx_xpm_file_to_image(d->mlx, SPL_7, &w, &h);
	player_spell[7] = mlx_xpm_file_to_image(d->mlx, SPL_8, &w, &h);
	while (i < 8)
	{
		if (!player_spell[i])
			error_handler(E_TEX_PLAYER, d);
		i++;
	}
}

void	load_player_attack(t_datas *datas)
{
	load_player_anim_attack(datas, datas->textures->player_attack);
	load_player_sfx(datas, datas->textures->player_sfx);
	load_player_spell(datas, datas->textures->player_spell);
}
