/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:21:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/09 17:41:58 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static t_player	*init_player(t_datas *datas)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		ft_e_malloc(datas);
	player->hp = 200;
	player->damage = 30;
	player->frame = 0;
	player->is_attacking = 0;
	player->is_moving = 0;
	player->is_casting = 0;
	player->target = NULL;
	return (player);
}

static t_foe	*init_foe(t_datas *datas, char type)
{
	t_foe	*foe;

	foe = (t_foe *) malloc(sizeof(t_foe));
	if (!foe)
		ft_e_malloc(datas);
	foe->type = type;
	foe->frame = 0;
	foe->direction = 'R';
	foe->is_attacking = 0;
	foe->is_dead = 0;
	if (type == 'U')
	{
		foe->hp = 50;
		foe->damage = 5;
	}
	else if (type == 'D')
	{
		foe->hp = 100;
		foe->damage = 20;
	}
	return (foe);
}

static void	init_foes(t_datas *datas)
{
	int			foes_nbr;
	int			unicorns_nbr;
	int			dragons_nbr;
	int			i;

	i = 0;
	unicorns_nbr = ft_check_unicorns(datas->map);
	dragons_nbr = ft_check_dragons(datas->map);
	foes_nbr = unicorns_nbr + dragons_nbr;
	datas->foes = (t_foe **) malloc(sizeof(t_foe *) * foes_nbr + 1);
	if (!datas->foes)
		ft_e_malloc(datas);
	while (i < unicorns_nbr)
		datas->foes[i++] = init_foe(datas, 'U');
	while (i < foes_nbr)
		datas->foes[i++] = init_foe(datas, 'D');
	datas->foes[i] = NULL;
}

static void	init_map(t_datas *datas, char *file)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		ft_e_malloc(datas);
	map->portal_open = 0;
	map->frame = 0;
	datas->map = map;
	ft_load_map(file, datas);
	ft_check_map(datas);
}

t_datas	*ft_init_datas(char *file)
{
	t_datas		*datas;
	t_player	*player;
	t_map		*map;

	datas = (t_datas *) malloc(sizeof(t_datas));
	if (!datas)
		ft_e_malloc(NULL);
	datas->mlx = NULL;
	datas->win = NULL;
	datas->player = init_player(datas);
	init_map(datas, file);
	init_foes(datas);
	datas->keycode = -1;
	datas->exit_code = 0;
	datas->move_count = 0;
	return (datas);
}
