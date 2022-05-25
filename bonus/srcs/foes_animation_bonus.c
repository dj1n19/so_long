/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foes_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 02:22:21 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:26:06 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_unicorn_anim_right(t_unicorn *unicorn)
{
	if (unicorn->frame == 8)
		unicorn->frame = 0;
	unicorn->pos_x += 8;
	unicorn->current = unicorn->unicorn[0][unicorn->frame];
	unicorn->frame++;
}

void	ft_unicorn_anim_left(t_unicorn *unicorn)
{
	if (unicorn->frame == 8)
		unicorn->frame = 0;
	unicorn->pos_x -= 8;
	unicorn->current = unicorn->unicorn[1][unicorn->frame];
	unicorn->frame++;
}

void	ft_dragon_anim_right(t_dragon *dragon)
{
	if (dragon->frame == 8)
		dragon->frame = 0;
	dragon->pos_x += 8;
	dragon->current = dragon->dragon[0][dragon->frame];
	dragon->frame++;
}

void	ft_dragon_anim_left(t_dragon *dragon)
{
	if (dragon->frame == 8)
		dragon->frame = 0;
	dragon->pos_x -= 8;
	dragon->current = dragon->dragon[1][dragon->frame];
	dragon->frame++;
}