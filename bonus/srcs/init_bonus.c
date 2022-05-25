/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:21:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/23 17:56:42 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static t_datas	*init_foes(t_datas *datas)
{
	t_unicorn	**unicorns;
	t_dragon	**dragons;
	int			unicorns_nbr;
	int			dragons_nbr;
	int			i;

	i = 0;
	unicorns_nbr = ft_check_unicorns(datas->map);
	dragons_nbr = ft_check_dragons(datas->map);
	unicorns = (t_unicorn **) calloc(sizeof(t_unicorn *), unicorns_number);
	if (!unicorns)
		ft_e_malloc(datas);
	dragons = (t_dragon **) calloc(sizeof(t_dragon *), dragon_count);
	if (!dragons)
		ft_e_malloc(datas);
	while (i < unicorns_nbr)
		unicorns[i++] = ft_init_unicorn(datas);
	i = 0;
	while (i < dragons_nbr)
		dragons[i++] = ft_init_dragon(datas);
	datas->unicorns = unicorns;
	datas->dragons = dragons;
	return (datas);
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
	player = init_player(datas);
	datas->player = player;
	init_map(file, datas);
	datas = init_foes(datas);
	datas->keycode = -1;
	datas->exit_code = 0;
	datas->move_count = 0;
	return (datas);
}
