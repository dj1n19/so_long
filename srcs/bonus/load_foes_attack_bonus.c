/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_attack_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	load_unicorn_attack_right(t_datas *d, void *unicorn_attack_right[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_attack_right[0] = mlx_xpm_file_to_image(d->mlx, UAR_1, &x, &y);
	unicorn_attack_right[1] = mlx_xpm_file_to_image(d->mlx, UAR_2, &x, &y);
	unicorn_attack_right[2] = mlx_xpm_file_to_image(d->mlx, UAR_3, &x, &y);
	unicorn_attack_right[3] = mlx_xpm_file_to_image(d->mlx, UAR_4, &x, &y);
	unicorn_attack_right[4] = mlx_xpm_file_to_image(d->mlx, UAR_5, &x, &y);
	unicorn_attack_right[5] = mlx_xpm_file_to_image(d->mlx, UAR_6, &x, &y);
	unicorn_attack_right[6] = mlx_xpm_file_to_image(d->mlx, UAR_7, &x, &y);
	unicorn_attack_right[7] = mlx_xpm_file_to_image(d->mlx, UAR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_attack_right[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

static void	load_unicorn_attack_left(t_datas *d, void *unicorn_attack_left[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_attack_left[0] = mlx_xpm_file_to_image(d->mlx, UAL_1, &x, &y);
	unicorn_attack_left[1] = mlx_xpm_file_to_image(d->mlx, UAL_2, &x, &y);
	unicorn_attack_left[2] = mlx_xpm_file_to_image(d->mlx, UAL_3, &x, &y);
	unicorn_attack_left[3] = mlx_xpm_file_to_image(d->mlx, UAL_4, &x, &y);
	unicorn_attack_left[4] = mlx_xpm_file_to_image(d->mlx, UAL_5, &x, &y);
	unicorn_attack_left[5] = mlx_xpm_file_to_image(d->mlx, UAL_6, &x, &y);
	unicorn_attack_left[6] = mlx_xpm_file_to_image(d->mlx, UAL_7, &x, &y);
	unicorn_attack_left[7] = mlx_xpm_file_to_image(d->mlx, UAL_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_attack_left[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

static void	load_dragon_attack_right(t_datas *d, void *dragon_attack_right[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_attack_right[0] = mlx_xpm_file_to_image(d->mlx, DAR_1, &x, &y);
	dragon_attack_right[1] = mlx_xpm_file_to_image(d->mlx, DAR_2, &x, &y);
	dragon_attack_right[2] = mlx_xpm_file_to_image(d->mlx, DAR_3, &x, &y);
	dragon_attack_right[3] = mlx_xpm_file_to_image(d->mlx, DAR_4, &x, &y);
	dragon_attack_right[4] = mlx_xpm_file_to_image(d->mlx, DAR_5, &x, &y);
	dragon_attack_right[5] = mlx_xpm_file_to_image(d->mlx, DAR_6, &x, &y);
	dragon_attack_right[6] = mlx_xpm_file_to_image(d->mlx, DAR_7, &x, &y);
	dragon_attack_right[7] = mlx_xpm_file_to_image(d->mlx, DAR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_attack_right[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

static void	load_dragon_attack_left(t_datas *d, void *dragon_attack_left[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_attack_left[0] = mlx_xpm_file_to_image(d->mlx, DAL_1, &x, &y);
	dragon_attack_left[1] = mlx_xpm_file_to_image(d->mlx, DAL_2, &x, &y);
	dragon_attack_left[2] = mlx_xpm_file_to_image(d->mlx, DAL_3, &x, &y);
	dragon_attack_left[3] = mlx_xpm_file_to_image(d->mlx, DAL_4, &x, &y);
	dragon_attack_left[4] = mlx_xpm_file_to_image(d->mlx, DAL_5, &x, &y);
	dragon_attack_left[5] = mlx_xpm_file_to_image(d->mlx, DAL_6, &x, &y);
	dragon_attack_left[6] = mlx_xpm_file_to_image(d->mlx, DAL_7, &x, &y);
	dragon_attack_left[7] = mlx_xpm_file_to_image(d->mlx, DAL_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_attack_left[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

void	load_foes_attack(t_datas *datas)
{
	load_unicorn_attack_right(datas, datas->textures->unicorn_attack_right);
	load_unicorn_attack_left(datas, datas->textures->unicorn_attack_left);
	load_dragon_attack_right(datas, datas->textures->dragon_attack_right);
	load_dragon_attack_left(datas, datas->textures->dragon_attack_left);
}
