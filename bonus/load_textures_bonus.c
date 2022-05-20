/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:02:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/19 17:12:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_load_corners(t_datas *datas)
{
	int	width;
	int	height;
	int	i;

	i = 0;
	width = TILESIZE;
	height = TILESIZE;
	datas->map->edges[0] = mlx_xpm_file_to_image(datas->mlx,
			"assets/corner_top_left.xpm", &width, &height);
	datas->map->edges[2] = mlx_xpm_file_to_image(datas->mlx,
			"assets/corner_top_right.xpm", &width, &height);
	datas->map->edges[4] = mlx_xpm_file_to_image(datas->mlx,
			"assets/corner_bottom_right.xpm", &width, &height);
	datas->map->edges[6] = mlx_xpm_file_to_image(datas->mlx,
			"assets/corner_bottom_left.xpm", &width, &height);
	while (i < 8)
	{
		if (!datas->map->edges[i])
		{
			ft_e_load(3, datas);
		}
		i += 2;
	}
}

static void	ft_load_edges(t_datas *datas)
{
	int	width;
	int	height;
	int	i;

	i = 1;
	width = TILESIZE;
	height = TILESIZE;
	datas->map->edges[1] = mlx_xpm_file_to_image(datas->mlx,
			"assets/edge_top.xpm", &width, &height);
	datas->map->edges[3] = mlx_xpm_file_to_image(datas->mlx,
			"assets/edge_right.xpm", &width, &height);
	datas->map->edges[5] = mlx_xpm_file_to_image(datas->mlx,
			"assets/edge_bottom.xpm", &width, &height);
	datas->map->edges[7] = mlx_xpm_file_to_image(datas->mlx,
			"assets/edge_left.xpm", &width, &height);
	while (i < 8)
	{
		if (!datas->map->edges[i])
			ft_e_load(3, datas);
		i += 2;
	}
}

static void	ft_load_item(t_datas *datas)
{
	int	width;
	int	height;

	width = TILESIZE;
	height = TILESIZE;
	datas->map->item = mlx_xpm_file_to_image(datas->mlx, "assets/chest.xpm",
			&width, &height);
	if (!datas->map->item)
		ft_e_load(2, datas);
}

static void	ft_load_player(t_datas *datas)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = TILESIZE;
	height = TILESIZE;
	datas->player->player[0] = mlx_xpm_file_to_image(datas->mlx,
			"assets/player_up.xpm", &width, &height);
	datas->player->player[1] = mlx_xpm_file_to_image(datas->mlx,
			"assets/player_right.xpm", &width, &height);
	datas->player->player[2] = mlx_xpm_file_to_image(datas->mlx,
			"assets/player_down.xpm", &width, &height);
	datas->player->player[3] = mlx_xpm_file_to_image(datas->mlx,
			"assets/player_left.xpm", &width, &height);
	datas->player->current = datas->player->player[1];
	while (i < 4)
	{
		if (!datas->player->player[i++])
			ft_e_load(1, datas);
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
	ft_load_corners(datas);
	ft_load_edges(datas);
	ft_load_item(datas);
	ft_load_player(datas);
	datas->map->ground = mlx_xpm_file_to_image(datas->mlx,
			"assets/grass.xpm", &width, &height);
	datas->map->wall = mlx_xpm_file_to_image(datas->mlx, "assets/trees.xpm",
			&width, &height);
	datas->map->exit_open = mlx_xpm_file_to_image(datas->mlx,
			"assets/portal_open.xpm", &width, &height);
	datas->map->exit_close = mlx_xpm_file_to_image(datas->mlx,
			"assets/portal_close.xpm", &width, &height);
	if (!datas->map->wall || !datas->map->ground || !datas->map->exit_open
		|| !datas->map->exit_close)
	{
		ft_e_load(4, datas);
	}
}
