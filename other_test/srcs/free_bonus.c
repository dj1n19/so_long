/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:12:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/13 15:35:03 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void print_list(t_list_meta *meta)
{
	t_list *node;

	node = meta->head;
	printf("=====%u=====\n", meta->size);
	while (node)
	{
		printf("node:[%p]\nnext:[%p]\n(%u,%u)\n\n", node, node->next, node->x, node->y);
		node = node->next;
	}
	printf("=====%u=====\n", meta->size);
}

void	clear_list(t_list_meta *meta)
{
	while (meta->size)
	{
		meta = pop_back(meta);
	}
}

static void	free_map(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
	free(*map);
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
	free(datas->move_thread);
	free(datas->player_thread);
	free(datas->foe_thread);
	free(datas->item_thread);
	free(datas->attr);
}

int	ft_close(t_datas *datas)
{
	pthread_cancel(*datas->move_thread);
	pthread_cancel(*datas->player_thread);
	pthread_cancel(*datas->foe_thread);
	pthread_cancel(*datas->item_thread);
	if (datas->win)
		mlx_destroy_window(datas->mlx, datas->win);
	// if (datas->img)
	// 	free(datas->img);
	if (datas->map->map)
		free_map(datas->map->map);
	if (datas->map->map)
		free(datas->map->map);
	if (datas->map)
		free(datas->map);
	if (datas->player)
		free(datas->player);
	free_threads(datas);
	if (datas->foes)
	{
		free_foes(datas->foes);
		free(datas->foes);
	}
	if (datas->textures)
		free(datas->textures);
	if (datas)
		free(datas);
	system("leaks a.out");
	exit(0);
	return (0);
}
