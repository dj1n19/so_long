/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:12:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/22 14:21:10 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mandatory/so_long.h"

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

	i = 0;
	while (i < map->size_y)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

int	ft_close(t_datas *datas)
{
	int	exit_code;

	exit_code = 0;
	if (!datas || datas->exit_code == 1)
		exit_code = 1;
	if (datas->map->map)
		free_map(datas->map);
	if (datas->map)
		free(datas->map);
	if (datas->player)
		free(datas->player);
	if (datas->win)
		mlx_destroy_window(datas->mlx, datas->win);
	if (datas)
		free(datas);
	system("leaks so_long");
	exit(exit_code);
	return (0);
}
