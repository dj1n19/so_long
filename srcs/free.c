/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:12:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 16:04:52 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
	free(*map);
}

int	ft_close(t_datas *datas)
{
	int	exit_code;

	exit_code = 0;
	if (!datas || datas->exit_code == 1)
		exit_code = 1;
	if (datas->map->blueprint)
		free_map(datas->map->blueprint);
	if (datas->map->blueprint)
		free(datas->map->blueprint);
	if (datas->map)
		free(datas->map);
	if (datas->player)
		free(datas->player);
	if (datas->win)
		mlx_destroy_window(datas->mlx, datas->win);
	if (datas)
		free(datas);
	exit(exit_code);
	return (0);
}
