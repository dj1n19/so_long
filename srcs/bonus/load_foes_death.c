/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:43:46 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	load_unicorn_death_right(t_datas *d, void *unicorn_death_right[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_death_right[0] = mlx_xpm_file_to_image(d->mlx, UDR_1, &x, &y);
	unicorn_death_right[1] = mlx_xpm_file_to_image(d->mlx, UDR_2, &x, &y);
	unicorn_death_right[2] = mlx_xpm_file_to_image(d->mlx, UDR_3, &x, &y);
	unicorn_death_right[3] = mlx_xpm_file_to_image(d->mlx, UDR_4, &x, &y);
	unicorn_death_right[4] = mlx_xpm_file_to_image(d->mlx, UDR_5, &x, &y);
	unicorn_death_right[5] = mlx_xpm_file_to_image(d->mlx, UDR_6, &x, &y);
	unicorn_death_right[6] = mlx_xpm_file_to_image(d->mlx, UDR_7, &x, &y);
	unicorn_death_right[7] = mlx_xpm_file_to_image(d->mlx, UDR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_death_right[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

static void	load_unicorn_death_left(t_datas *d, void *unicorn_death_left[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	unicorn_death_left[0] = mlx_xpm_file_to_image(d->mlx, UDL_1, &x, &y);
	unicorn_death_left[1] = mlx_xpm_file_to_image(d->mlx, UDL_2, &x, &y);
	unicorn_death_left[2] = mlx_xpm_file_to_image(d->mlx, UDL_3, &x, &y);
	unicorn_death_left[3] = mlx_xpm_file_to_image(d->mlx, UDL_4, &x, &y);
	unicorn_death_left[4] = mlx_xpm_file_to_image(d->mlx, UDL_5, &x, &y);
	unicorn_death_left[5] = mlx_xpm_file_to_image(d->mlx, UDL_6, &x, &y);
	unicorn_death_left[6] = mlx_xpm_file_to_image(d->mlx, UDL_7, &x, &y);
	unicorn_death_left[7] = mlx_xpm_file_to_image(d->mlx, UDL_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!unicorn_death_left[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

static void	load_dragon_death_right(t_datas *d, void *dragon_death_right[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_death_right[0] = mlx_xpm_file_to_image(d->mlx, DDR_1, &x, &y);
	dragon_death_right[1] = mlx_xpm_file_to_image(d->mlx, DDR_2, &x, &y);
	dragon_death_right[2] = mlx_xpm_file_to_image(d->mlx, DDR_3, &x, &y);
	dragon_death_right[3] = mlx_xpm_file_to_image(d->mlx, DDR_4, &x, &y);
	dragon_death_right[4] = mlx_xpm_file_to_image(d->mlx, DDR_5, &x, &y);
	dragon_death_right[5] = mlx_xpm_file_to_image(d->mlx, DDR_6, &x, &y);
	dragon_death_right[6] = mlx_xpm_file_to_image(d->mlx, DDR_7, &x, &y);
	dragon_death_right[7] = mlx_xpm_file_to_image(d->mlx, DDR_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_death_right[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

static void	load_dragon_death_left(t_datas *d, void *dragon_death_left[8])
{
	int	i;
	int	x;
	int	y;

	x = TILESIZE;
	y = TILESIZE;
	dragon_death_left[0] = mlx_xpm_file_to_image(d->mlx, DDL_1, &x, &y);
	dragon_death_left[1] = mlx_xpm_file_to_image(d->mlx, DDL_2, &x, &y);
	dragon_death_left[2] = mlx_xpm_file_to_image(d->mlx, DDL_3, &x, &y);
	dragon_death_left[3] = mlx_xpm_file_to_image(d->mlx, DDL_4, &x, &y);
	dragon_death_left[4] = mlx_xpm_file_to_image(d->mlx, DDL_5, &x, &y);
	dragon_death_left[5] = mlx_xpm_file_to_image(d->mlx, DDL_6, &x, &y);
	dragon_death_left[6] = mlx_xpm_file_to_image(d->mlx, DDL_7, &x, &y);
	dragon_death_left[7] = mlx_xpm_file_to_image(d->mlx, DDL_8, &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!dragon_death_left[i])
			error_handler(E_TEX_FOE, d);
		i++;
	}
}

void	load_foes_death(t_datas *datas)
{
	t_textures	*tex;

	tex = datas->textures;
	load_unicorn_death_right(datas, tex->unicorn_death_right);
	load_unicorn_death_left(datas, tex->unicorn_death_left);
	load_dragon_death_right(datas, tex->dragon_death_right);
	load_dragon_death_left(datas, tex->dragon_death_left);
}
