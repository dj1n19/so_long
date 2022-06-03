/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:06:07 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/03 13:41:17 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void load_unicorn_right(t_datas *datas, t_foe *unicorn, void *mlx)
{
	int		i;
	int		x;
	int		y;
	void	**u;

	u = unicorn->sprites_right;
	x = TILESIZE;
	y = TILESIZE;
	u[0] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_1.xpm", &x, &y);
	u[1] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_2.xpm", &x, &y);
	u[2] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_3.xpm", &x, &y);
	u[3] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_4.xpm", &x, &y);
	u[4] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_5.xpm", &x, &y);
	u[5] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_6.xpm", &x, &y);
	u[6] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_7.xpm", &x, &y);
	u[7] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_right_8.xpm", &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!u[i])
			ft_e_load(5, datas);
		i++;
	}
}

static void	load_unicorn_left(t_datas *datas, t_foe *unicorn, void * mlx)
{
	int		i;
	int		x;
	int		y;
	void	**u;

	u = unicorn->sprites_left;
	x = TILESIZE;
	y = TILESIZE;
	u[0] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_1.xpm", &x, &y);
	u[1] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_2.xpm", &x, &y);
	u[2] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_3.xpm", &x, &y);
	u[3] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_4.xpm", &x, &y);
	u[4] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_5.xpm", &x, &y);
	u[5] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_6.xpm", &x, &y);
	u[6] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_7.xpm", &x, &y);
	u[7] = mlx_xpm_file_to_image(mlx, "../../assets/unicorn_left_8.xpm", &x, &y);
	i = 0;
	while (i < 8)
	{
		if (!u[i])
			ft_e_load(5, datas);
		i++;
	}
}

static void load_dragon_right(t_datas *datas, t_foe *dragon, void *mlx)
{
	int		i;
	int		x;
	int		y;
	void	**d;

	d = dragon->sprites_right;
	x = TILESIZE;
	y = TILESIZE;
	d[0] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_1.xpm", &x, &y);
	d[1] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_2.xpm", &x, &y);
	d[2] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_3.xpm", &x, &y);
	d[3] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_4.xpm", &x, &y);
	d[4] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_5.xpm", &x, &y);
	d[5] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_6.xpm", &x, &y);
	d[6] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_7.xpm", &x, &y);
	d[7] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_right_8.xpm", &x, &y);
	i = 0;
	/*while ( i < 8)
	{
		if (!d[i])
			ft_e_load(5, datas);
	}*/
}

static void	load_dragon_left(t_datas *datas, t_foe *dragon, void *mlx)
{
	int		i;
	int		x;
	int		y;
	void	**d;

	d = dragon->sprites_left;
	x = TILESIZE;
	y = TILESIZE;
	d[0] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_1.xpm", &x, &y);
	d[1] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_2.xpm", &x, &y);
	d[2] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_3.xpm", &x, &y);
	d[3] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_4.xpm", &x, &y);
	d[4] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_5.xpm", &x, &y);
	d[5] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_6.xpm", &x, &y);
	d[6] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_7.xpm", &x, &y);
	d[7] = mlx_xpm_file_to_image(mlx, "../../assets/dragon_left_8.xpm", &x, &y);
	i = 0;
	/*while (i < 8)
	{
		if (!d[i])
			ft_e_load(5, datas);
	}*/
}

void	ft_load_foes(t_datas *datas)
{
	int	i;

	i = 0;
	while (datas->foes[i])
	{
		if (datas->foes[i]->type == 'U')
		{
			load_unicorn_right(datas, datas->foes[i], datas->mlx);
			load_unicorn_left(datas, datas->foes[i], datas->mlx);
		}
		else if (datas->foes[i]->type == 'D')
		{
			load_dragon_right(datas, datas->foes[i], datas->mlx);
			load_dragon_left(datas, datas->foes[i], datas->mlx);
		}
		i++;
	}
}
