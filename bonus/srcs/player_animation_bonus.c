/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:53:15 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/01 15:09:47 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_player_anim_north(t_player *player)
{
	player->pos_y -= 8;
	player->current = player->player_up[player->frame];
	player->frame++;
}

void	ft_player_anim_east(t_player *player)
{
	player->pos_x += 8;
	player->current = player->player_right[player->frame];
	player->frame++;
}

void	ft_player_anim_south(t_player *player)
{
	player->pos_y += 8;
	player->current = player->player_down[player->frame];
	player->frame++;
}

void	ft_player_anim_west(t_player *player)
{
	player->pos_x -= 8;
	player->current = player->player_left[player->frame];
	player->frame++;
}
