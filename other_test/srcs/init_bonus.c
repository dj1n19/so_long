/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:21:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/20 15:50:36 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static t_player	*init_player(t_datas *datas)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	if (!player)
		exit(EXIT_FAILURE);
	player->hp = 300;
	player->dmg = 50;
	player->frame = 0;
	player->dir = 'R';
	player->target = NULL;
	player->current = NULL;
	return (player);
}

static t_foe	*init_foe(t_datas *datas, char type)
{
	t_foe	*foe;

	foe = (t_foe *) malloc(sizeof(t_foe));
	if (!foe)
		exit(EXIT_FAILURE);
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
	datas->foes = (t_foe **) malloc(sizeof(t_foe *) * (foes_nbr + 1));
	if (!datas->foes)
		exit(EXIT_FAILURE);
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
		exit(EXIT_FAILURE);
	map->is_portal_open = 0;
	map->frame = 0;
	map = load_map(file, map);
	//ft_printf("%d,%d\n", map->x, map->y);
	map_check(map, &datas->items);
	datas->map = map;
}

t_datas	*ft_init_datas(char *file)
{
	t_datas		*datas;
	t_player	*player;
	t_map		*map;

	datas = (t_datas *) malloc(sizeof(t_datas));
	if (!datas)
		exit(EXIT_FAILURE);
	datas->mlx = NULL;
	datas->win = NULL;
	datas->player = init_player(datas);
	init_map(datas, file);
	init_foes(datas);
	datas->textures = (t_textures *) malloc(sizeof(t_textures));
	if (!datas->textures)
		exit(EXIT_FAILURE);
	datas->keycode = -1;
	//datas->exit_code = 0;
	//datas->move_count = 0;
	return (datas);
}
