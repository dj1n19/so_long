/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:02:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/11 12:20:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	foe_anim_attack(t_foe *foe, t_textures *textures)
{
	if (foe->frame == 8)
		foe->frame = 0;
	if (foe->dir == 'R')
	{
		if (foe->type == 'U')
			foe->current = textures->unicorn_attack_right[foe->frame];
		else if (foe->type == 'D')
			foe ->current = textures->dragon_attack_right[foe->frame];
	}
	else if (foe->dir == 'L')
	{
		if (foe->type == 'U')
			foe->current = textures->unicorn_attack_left[foe->frame];
		else if (foe->type == 'D')
			foe->current = textures->dragon_attack_left[foe->frame];
	}
	foe->frame++;
}

static void	player_anim_attack(t_player *player, t_textures *textures)
{
	player->current = textures->player_attack[player->frame];
	player->frame++;
}

void	*ft_player_attack(t_datas *datas)
{
	void	*save;

	save = datas->player->current;
	while (1)
	{
		set_target(datas->player, datas->foes);
		player_anim_attack(datas->player, datas->textures);
		if (datas->player->frame > 7)
		{
			if (datas->player->target)
				datas->player->target->hp -= datas->player->dmg;
			if (datas->player->target && datas->player->target->hp <= 0)
				kill_target(datas->player);
			unset_target(datas, save);
			datas->pt_running = 0;
			pthread_exit(0);
		}
		usleep(100000);
	}
	return (datas);
}

void	ft_foe_attack(t_datas *datas)
{
	int	i;

	i = 0;
	while (datas->foes[i])
	{
		if (is_at_range(datas->foes[i], datas->player)
			&& datas->foes[i]->is_dead == 0)
		{
			datas->foes[i]->in_combat = 1;
			if (datas->foes[i]->frame == 8)
				datas->player->hp -= datas->foes[i]->dmg;
			foe_anim_attack(datas->foes[i], datas->textures);
		}
		else
			datas->foes[i]->in_combat = 0;
		i++;
	}
}
