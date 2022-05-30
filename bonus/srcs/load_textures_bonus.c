/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:02:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:39:38 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_corners(t_datas *datas)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	width = TILESIZE;
	height = TILESIZE;
	datas->map->edges[0] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/corner_top_left.xpm", &width, &height);
	datas->map->edges[2] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/corner_top_right.xpm", &width, &height);
	datas->map->edges[4] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/corner_bottom_right.xpm", &width, &height);
	datas->map->edges[6] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/corner_bottom_left.xpm", &width, &height);
	while (i < 8)
	{
		if (!datas->map->edges[i])
		{
			ft_e_load(3, datas);
		}
		i += 2;
	}
}

static void	load_edges(t_datas *datas)
{
	int	width;
	int	height;
	int	i;

	i = 1;
	width = TILESIZE;
	height = TILESIZE;
	datas->map->edges[1] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/edge_top.xpm", &width, &height);
	datas->map->edges[3] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/edge_right.xpm", &width, &height);
	datas->map->edges[5] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/edge_bottom.xpm", &width, &height);
	datas->map->edges[7] = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/edge_left.xpm", &width, &height);
	while (i < 8)
	{
		if (!datas->map->edges[i])
			ft_e_load(3, datas);
		i += 2;
	}
}

static void	load_portals(t_datas *datas, void *mlx)
{
	int		w;
	int		h;
	int		i;
	void	**e;

	w = TILESIZE;
	h = TILESIZE;
	e = datas->map->exit_open;
	datas->map->exit_close = mlx_xpm_file_to_image(mlx,
		"../../assets/portal_close.xpm", &w, &h);
	e[0] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_1.xpm", &w, &h);
	e[1] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_2.xpm", &w, &h);
	e[2] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_3.xpm", &w, &h);
	e[3] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_4.xpm", &w, &h);
	e[4] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_5.xpm", &w, &h);
	e[5] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_6.xpm", &w, &h);
	e[6] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_7.xpm", &w, &h);
	e[7] = mlx_xpm_file_to_image(mlx, "../../assets/portal_open_8.xpm", &w, &h);
	i = 1;
	while (i < 8)
	{
		if (!e[i])
			ft_e_load(4, datas);
		i++;
	}
}

void	ft_load_textures(t_datas *datas)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = TILESIZE;
	height = TILESIZE;
	load_corners(datas);
	load_edges(datas);
	load_portals(datas, datas->mlx);
	ft_load_items(datas);
	ft_load_player(datas);
	ft_load_foes(datas);
	datas->map->ground = mlx_xpm_file_to_image(datas->mlx,
			"../../assets/grass.xpm", &width, &height);
	datas->map->wall = mlx_xpm_file_to_image(datas->mlx, "../../assets/trees.xpm",
			&width, &height);
	if (!datas->map->wall || !datas->map->ground)
	{
		ft_e_load(4, datas);
	}
}
