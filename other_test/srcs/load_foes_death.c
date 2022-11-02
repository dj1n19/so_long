/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:43:46 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/28 15:40:32 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_unicorn_death_right(void *mlx, void *unicorn_death_right[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_death_right[0] = mlx_xpm_file_to_image(mlx, UDR_1, &x, &y);
	unicorn_death_right[1] = mlx_xpm_file_to_image(mlx, UDR_2, &x, &y);
	unicorn_death_right[2] = mlx_xpm_file_to_image(mlx, UDR_3, &x, &y);
	unicorn_death_right[3] = mlx_xpm_file_to_image(mlx, UDR_4, &x, &y);
	unicorn_death_right[4] = mlx_xpm_file_to_image(mlx, UDR_5, &x, &y);
	unicorn_death_right[5] = mlx_xpm_file_to_image(mlx, UDR_6, &x, &y);
	unicorn_death_right[6] = mlx_xpm_file_to_image(mlx, UDR_7, &x, &y);
	unicorn_death_right[7] = mlx_xpm_file_to_image(mlx, UDR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_death_right[i])
			error_handler(E_TEX_FOE);
		i++;
	}
}

static void	load_unicorn_death_left(void *mlx, void *unicorn_death_left[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_death_left[0] = mlx_xpm_file_to_image(mlx, UDL_1, &x, &y);
	unicorn_death_left[1] = mlx_xpm_file_to_image(mlx, UDL_2, &x, &y);
	unicorn_death_left[2] = mlx_xpm_file_to_image(mlx, UDL_3, &x, &y);
	unicorn_death_left[3] = mlx_xpm_file_to_image(mlx, UDL_4, &x, &y);
	unicorn_death_left[4] = mlx_xpm_file_to_image(mlx, UDL_5, &x, &y);
	unicorn_death_left[5] = mlx_xpm_file_to_image(mlx, UDL_6, &x, &y);
	unicorn_death_left[6] = mlx_xpm_file_to_image(mlx, UDL_7, &x, &y);
	unicorn_death_left[7] = mlx_xpm_file_to_image(mlx, UDL_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_death_left[i])
			error_handler(E_TEX_FOE);
		i++;
	}
}

static void	load_dragon_death_right(void *mlx, void *dragon_death_right[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_death_right[0] = mlx_xpm_file_to_image(mlx, DDR_1, &x, &y);
	dragon_death_right[1] = mlx_xpm_file_to_image(mlx, DDR_2, &x, &y);
	dragon_death_right[2] = mlx_xpm_file_to_image(mlx, DDR_3, &x, &y);
	dragon_death_right[3] = mlx_xpm_file_to_image(mlx, DDR_4, &x, &y);
	dragon_death_right[4] = mlx_xpm_file_to_image(mlx, DDR_5, &x, &y);
	dragon_death_right[5] = mlx_xpm_file_to_image(mlx, DDR_6, &x, &y);
	dragon_death_right[6] = mlx_xpm_file_to_image(mlx, DDR_7, &x, &y);
	dragon_death_right[7] = mlx_xpm_file_to_image(mlx, DDR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_death_right[i])
			error_handler(E_TEX_FOE);
		i++;
	}
}

static void	load_dragon_death_left(void *mlx, void *dragon_death_left[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_death_left[0] = mlx_xpm_file_to_image(mlx, DDL_1, &x, &y);
	dragon_death_left[1] = mlx_xpm_file_to_image(mlx, DDL_2, &x, &y);
	dragon_death_left[2] = mlx_xpm_file_to_image(mlx, DDL_3, &x, &y);
	dragon_death_left[3] = mlx_xpm_file_to_image(mlx, DDL_4, &x, &y);
	dragon_death_left[4] = mlx_xpm_file_to_image(mlx, DDL_5, &x, &y);
	dragon_death_left[5] = mlx_xpm_file_to_image(mlx, DDL_6, &x, &y);
	dragon_death_left[6] = mlx_xpm_file_to_image(mlx, DDL_7, &x, &y);
	dragon_death_left[7] = mlx_xpm_file_to_image(mlx, DDL_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_death_left[i])
			error_handler(E_TEX_FOE);
		i++;
	}
}

void	load_foes_death(t_datas *datas)
{
	t_textures	*tex;

	tex = datas->textures;
	load_unicorn_death_right(datas->mlx, tex->unicorn_death_right);
	load_unicorn_death_left(datas->mlx, tex->unicorn_death_left);
	load_dragon_death_right(datas->mlx, tex->dragon_death_right);
	load_dragon_death_left(datas->mlx, tex->dragon_death_left);
}
