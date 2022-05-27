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

static void load_unicorn_right(t_foe *unicorn, void *mlx)
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn[0][0] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][1] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][2] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][3] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][4] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][5] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][6] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	unicorn[0][7] = mlx_xpm_file_image(mlx,	"assets/unicorn_right.xpm", &x, &y);
	i = 0;
	while ( i < 8)
	{
		if (!unicorn[0][i])
			ft_e_load(5);
	}
}

static void	load_unicorn_left(t_foe *unicorn, void * mlx)
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn[1][0] = mlx_xpm_file_image(mlx,	"assets/unicorn_left.xpm", &x, &y);
	unicorn[1][1] = mlx_xpm_file_image(mlx,	"assets/unicorn_left.xpm", &x, &y);
	unicorn[1][2] = mlx_xpm_file_image(mlx,	"assets/unicorn_left.xpm", &x, &y);
	unicorn[1][3] = mlx_xpm_file_image(mlx,	"assets/unicorn_left.xpm", &x, &y);
	unicorn[1][4] = mlx_xpm_file_image(mlx, "assets/unicorn_left.xpm", &x, &y);
	unicorn[1][5] = mlx_xpm_file_image(mlx, "assets/unicorn_left.xpm", &x, &y);
	unicorn[1][6] = mlx_xpm_file_image(mlx, "assets/unicorn_left.xpm", &x, &y);
	unicorn[1][7] = mlx_xpm_file_image(mlx, "assets/unicorn_left.xpm", &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn[0][i])
			ft_e_load(5);
	}
}

static void load_dragon_right(t_foe *dragon, void *mlx)
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon[0][0] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][1] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][2] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][3] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][4] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][5] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][6] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	dragon[0][7] = mlx_xpm_file_image(mlx, "assets/dragon_right.xpm", &x, &y);
	i = 0;
	while ( i < 8)
	{
		if (!dragon[0][i])
			ft_e_load(5);
	}
}

static void	load_dragon_left(t_foe *dragon, void *mlx)
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon[1][0] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][1] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][2] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][3] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][4] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][5] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][6] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	dragon[1][7] = mlx_xpm_file_image(mlx, "assets/dragon_left.xpm", &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon[0][i])
			ft_e_load(5);
	}
}

void	ft_load_foes(t_datas *datas)
{
	while (*datas->foes)
	{
		if (*(datas->foes)->type = 'U')
		{
			load_unicorn_right(*datas->foes, datas->mlx);
			load_unicorn_left(*datas->foes, datas->mlx);
		}
		else if (*(datas->foes)->type = 'D')
		{
			load_dragon_right(*datas->foes, datas->mlx);
			load_dragon_left(*datas->foes, datas->mlx);			
		}
		datas->foes++;
	}
}
