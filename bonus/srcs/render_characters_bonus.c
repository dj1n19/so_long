/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_characters_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:18:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/23 16:32:12 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_unicorn(t_datas *datas)
{
	int	i;

	i = 0;
	while (datas->foes[i])
	{	
		mlx_put_image_to_window(datas->mlx, datas->win,
				datas->foes[i]->current,
				datas->foes[i]->pos_x, datas->foes[i]->pos_y);
		i++;
	}
}

static void	draw_dragon(t_datas *datas)
{
	//TO_DO
}

static void	draw_player(t_datas *datas);
{
	mlx_put_to_image(datas->mlx, datas->win, datas->player->current,
			datas->player->pos_x, datas->player->pos_x);
}

void	ft_draw_characters(t_datas *datas)
{
	draw_player(datas);
	draw_unicorn(datas);
	draw_dragon(datas);
}
