/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_characters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:14:37 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:21:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->hp = 300;
	player->dmg = 50;
	player->frame = 0;
	player->move_count = 0;
	player->dir = 'R';
	player->target = NULL;
	player->current = NULL;
	return (player);
}

static t_foe	*init_foe(char type)
{
	t_foe	*foe;

	foe = (t_foe *) malloc(sizeof(t_foe));
	if (!foe)
		return (NULL);
	foe->type = type;
	foe->frame = 0;
	foe->dir = 'R';
	foe->in_combat = 0;
	foe->is_dead = 0;
	foe->current = NULL;
	if (type == 'U')
	{
		foe->hp = 100;
		foe->dmg = 10;
	}
	else if (type == 'D')
	{
		foe->hp = 200;
		foe->dmg = 15;
	}
	return (foe);
}

void	init_foes(t_datas *datas)
{
	int			foes_nbr;
	int			unicorns_nbr;
	int			dragons_nbr;
	int			i;

	unicorns_nbr = ft_check_unicorns(datas->map);
	dragons_nbr = ft_check_dragons(datas->map);
	foes_nbr = unicorns_nbr + dragons_nbr;
	datas->foes = (t_foe **) malloc(sizeof(t_foe *) * (foes_nbr + 1));
	if (!datas->foes)
		error_handler(E_MALLOC, datas);
	i = -1;
	while (++i < unicorns_nbr)
	{
		datas->foes[i] = init_foe('U');
		if (!datas->foes[i])
			error_handler(E_MALLOC, datas);
	}
	while (i < foes_nbr)
	{
		datas->foes[i++] = init_foe('D');
		if (!datas->foes[i - 1])
			error_handler(E_MALLOC, datas);
	}
	datas->foes[i] = NULL;
}
