/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:06:07 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 01:49:30 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void load_unicorn_right(t_datas *datas)
{
	int	i;

	datas->unicorn->unicorn[0][0] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][1] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][2] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][3] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][4] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][5] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][6] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[0][7] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	i = 0;
	while ( i < 8)
	{
		if (!datas->unicorn->unicorn[0][i])
			ft_e_load(5);
	}
}

static void	load_unicorn_left(t_datas *datas)
{
	int	i;

	datas->unicorn->unicorn[1][0] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][1] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][2] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][3] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][4] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][5] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][6] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->unicorn->unicorn[1][7] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->unicorn->unicorn[0][i])
			ft_e_load(5);
	}
}

static void load_dragon_right(t_datas *datas)
{
	int	i;

	datas->dragon->dragon[0][0] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][1] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][2] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][3] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][4] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][5] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][6] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[0][7] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_right.xpm", TILESIZE, TILESIZE);
	i = 0;
	while ( i < 8)
	{
		if (!datas->dragon->dragon[0][i])
			ft_e_load(5);
	}
}

static void	load_dragon_left(t_datas *datas)
{
	int	i;

	datas->dragon->dragon[1][0] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][1] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][2] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][3] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][4] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][5] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][6] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	datas->dragon->dragon[1][7] = mlx_xpm_file_image(datas->mlx,
			"assets/dragon_left.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->dragon->dragon[0][i])
			ft_e_load(5);
	}
}

void	ft_load_foes(t_datas *datas)
{
	load_unicorn_right(datas);
	load_unicorn_left(datas);
	load_dragon_right(datas);
	load_dragon_left(datas);
}
