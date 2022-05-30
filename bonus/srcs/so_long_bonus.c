/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:22:42 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:30:05 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_args(char *arg)
{
	arg = ft_strrchr(arg, '.');
	if (ft_strnstr(arg, ".ber", 5) != 0 && *(arg + 4) == 0)
		return (1);
	return (0);
}

static void	ft_init(char *file)
{
	t_datas		*datas;

	datas = ft_init_datas(file);
	datas->mlx = mlx_init();
	ft_load_textures(datas);
	ft_load_player(datas);
	datas->win = mlx_new_window(datas->mlx, datas->map->size_x * TILESIZE,
			datas->map->size_y * TILESIZE, "so_long");
	mlx_key_hook(datas->win, ft_key_hook, datas);
	mlx_hook(datas->win, 17, 0, ft_close, datas);
	mlx_loop_hook(datas->mlx, ft_hook, datas);
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
