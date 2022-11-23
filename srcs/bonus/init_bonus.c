/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:21:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/23 11:57:56 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

static void	init_map(t_datas *datas, char *file)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		error_handler(E_MALLOC, datas);
	map->is_portal_open = 0;
	map->frame = 0;
	map = load_map(datas, file, map);
	if (!map_check(map, &datas->items))
		error_handler(E_MAP, datas);
	datas->map = map;
}

static t_datas	*init_threads(t_datas *datas)
{
	pthread_t		*move_thread;
	pthread_t		*foe_thread;
	pthread_t		*item_thread;
	pthread_t		*player_thread;
	pthread_attr_t	*attr;

	move_thread = malloc(sizeof(pthread_t));
	foe_thread = malloc(sizeof(pthread_t));
	item_thread = malloc(sizeof(pthread_t));
	player_thread = malloc(sizeof(pthread_t));
	attr = malloc(sizeof(pthread_attr_t));
	if (!attr || !move_thread || !foe_thread || !item_thread || !player_thread)
		error_handler(E_MALLOC, datas);
	pthread_attr_init(attr);
	pthread_attr_setdetachstate(attr, PTHREAD_CREATE_DETACHED);
	datas->move_thread = move_thread;
	datas->foe_thread = foe_thread;
	datas->item_thread = item_thread;
	datas->player_thread = player_thread;
	datas->attr = attr;
	return (datas);
}

t_datas	*ft_init_datas(char *file)
{
	t_datas		*datas;

	datas = (t_datas *) malloc(sizeof(t_datas));
	if (!datas)
		error_handler(E_MALLOC, NULL);
	datas->mlx = NULL;
	datas->win = NULL;
	datas->player_thread = NULL;
	datas->move_thread = NULL;
	datas->foe_thread = NULL;
	datas->item_thread = NULL;
	datas->attr = NULL;
	datas->map = NULL;
	datas->player = NULL;
	datas->foes = NULL;
	datas->textures = NULL;
	datas->player = init_player();
	init_map(datas, file);
	init_foes(datas);
	datas = init_threads(datas);
	datas->textures = (t_textures *) malloc(sizeof(t_textures));
	if (!datas->textures)
		error_handler(E_MALLOC, datas);
	datas->keycode = -1;
	return (datas);
}
