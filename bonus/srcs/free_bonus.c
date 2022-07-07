/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:12:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:30:55 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/leaks.h"

static void	free_map(char **map)
{
	while (*map)
	{
		free(*map);
		map++;
	}
	free(*map);
}

static void free_foes(t_foe **foes)
{
	while(*foes)
	{
		free(*foes);
		foes++;
	}
	free(*foes);
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
	if (datas->foes)
	{
		free_foes(datas->foes);
		free(datas->foes);
	}
	if (datas)
		free(datas);
	check_leaks();
	exit(exit_code);
	return (0);
}
