/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_characters_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:18:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/28 14:23:30 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_foes(t_img *img, t_foe **foes)
{
	int	i;

	i = 0;
	while (foes[i])
	{	
		write_to_img(img, foes[i]->current, foes[i]->x, foes[i]->y);
		i++;
	}
}

static void	draw_player(t_img *img, t_player *player)
{
	write_to_img(img, player->current, player->x, player->y);
}

void	draw_characters(t_img *img, t_player *player, t_foe **foes)
{
	draw_foes(img, foes);
	draw_player(img, player);
}
