/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_characters_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:18:03 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/02 14:51:23 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	draw_foes(t_datas *datas)
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

static void	draw_player(t_datas *datas)
{
	mlx_put_image_to_window(datas->mlx, datas->win, datas->player->current,
		datas->player->pos_x, datas->player->pos_y);
}

void	ft_draw_characters(t_datas *datas)
{
	draw_foes(datas);
	draw_player(datas);
}
