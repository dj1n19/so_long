/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:06:07 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/15 15:34:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_unicorn_right(void *mlx, void *unicorn_right[8])
{
	int		i;
	int		x;
	int		y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_right[0] = mlx_xpm_file_to_image(mlx, UMR_1, &x, &y);
	unicorn_right[1] = mlx_xpm_file_to_image(mlx, UMR_2, &x, &y);
	unicorn_right[2] = mlx_xpm_file_to_image(mlx, UMR_3, &x, &y);
	unicorn_right[3] = mlx_xpm_file_to_image(mlx, UMR_4, &x, &y);
	unicorn_right[4] = mlx_xpm_file_to_image(mlx, UMR_5, &x, &y);
	unicorn_right[5] = mlx_xpm_file_to_image(mlx, UMR_6, &x, &y);
	unicorn_right[6] = mlx_xpm_file_to_image(mlx, UMR_7, &x, &y);
	unicorn_right[7] = mlx_xpm_file_to_image(mlx, UMR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_right[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_unicorn_left(void *mlx, void *unicorn_left[8])
{
	int		i;
	int		x;
	int		y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_left[0] = mlx_xpm_file_to_image(mlx, UML_1, &x, &y);
	unicorn_left[1] = mlx_xpm_file_to_image(mlx, UML_2, &x, &y);
	unicorn_left[2] = mlx_xpm_file_to_image(mlx, UML_3, &x, &y);
	unicorn_left[3] = mlx_xpm_file_to_image(mlx, UML_4, &x, &y);
	unicorn_left[4] = mlx_xpm_file_to_image(mlx, UML_5, &x, &y);
	unicorn_left[5] = mlx_xpm_file_to_image(mlx, UML_6, &x, &y);
	unicorn_left[6] = mlx_xpm_file_to_image(mlx, UML_7, &x, &y);
	unicorn_left[7] = mlx_xpm_file_to_image(mlx, UML_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_left[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_dragon_right(void *mlx, void *dragon_right[8])
{
	int		i;
	int		x;
	int		y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_right[0] = mlx_xpm_file_to_image(mlx, DMR_1, &x, &y);
	dragon_right[1] = mlx_xpm_file_to_image(mlx, DMR_2, &x, &y);
	dragon_right[2] = mlx_xpm_file_to_image(mlx, DMR_3, &x, &y);
	dragon_right[3] = mlx_xpm_file_to_image(mlx, DMR_4, &x, &y);
	dragon_right[4] = mlx_xpm_file_to_image(mlx, DMR_5, &x, &y);
	dragon_right[5] = mlx_xpm_file_to_image(mlx, DMR_6, &x, &y);
	dragon_right[6] = mlx_xpm_file_to_image(mlx, DMR_7, &x, &y);
	dragon_right[7] = mlx_xpm_file_to_image(mlx, DMR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_right[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

static void	load_dragon_left(void *mlx, void *dragon_left[8])
{
	int		i;
	int		x;
	int		y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_left[0] = mlx_xpm_file_to_image(mlx, DML_1, &x, &y);
	dragon_left[1] = mlx_xpm_file_to_image(mlx, DML_2, &x, &y);
	dragon_left[2] = mlx_xpm_file_to_image(mlx, DML_3, &x, &y);
	dragon_left[3] = mlx_xpm_file_to_image(mlx, DML_4, &x, &y);
	dragon_left[4] = mlx_xpm_file_to_image(mlx, DML_5, &x, &y);
	dragon_left[5] = mlx_xpm_file_to_image(mlx, DML_6, &x, &y);
	dragon_left[6] = mlx_xpm_file_to_image(mlx, DML_7, &x, &y);
	dragon_left[7] = mlx_xpm_file_to_image(mlx, DML_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_left[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
}

void	load_foes(t_datas *datas)
{
	t_textures	*tex;

	tex = datas->textures;
	load_unicorn_right(datas->mlx, tex->unicorn_right);
	load_unicorn_left(datas->mlx, tex->unicorn_left);
	load_dragon_right(datas->mlx, tex->dragon_right);
	load_dragon_left(datas->mlx, tex->dragon_left);
}
