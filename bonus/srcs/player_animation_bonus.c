/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:53:15 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:22:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_player_anim_north(t_player *player)
{
	if (player->frame == 8)
		player->frame = 0;
	player->pos_y -= 8;
	player->current = player->player[0][player->frame];
	player->frame++;
}

void	ft_player_anim_east(t_player *player)
{
	if (player->frame == 8)
		player->frame = 0;
	player->pos_x += 8;
	player->current = player->player[1][player->frame];
	player->frame++;
}

void	ft_player_anim_south(t_player *player)
{
	if (player->frame == 8)
		player->frame = 0;
	player->pos_y += 8;
	player->current = player->player[2][player->frame];
	player->frame++;
}

void	ft_player_anim_west(t_player *player)
{
	if (player->frame == 8)
		player->frame = 0;
	player->pos_x -= 8;
	player->current = player->player[3][player->frame];
	player->frame++;
}
