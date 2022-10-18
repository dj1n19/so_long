/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:22:42 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/20 15:49:24 by bgenie           ###   ########.fr       */
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

static void test_item_anim(t_datas *datas)
{
	while (datas->it_running == 0)
	{
		datas->map->frame++;
		if (datas->map->frame > 7)
			datas->map->frame = 0;
		usleep(200000);
	}
}

static void	ft_init(char *file)
{
	t_datas		*datas;
	pthread_t	move_thread;
	pthread_t	foe_thread;
	pthread_t	item_thread;
	pthread_t	player_thread;
	pthread_attr_t	attr;
	t_img		img;

	datas = ft_init_datas(file);
	datas->mlx = mlx_init();
	load_textures(datas);
	//ft_printf("\e[33mGNAH ?\n\e[0m");
	ft_check_player(datas);
	ft_place_foes(datas);
	datas->win = mlx_new_window(datas->mlx, datas->map->x * TILESIZE,
			datas->map->y * TILESIZE, "so_long");
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	datas->attr = &attr;
	datas->foe_thread = &foe_thread;
	datas->item_thread = &item_thread;
	datas->player_thread = &player_thread;
	datas->move_thread = &move_thread;
	datas->pt_running = 0;
	datas->ft_running = 0;
	datas->it_running = 0;
	datas->mt_running = 0;
	datas->img = &img;
	//printf(">>>%lu\n", sizeof(img));
	pthread_create(datas->item_thread, datas->attr, test_item_anim, datas);
	pthread_create(datas->foe_thread, datas->attr, move_foes, datas);
	//mlx_key_hook(datas->win, ft_key_hook, datas);
	mlx_hook(datas->win, 2, 1L<<0, ft_key_down, datas);
	mlx_hook(datas->win, 3, 1L<<1, ft_key_up, datas);
	mlx_hook(datas->win, 17, 0, ft_close, datas);
	mlx_loop_hook(datas->mlx, ft_hook, datas);
	mlx_loop(datas->mlx);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("\e[31mERROR: %s\n\e[0m", "E_ARGS");
		exit(EXIT_FAILURE);
	}
	if (!check_args(*++argv))
	{
		ft_printf("\e[31mERROR: %s\n\e[0m", "E_FILE");
		exit(EXIT_FAILURE);
	}
	ft_init(*argv);
	return (0);
}
