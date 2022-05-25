/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:25:04 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:38:50 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_up(t_datas *datas)
{
	int			i;
	int			w;
	int			h;
	void		***p;
	void		*mlx;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player;
	mlx = datas->mlx;
	i = 0;
	p[0][0] = mlx_xpm_file_to_image(mlx, "assets/player_up_1.xpm", &w, &h);
	p[0][1] = mlx_xpm_file_to_image(mlx, "assets/player_up_2.xpm", &w, &h);
	p[0][2] = mlx_xpm_file_to_image(mlx, "assets/player_up_3.xpm", &w, &h);
	p[0][3] = mlx_xpm_file_to_image(mlx, "assets/player_up_4.xpm", &w, &h);
	p[0][4] = mlx_xpm_file_to_image(mlx, "assets/player_up_5.xpm", &w, &h);
	p[0][5] = mlx_xpm_file_to_image(mlx, "assets/player_up_6.xpm", &w, &h);
	p[0][6] = mlx_xpm_file_to_image(mlx, "assets/player_up_7.xpm", &w, &h);
	p[0][7] = mlx_xpm_file_to_image(mlx, "assets/player_up_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[0][i])
			ft_load_error(1, datas);
		i++;
	}
}

static void	load_right(t_datas *datas)
{
	int	i;
	int			w;
	int			h;
	void		***p;
	void		*mlx;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player;
	mlx = datas->mlx;
	i = 0;
	p[1][0] = mlx_xpm_file_to_image(mlx, "assets/player_right_1.xpm", &w, &h);
	p[1][1] = mlx_xpm_file_to_image(mlx, "assets/player_right_2.xpm", &w, &h);
	p[1][2] = mlx_xpm_file_to_image(mlx, "assets/player_right_3.xpm", &w, &h);
	p[1][3] = mlx_xpm_file_to_image(mlx, "assets/player_right_4.xpm", &w, &h);
	p[1][4] = mlx_xpm_file_to_image(mlx, "assets/player_right_5.xpm", &w, &h);
	p[1][5] = mlx_xpm_file_to_image(mlx, "assets/player_right_6.xpm", &w, &h);
	p[1][6] = mlx_xpm_file_to_image(mlx, "assets/player_right_7.xpm", &w, &h);
	p[1][7] = mlx_xpm_file_to_image(mlx, "assets/player_right_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[1][i])
			ft_load_error(1, datas);
		i++;
	}
}

static void	load_down(t_datas *datas)
{
	int	i;
	int			w;
	int			h;
	void		***p;
	void		*mlx;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player;
	mlx = datas->mlx;
	i = 0;
	p[2][0] = mlx_xpm_file_to_image(mlx, "assets/player_down_1.xpm", &w, &h);
	p[2][1] = mlx_xpm_file_to_image(mlx, "assets/player_down_2.xpm", &w, &h);
	p[2][2] = mlx_xpm_file_to_image(mlx, "assets/player_down_3.xpm", &w, &h);
	p[2][3] = mlx_xpm_file_to_image(mlx, "assets/player_down_4.xpm", &w, &h);
	p[2][4] = mlx_xpm_file_to_image(mlx, "assets/player_down_5.xpm", &w, &h);
	p[2][5] = mlx_xpm_file_to_image(mlx, "assets/player_down_6.xpm", &w, &h);
	p[2][6] = mlx_xpm_file_to_image(mlx, "assets/player_down_7.xpm", &w, &h);
	p[2][7] = mlx_xpm_file_to_image(mlx, "assets/player_down_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[2][i])
			ft_load_error(1, datas);
		i++;
	}
}

static void	load_left(t_datas *datas)
{
	int	i;
	int			w;
	int			h;
	void		***p;
	void		*mlx;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player;
	mlx = datas->mlx;
	i = 0;
	p[3][0] = mlx_xpm_file_to_image(mlx, "assets/player_left_1.xpm", &w, &h);
	p[3][1] = mlx_xpm_file_to_image(mlx, "assets/player_left_2.xpm", &w, &h);
	p[3][2] = mlx_xpm_file_to_image(mlx, "assets/player_left_3.xpm", &w, &h);
	p[3][3] = mlx_xpm_file_to_image(mlx, "assets/player_left_4.xpm", &w, &h);
	p[3][4] = mlx_xpm_file_to_image(mlx, "assets/player_left_5.xpm", &w, &h);
	p[3][5] = mlx_xpm_file_to_image(mlx, "assets/player_left_6.xpm", &w, &h);
	p[3][6] = mlx_xpm_file_to_image(mlx, "assets/player_left_7.xpm", &w, &h);
	p[3][7] = mlx_xpm_file_to_image(mlx, "assets/player_left_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[3][i])
			ft_load_error(1, datas);
		i++;
	}
}

void	ft_load_player(t_datas *datas)
{
	load_left(datas);
	load_right(datas);
	load_top(datas);
	load_bottom(datas);
}
