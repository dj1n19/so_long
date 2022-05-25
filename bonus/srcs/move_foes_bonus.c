/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_foes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:46:54 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/25 12:46:56 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	foe_anim_right(t_foe *foe)
{
	if (foe->frame == 8)
		foe->frame = 0;
	foe->pos_x += 8;
	foe->current = foe->foe[0][foe->frame];
	foe->frame++;
}

static void	foe_anim_left(t_foe *foe)
{
	if (foe->frame == 8)
		foe->frame = 0;
	foe->pos_x -= 8;
	foe->current = foe->foe[1][foe->frame];
	foe->frame++;
}

static void move_foe_right(t_map *map, t_foe *foe)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[foe->pos_y][(foe->pos_x + 64) / 64] != '1')
    {
        foe_anim_right(foe);
    }
    else
    {
        foe->direction = 'L';
        foe->frame = 0;
        foe_anim_left(foe);
    }
}

static void move_foe_left(t_map *map, t_foe *foe)
{
    char    **bp;

    bp = map->blueprint;
    if (bp[foe->pos_y][(foe->pos_x - 64) / 64] != '1')
        foe_anim_left(foe);
    else
    {
        foe->direction = 'R';
        foe->frame = 0;
        foe_anim_right(foe);
    }
}

void    ft_move_foes(t_datas *datas)
{
    t_foe   *foe;

    ft_foe_attack(datas);
    while (*datas->foes)
    {
        foe = *datas->foe
        if (foes->direction == 'R')
            move_foe_right(datas->map, foe);
        else if (foe->direction == 'L')
            move_foe_left(datas->map, foe);
        ++datas->foe;
    }
}