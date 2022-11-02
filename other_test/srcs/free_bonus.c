/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:12:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/30 15:16:31 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

int	ft_close(t_datas *datas)
{
	pthread_cancel(*datas->move_thread);
	pthread_cancel(*datas->player_thread);
	pthread_cancel(*datas->foe_thread);
	pthread_cancel(*datas->item_thread);
	if (datas->win)
		mlx_destroy_window(datas->mlx, datas->win);
	// if (datas->img)
	// 	mlx_destroy_image(datas->mlx, datas->img->img);
	mlx_destroy_image(datas->mlx, datas->textures->ground);
	if (datas->map->map)
		free_map(datas->map->map);
	if (datas->map->map)
		free(datas->map->map);
	if (datas->map)
		free(datas->map);
	if (datas->player)
		free(datas->player);
	free(datas->move_thread);
	free(datas->player_thread);
	free(datas->foe_thread);
	free(datas->item_thread);
	free(datas->attr);
	if (datas->foes)
	{
		free_foes(datas->foes);
		free(datas->foes);
	}
	if (datas->textures)
		free(datas->textures);
	if (datas)
		free(datas);
	//check_leaks();
	//system("leaks a.out");
	exit(0);
	return (0);
}
