/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:22:42 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 16:05:35 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	check_args(char *arg)
{
	arg = ft_strrchr(arg, '.');
	if (ft_strnstr(arg, ".ber", 5) != 0 && *(arg + 4) == 0)
		return (1);
	return (0);
}

static void	place_player(t_player *player, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size_y - 1)
	{
		j = 0;
		while (j < map->size_x - 1)
		{
			if (map->blueprint[i][j] == 'P')
			{
				player->pos_x = j;
				player->pos_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static t_datas	*init_datas(void)
{
	t_datas		*datas;
	t_map		*map;
	t_player	*player;

	datas = (t_datas *)malloc(sizeof(t_datas));
	if (!datas)
		ft_close(NULL);
	datas->exit_code = 1;
	datas->mlx = NULL;
	datas->win = NULL;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_close(datas);
	datas->map = map;
	player = (t_player *)malloc(sizeof(t_player));
	if (!player)
		ft_close(datas);
	datas->player = player;
	datas->map->portal_open = 0;
	datas->move_count = 0;
	datas->exit_code = 0;
	return (datas);
}

static void	ft_init(char *file)
{
	t_datas		*datas;

	datas = init_datas();
	datas->mlx = mlx_init();
	ft_load_map(file, datas);
	datas->collected = ft_check_map(datas);
	ft_load_textures(datas);
	place_player(datas->player, datas->map);
	datas->win = mlx_new_window(datas->mlx, datas->map->size_x * TILESIZE,
			datas->map->size_y * TILESIZE, "so_long");
	mlx_key_hook(datas->win, ft_key_hook, datas);
	mlx_hook(datas->win, 17, 0, ft_close, datas);
	mlx_loop_hook(datas->mlx, ft_draw, datas);
	mlx_loop(datas->mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("\e[31mERROR: %s\n\e[0m", E_ARGS);
		exit(EXIT_FAILURE);
	}
	if (!check_args(*++argv))
	{
		ft_printf("\e[31mERROR: %s\n\e[0m", E_FILE);
		exit(EXIT_FAILURE);
	}
	ft_init(*argv);
	return (0);
}
