/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:12:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/21 14:15:00 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

void	clear_list(t_list_meta *meta)
{
	while (meta->size)
	{
		meta = pop_back(meta);
	}
}

void	free_map(t_map *map)
{
	int	i;
ft_printf("GNAH\n");
	i = 0;
	while (i < map->y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

static void	free_foes(t_foe **foes)
{
	while (*foes)
	{
		free(*foes);
		foes++;
	}
	free(*foes);
}

static void	free_threads(t_datas *datas)
{
	if (datas)
	{
		pthread_cancel(*datas->foe_thread);
		pthread_cancel(*datas->move_thread);
		pthread_cancel(*datas->player_thread);
		pthread_cancel(*datas->item_thread);
		if (datas->move_thread)
			free(datas->move_thread);
		if (datas->player_thread)
			free(datas->player_thread);
		if (datas->foe_thread)
			free(datas->foe_thread);
		if (datas->item_thread)
			free(datas->item_thread);
		if (datas->attr)
			free(datas->attr);
	}
}

int	ft_close(t_datas *datas)
{
	if (!datas)
		exit(0);
	free_threads(datas);
	if (datas->win)
		mlx_destroy_window(datas->mlx, datas->win);
	if (datas->map->map)
		free_map(datas->map);
	// if (datas->map->map)
	// 	free(datas->map->map);
	if (datas->map)
		free(datas->map);
	if (datas->player)
		free(datas->player);
	if (datas->foes)
	{
		free_foes(datas->foes);
		free(datas->foes);
	}
	if (datas->textures)
		free(datas->textures);
	if (datas)
		free(datas);
	system("leaks so_long");
	exit(0);
	return (0);
}
