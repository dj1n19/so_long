/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:25:04 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/19 15:51:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_load_up(t_player *player)
{
	int	i;

	i = 0;
	player->up[0] = mlx_file_to_image(mlx, "assets/player_up_1.xpm",
			&player->size_x, &player->size_y);
	player->up[1] = mlx_file_to_image(mlx, "assets/player_up_2.xpm",
			&player->size_x, &player->size_y);
	player->up[2] = mlx_file_to_image(mlx, "assets/player_up_3.xpm",
			&player->size_x, &player->size_y);
	player->up[3] = mlx_file_to_image(mlx, "assets/player_up_4.xpm",
			&player->size_x, &player->size_y);
	player->up[4] = mlx_file_to_image(mlx, "assets/player_up_5.xpm",
			&player->size_x, &player->size_y);
	player->up[5] = mlx_file_to_image(mlx, "assets/player_up_6.xpm",
			&player->size_x, &player->size_y);
	player->up[6] = mlx_file_to_image(mlx, "assets/player_up_7.xpm",
			&player->size_x, &player->size_y);
	player->up[7] = mlx_file_to_image(mlx, "assets/player_up_8.xpm",
			&player->size_x, &player->size_y);
	while (i < 8)
	{
		if (!player->up[i])
			ft_load_error(1);
	}
}

void	ft_load_right(t_player *player)
{
	int	i;

	i = 0;
	player->right[0] = mlx_file_to_image(mlx, "assets/player_right_1.xpm",
			&player->size_x, &player->size_y);
	player->right[1] = mlx_file_to_image(mlx, "assets/player_right_2.xpm",
			&player->size_x, &player->size_y);
	player->right[2] = mlx_file_to_image(mlx, "assets/player_right_3.xpm",
			&player->size_x, &player->size_y);
	player->right[3] = mlx_file_to_image(mlx, "assets/player_right_4.xpm",
			&player->size_x, &player->size_y);
	player->right[4] = mlx_file_to_image(mlx, "assets/player_right_5.xpm",
			&player->size_x, &player->size_y);
	player->right[5] = mlx_file_to_image(mlx, "assets/player_right_6.xpm",
			&player->size_x, &player->size_y);
	player->right[6] = mlx_file_to_image(mlx, "assets/player_right_7.xpm",
			&player->size_x, &player->size_y);
	player->right[7] = mlx_file_to_image(mlx, "assets/player_right_8.xpm",
			&player->size_x, &player->size_y);
	while (i < 8)
	{
		if (!player->right[i])
			ft_load_error(1);
	}
}

void	ft_load_right(t_player *player)
{
	int	i;

	i = 0;
	player->down[0] = mlx_file_to_image(mlx, "assets/player_down_1.xpm",
			&player->size_x, &player->size_y);
	player->down[1] = mlx_file_to_image(mlx, "assets/player_down_2.xpm",
			&player->size_x, &player->size_y);
	player->down[2] = mlx_file_to_image(mlx, "assets/player_down_3.xpm",
			&player->size_x, &player->size_y);
	player->down[3] = mlx_file_to_image(mlx, "assets/player_down_4.xpm",
			&player->size_x, &player->size_y);
	player->down[4] = mlx_file_to_image(mlx, "assets/player_down_5.xpm",
			&player->size_x, &player->size_y);
	player->down[5] = mlx_file_to_image(mlx, "assets/player_down_6.xpm",
			&player->size_x, &player->size_y);
	player->down[6] = mlx_file_to_image(mlx, "assets/player_down_7.xpm",
			&player->size_x, &player->size_y);
	player->down[7] = mlx_file_to_image(mlx, "assets/player_down_8.xpm",
			&player->size_x, &player->size_y);
	while (i < 8)
	{
		if (!player->down[i])
			ft_load_error(1);
	}
}

void	ft_load_left(t_player *player)
{
	int	i;

	i = 0;
	player->left[0] = mlx_file_to_image(mlx, "assets/player_left_1.xpm",
			&player->size_x, &player->size_y);
	player->left[1] = mlx_file_to_image(mlx, "assets/player_left_2.xpm",
			&player->size_x, &player->size_y);
	player->left[2] = mlx_file_to_image(mlx, "assets/player_left_3.xpm",
			&player->size_x, &player->size_y);
	player->left[3] = mlx_file_to_image(mlx, "assets/player_left_4.xpm",
			&player->size_x, &player->size_y);
	player->left[4] = mlx_file_to_image(mlx, "assets/player_left_5.xpm",
			&player->size_x, &player->size_y);
	player->left[5] = mlx_file_to_image(mlx, "assets/player_left_6.xpm",
			&player->size_x, &player->size_y);
	player->left[6] = mlx_file_to_image(mlx, "assets/player_left_7.xpm",
			&player->size_x, &player->size_y);
	player->left[7] = mlx_file_to_image(mlx, "assets/player_left_8.xpm",
			&player->size_x, &player->size_y);
	while (i < 8)
	{
		if (!player->left[i])
			ft_load_error(1);
	}
}

void	ft_load_player(t_player *player)
{
	ft_load_left(player);
	ft_load_right(player);
	ft_load_top(player);
	ft_load_bottom(player);
}
