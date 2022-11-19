/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:46:54 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	foe_anim_right(t_foe *foe, t_textures *textures)
{
	foe->x += 8;
	if (foe->type == 'U')
		foe->current = textures->unicorn_right[foe->frame];
	else if (foe->type == 'D')
		foe->current = textures->dragon_right[foe->frame];
	foe->frame++;
}

static void	foe_anim_left(t_foe *foe, t_textures *textures)
{
	foe->x -= 8;
	if (foe->type == 'U')
		foe->current = textures->unicorn_left[foe->frame];
	else if (foe->type == 'D')
		foe->current = textures->dragon_left[foe->frame];
	foe->frame++;
}

static void	move_foe_right(t_map *map, t_foe *foe, t_textures *textures)
{
	if (map->map[foe->y / 64][(foe->x + 64) / 64] == '1')
	{
		foe->dir = 'L';
		foe->frame = 0;
		foe_anim_left(foe, textures);
	}
	else
	{
		if (foe->frame == 8)
			foe->frame = 0;
		foe_anim_right(foe, textures);
	}
}

static void	move_foe_left(t_map *map, t_foe *foe, t_textures *textures)
{
	if (map->map[foe->y / 64][((foe->x - 64) / 64) + 1] == '1')
	{
		foe->dir = 'R';
		foe->frame = 0;
		foe_anim_right(foe, textures);
	}
	else
	{
		if (foe->frame == 8)
			foe->frame = 0;
		foe_anim_left(foe, textures);
	}
}

void	*move_foes(void *d)
{
	t_datas	*datas;
	t_foe	*foe;
	int		i;

	datas = (t_datas *)d;
	while (datas->ft_running == 0)
	{
		i = 0;
		ft_foe_attack(datas);
		while (datas->foes[i])
		{
			foe = datas->foes[i];
			if (foe->is_dead == 1)
				foe_death(foe, datas->textures);
			if (foe->dir == 'R' && foe->in_combat == 0 && foe->is_dead == 0)
				move_foe_right(datas->map, foe, datas->textures);
			else if (foe->dir == 'L' && foe->in_combat == 0
				&& foe->is_dead == 0)
				move_foe_left(datas->map, foe, datas->textures);
			++i;
		}
		usleep(50000);
	}
	return (d);
}
