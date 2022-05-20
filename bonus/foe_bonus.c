/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:06:07 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 19:17:38 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void load_unicorn_right(t_datas *datas)
{
	int	i;

	datas->foe_tex[0][0] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][1] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][2] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][3] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][4] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][5] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][6] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[0][7] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_right.xpm", TILESIZE, TILESIZE);
	i = 0;
	while ( i < 8)
	{
		if (!datas->foe_tex[0][i])
			ft_e_load(5);
	}
}

static void	load_unicorn_left(t_datas *datas)
{
	int	i;

	datas->foe_tex[1][0] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][1] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][2] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][3] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][4] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][5] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][6] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	datas->foe_tex[1][7] = mlx_xpm_file_image(datas->mlx,
			"assets/unicorn_left.xpm", TILESIZE, TILESIZE);
	i = 0;
	while (i < 8)
	{
		if (!datas->foe_tex[0][i])
			ft_e_load(5);
	}
}

void	load_foe(t_datas *datas)
{
	load_unicorn_right(datas);
	load_unicorn_left(datas);

}
