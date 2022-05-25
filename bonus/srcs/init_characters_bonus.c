/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_characters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:47:49 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/24 14:47:51 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    ft_init_player(t_datas *datas)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player *));
	if (!player)
		ft_e_malloc(datas);
	player->hp = 100;
	player->damage = 20;
	player->frame = 0;
	return (player);
}

t_unicorn	*ft_init_unicorn(t_datas *datas)
{
	t_unicorn	*unicorn;

	unicorn = (t_unicorn *) malloc(sizeof(t_unicorn));
	if (!unicorn)
		ft_e_malloc(datas);
	unicorn->hp = 50;
	unicorn->damage = 5;
	unicorn->frame = 0;
	return (unicorn);
}

t_dragon	*ft_init_dragon(t_datas *datas)
{
	t_dragon	*dragon;

	dragon = (t_dragon *) malloc(sizeof(t_dragon));
	if (!dragon)
		ft_e_malloc(datas);
	dragon->hp = 100;
	dragon->damage = 10;
	dragon->frame = 0;
	return (dragon);
}
