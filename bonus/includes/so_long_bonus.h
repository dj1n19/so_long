/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:35:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/09 17:41:40 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "datas_bonus.h"
# include "error_bonus.h"
# include "libft.h"
# include <stdio.h>

void    ft_player_attack(t_datas *datas);
void    ft_foe_attack(t_datas *datas);
int     ft_check_unicorns(t_map *map);
int     ft_check_dragons(t_map *map);
void    ft_check_player(t_datas *datas);
void    ft_foe_death_anim(t_foe *foe);
void    ft_e_open(t_datas *datas);
void    ft_e_map(int errnum, t_datas *datas);
void    ft_e_load(int errnum, t_datas *datas);
void    ft_e_malloc(t_datas *datas);
int     ft_close(t_datas *datas);
int     ft_key_hook(int keycode, t_datas *datas);
int     ft_hook(t_datas *datas);
t_datas *ft_init_datas(char *file);
void    ft_load_foes_attack(t_datas *datas);
void    ft_load_foes(t_datas *datas);
void    ft_load_foes_death(t_datas *datas);
void    ft_load_items(t_datas *datas);
void    ft_load_map(char *file, t_datas *datas);
void    ft_load_player_attack(t_datas *datas);
void    ft_load_player(t_datas *datas);
void    ft_load_textures(t_datas *datas);
void    ft_check_map(t_datas *datas);
int     ft_move(int keycode, t_datas *datas);
void    ft_move_foes(t_datas *datas);
void    ft_move_player(int keycode, t_datas *datas);
void    ft_place_foes(t_datas *datas);
void    ft_player_anim_north(t_player *player);
void    ft_player_anim_east(t_player *player);
void    ft_player_anim_south(t_player *player);
void    ft_player_anim_west(t_player *player);
int     ft_draw(t_datas *datas);
void    ft_draw_characters(t_datas *datas);
void    ft_draw_items(t_datas *datas, char item, int x, int y);
void    ft_draw_map_objects(t_datas *datas);
void    ft_draw_spell(t_datas *datas);
void    ft_spell_cast(t_datas *datas);

#endif
