/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_foes_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:10:06 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/14 15:29:26 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void foe_death_anim_right(t_foe *foe, t_textures *textures)
{
    if (foe->frame < 8)
    {
        if (foe->type == 'U')
            foe->current = textures->unicorn_death_right[foe->frame];
        else if (foe->type == 'D')
            foe->current = textures->dragon_death_right[foe->frame];
        ++foe->frame;
    }
    else
    {
        if (foe->type == 'U')
            foe->current = textures->unicorn_death_right[7];
        else if (foe->type == 'D')
            foe->current = textures->dragon_death_right[7];
    }
}

static void foe_death_anim_left(t_foe *foe, t_textures *textures)
{
    if (foe->frame < 8)
    {
        if (foe->type == 'U')
            foe->current = textures->unicorn_death_left[foe->frame];
        else if (foe->type == 'D')
            foe->current = textures->dragon_death_left[foe->frame];
        ++foe->frame;
    }
    else
    {
        if (foe->type == 'U')
            foe->current = textures->unicorn_death_left[7];
        else if (foe->type == 'D')
            foe->current = textures->dragon_death_left[7];
    }
}

void    foe_death(t_foe *foe, t_textures *textures)
{
    if (foe->dir == 'R')
        foe_death_anim_right(foe, textures);
    else if (foe->dir == 'L')
        foe_death_anim_left(foe, textures);
}