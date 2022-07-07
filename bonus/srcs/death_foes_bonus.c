/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_foes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:10:06 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/09 16:19:13 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void    ft_foe_death_anim(t_foe *foe)
{
    if (foe->frame < 8)
    {
        if (foe->direction == 'L')
            foe->current = foe->sprites_death_left[foe->frame];
        else if (foe->direction == 'R')
                foe->current = foe->sprites_death_right[foe->frame];
        foe->frame++;
    }
    else
    {
        if (foe->direction == 'L')
            foe->current = foe->sprites_death_left[7];
        else if (foe->direction == 'R')
            foe->current = foe->sprites_death_right[7];
    }
}