/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:02:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	load_edges(t_datas *d, void *map_edges[8])
{
	int	w;
	int	h;
	int	i;

	i = 0;
	w = TILESIZE;
	h = TILESIZE;
	map_edges[0] = mlx_xpm_file_to_image(d->mlx, CTL, &w, &h);
	map_edges[1] = mlx_xpm_file_to_image(d->mlx, EDT, &w, &h);
	map_edges[2] = mlx_xpm_file_to_image(d->mlx, CTR, &w, &h);
	map_edges[3] = mlx_xpm_file_to_image(d->mlx, EDR, &w, &h);
	map_edges[4] = mlx_xpm_file_to_image(d->mlx, CBR, &w, &h);
	map_edges[5] = mlx_xpm_file_to_image(d->mlx, EDB, &w, &h);
	map_edges[6] = mlx_xpm_file_to_image(d->mlx, CBL, &w, &h);
	map_edges[7] = mlx_xpm_file_to_image(d->mlx, EDL, &w, &h);
	while (i < 8)
	{
		if (!map_edges[i])
		{
			error_handler(E_TEX_OBJ, d);
		}
		++i;
	}
}

static void	*load_portals(t_datas *d, void *portal_open[8], void *portal_close)
{
	int		w;
	int		h;
	int		i;

	w = TILESIZE;
	h = TILESIZE;
	portal_close = mlx_xpm_file_to_image(d->mlx, PCLOSED, &w, &h);
	portal_open[0] = mlx_xpm_file_to_image(d->mlx, POPEN_1, &w, &h);
	portal_open[1] = mlx_xpm_file_to_image(d->mlx, POPEN_2, &w, &h);
	portal_open[2] = mlx_xpm_file_to_image(d->mlx, POPEN_3, &w, &h);
	portal_open[3] = mlx_xpm_file_to_image(d->mlx, POPEN_4, &w, &h);
	portal_open[4] = mlx_xpm_file_to_image(d->mlx, POPEN_5, &w, &h);
	portal_open[5] = mlx_xpm_file_to_image(d->mlx, POPEN_6, &w, &h);
	portal_open[6] = mlx_xpm_file_to_image(d->mlx, POPEN_7, &w, &h);
	portal_open[7] = mlx_xpm_file_to_image(d->mlx, POPEN_8, &w, &h);
	i = 0;
	if (!portal_close)
		error_handler(E_TEX_OBJ, d);
	while (i < 8)
	{
		if (!portal_open[i])
			error_handler(E_TEX_OBJ, d);
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
	load_edges(datas, datas->textures->map_edges);
	datas->textures->portal_close = load_portals(datas,
			datas->textures->portal_open, datas->textures->portal_close);
	load_items(datas);
	load_player(datas);
	load_player_attack(datas);
	load_foes(datas);
	load_foes_attack(datas);
	load_foes_death(datas);
	datas->textures->ground = mlx_xpm_file_to_image(datas->mlx, GRND, &w, &h);
	datas->textures->wall = mlx_xpm_file_to_image(datas->mlx, WALL, &w, &h);
	if (!datas->textures->wall || !datas->textures->ground)
		error_handler(E_TEX_OBJ, datas);
}
