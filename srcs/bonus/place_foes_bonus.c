/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_foes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:44:35 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	place_unicorn(t_foe *unicorn, t_textures *tex, int x, int y)
{
	unicorn->x = x * TILESIZE;
	unicorn->y = y * TILESIZE;
	unicorn->current = tex->unicorn_right[0];
}

static void	place_dragon(t_foe *dragon, t_textures *tex, int x, int y)
{
	dragon->x = x * TILESIZE;
	dragon->y = y * TILESIZE;
	dragon->current = tex->dragon_right[0];
}

void	ft_place_foes(t_datas *datas)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 1;
	while (y < datas->map->y - 1)
	{
		x = 1;
		while (x < datas->map->x - 1)
		{
			if (datas->map->map[y][x] == 'D')
				place_dragon(datas->foes[i++], datas->textures, x, y);
			else if (datas->map->map[y][x] == 'U')
				place_unicorn(datas->foes[i++], datas->textures, x, y);
			++x;
		}
		++y;
	}
}
