/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:17:51 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

int	is_at_range(t_foe *f, t_player *p)
{
	int	dist_x;
	int	dist_y;

	if (f->is_dead == 0)
	{
		dist_x = f->x - p->x;
		dist_y = f->y - p->y;
		if (dist_x < 0)
			dist_x = -dist_x;
		if (dist_y < 0)
			dist_y = -dist_y;
		if (dist_x < TILESIZE && dist_y < TILESIZE)
			return (1);
	}
	return (0);
}

void	kill_target(t_player *player)
{
	player->target->is_dead = 1;
	player->target->frame = 0;
	player->target = NULL;
}

void	unset_target(t_datas *datas, void *save)
{
	if (datas->player->target)
		datas->player->target->frame = 0;
	datas->player->target = NULL;
	datas->player->current = save;
	datas->player->frame = 0;
}

int	set_target(t_player *player, t_foe **foes)
{
	int	i;

	i = 0;
	while (foes[i])
	{
		if (is_at_range(foes[i], player))
		{
			player->target = foes[i];
			return (1);
		}
		++i;
	}
	return (0);
}
