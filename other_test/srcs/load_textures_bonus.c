/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:02:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/18 17:13:55 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	load_edges(void *mlx, void *map_edges[8])
{
	int	w;
	int	h;
	int	i;

	i = 0;
	w = TILESIZE;
	h = TILESIZE;
	map_edges[0] = mlx_xpm_file_to_image(mlx, CTL, &w, &h);
	map_edges[1] = mlx_xpm_file_to_image(mlx, EDT, &w, &h);
	map_edges[2] = mlx_xpm_file_to_image(mlx, CTR, &w, &h);
	map_edges[3] = mlx_xpm_file_to_image(mlx, EDR, &w, &h);
	map_edges[4] = mlx_xpm_file_to_image(mlx, CBR, &w, &h);
	map_edges[5] = mlx_xpm_file_to_image(mlx, EDB, &w, &h);
	map_edges[6] = mlx_xpm_file_to_image(mlx, CBL, &w, &h);
	map_edges[7] = mlx_xpm_file_to_image(mlx, EDL, &w, &h);
	while (i < 8)
	{
		if (!map_edges[i])
		{
			exit(EXIT_FAILURE); // TODO ERROR
		}
		++i;
	}
}

static void	*load_portals(void *mlx, void *portal_open[8], void *portal_close)
{
	int		w;
	int		h;
	int		i;

	w = TILESIZE;
	h = TILESIZE;
	portal_close = mlx_xpm_file_to_image(mlx, PCLOSED, &w, &h);
	portal_open[0] = mlx_xpm_file_to_image(mlx, POPEN_1, &w, &h);
	portal_open[1] = mlx_xpm_file_to_image(mlx, POPEN_2, &w, &h);
	portal_open[2] = mlx_xpm_file_to_image(mlx, POPEN_3, &w, &h);
	portal_open[3] = mlx_xpm_file_to_image(mlx, POPEN_4, &w, &h);
	portal_open[4] = mlx_xpm_file_to_image(mlx, POPEN_5, &w, &h);
	portal_open[5] = mlx_xpm_file_to_image(mlx, POPEN_6, &w, &h);
	portal_open[6] = mlx_xpm_file_to_image(mlx, POPEN_7, &w, &h);
	portal_open[7] = mlx_xpm_file_to_image(mlx, POPEN_8, &w, &h);
	i = 0;
	if (!portal_close)
		exit(EXIT_FAILURE);
	while (i < 8)
	{
		if (!portal_open[i])
			exit(EXIT_FAILURE); // TODO ERROR
		i++;
	}
	return (portal_close);
}

void	load_textures(t_datas *datas)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	w = TILESIZE;
	h = TILESIZE;
	load_edges(datas->mlx, datas->textures->map_edges);
	datas->textures->portal_close = load_portals(datas->mlx,
		datas->textures->portal_open, datas->textures->portal_close);
	ft_printf("[%p]\n", datas->textures->portal_open[0]);
	load_items(datas);
	load_player(datas);
	load_player_attack(datas);
	load_foes(datas);
	load_foes_attack(datas);
	load_foes_death(datas);
	datas->textures->ground = mlx_xpm_file_to_image(datas->mlx, GRND, &w, &h);
	datas->textures->wall = mlx_xpm_file_to_image(datas->mlx, WALL, &w, &h);
	if (!datas->textures->wall || !datas->textures->ground)
		exit(EXIT_FAILURE); // TODO ERROR
}
