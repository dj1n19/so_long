/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:22:42 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/13 15:53:26 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_args(char *arg)
{
	arg = ft_strrchr(arg, '.');
	if (!arg)
		error_handler(E_FILE);
	if (ft_strnstr(arg, ".ber", 5) != 0 && *(arg + 4) == 0)
		return (1);
	return (0);
}

static void	*item_anim(void *datas)
{
	while (((t_datas *)datas)->it_running == 0)
	{
		((t_datas *)datas)->map->frame++;
		if (((t_datas *)datas)->map->frame > 7)
			((t_datas *)datas)->map->frame = 0;
		usleep(200000);
	}
}

static t_datas	*init_datas(t_datas *datas, t_img *img)
{
	datas->win = mlx_new_window(datas->mlx, datas->map->x * TILESIZE,
			datas->map->y * TILESIZE, "so_long");
	datas->pt_running = 0;
	datas->ft_running = 0;
	datas->it_running = 0;
	datas->mt_running = 0;
	datas->img = img;
	pthread_create(datas->item_thread, datas->attr, item_anim, datas);
	pthread_create(datas->foe_thread, datas->attr, move_foes, datas);
	return (datas);
}

static void	ft_init(char *file)
{
	t_datas			*datas;
	t_img			img;

	datas = ft_init_datas(file);
	datas->mlx = mlx_init();
	load_textures(datas);
	ft_check_player(datas);
	ft_place_foes(datas);
	datas = init_datas(datas, &img);
	if (!pathfinding(datas->map, datas->player->x / TILESIZE,
			datas->player->y / TILESIZE))
		error_handler(E_PATH);
	mlx_hook(datas->win, 2, 1L << 0, ft_key_down, datas);
	mlx_hook(datas->win, 3, 1L << 1, ft_key_up, datas);
	mlx_hook(datas->win, 17, 0, ft_close, datas);
	mlx_loop_hook(datas->mlx, ft_hook, datas);
	mlx_loop(datas->mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		error_handler(E_ARGS);
	if (!check_args(*++argv))
		error_handler(E_FILE);
	ft_init(*argv);
	return (0);
}
