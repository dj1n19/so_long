/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:35:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/10 17:13:12 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include "mlx.h"
# include "assets_bonus.h"
# include "structures_bonus.h"
# include "error_bonus.h"
# include "pathfinding.h"
# include "libft.h"
# define TILESIZE 64
# define ABS(x) if (x < 0) x = -x
// TEST
//# include "leaks.h"
# include <stdio.h>
// TEST

typedef enum	e_keys
{
	SOUTH = 1,
	NORTH = 13,
	EAST = 2,
	WEST = 0,
	ESC = 53,
	LETTER_E = 14,
	NUM_1 = 18
}				t_keys;

int     map_check(t_map *map, int *items);
t_map   *load_map(char *file, t_map *map_datas);
void    load_foes(t_datas *datas);
void    load_foes_attack(t_datas *datas);
void    load_foes_death(t_datas *datas);
void    load_items(t_datas *datas);
void    load_player_attack(t_datas *datas);
void    load_player(t_datas *datas);
void    load_textures(t_datas *datas);
void    write_to_img(t_img *dst_img, void *src_datas, int x, int y);
void    draw_map_objects(t_img *img, t_datas *datas);
void    draw_items(t_img *img, t_datas *datas, int x, int y);
void    draw_characters(t_img *img, t_player *player, t_foe **foes);
void	draw_spell(t_img *img, t_player *player, t_textures *tex);
int     draw(t_datas *datas);
void    move_player(t_datas *datas);
void    *move_foes(void *datas);
void    foe_death(t_foe *foe, t_textures *textures);
void	error_handler(char *err);

// OLD

void    *ft_player_attack(t_datas *datas);
void    ft_foe_attack(t_datas *datas);
int     ft_check_unicorns(t_map *map);
int     ft_check_dragons(t_map *map);
void    ft_check_player(t_datas *datas);
//void    ft_foe_death_anim(t_foe *foe);
void    ft_e_open(t_datas *datas);
void    ft_e_map(int errnum, t_datas *datas);
void    ft_e_load(int errnum, t_datas *datas);
void    ft_e_malloc(t_datas *datas);
int     ft_close(t_datas *datas);
int     ft_key_hook(int keycode, t_datas *datas);
int     ft_hook(t_datas *datas);
t_datas *ft_init_datas(char *file);
//void    ft_load_foes_attack(t_datas *datas);
//void    ft_load_foes(t_datas *datas);
//void    ft_load_foes_death(t_datas *datas);
//void    ft_load_items(t_datas *datas);
//void    ft_load_map(char *file, t_datas *datas);
//void    ft_load_player_attack(t_datas *datas);
//void    ft_load_player(t_datas *datas);
//void    ft_load_textures(t_datas *datas);
//void    ft_check_map(t_datas *datas);
int     ft_move(int keycode, t_datas *datas);
//void    ft_move_foes(t_datas *datas);
//void    ft_move_player(t_datas *datas);
void    ft_place_foes(t_datas *datas);
void    ft_player_anim_north(t_player *player, t_textures *textures);
void    ft_player_anim_east(t_player *player, t_textures *textures);
void    ft_player_anim_south(t_player *player, t_textures *textures);
void    ft_player_anim_west(t_player *player, t_textures *textures);
//int     ft_draw(t_datas *datas);
//void    ft_draw_characters(t_datas *datas);
//void    ft_draw_items(t_datas *datas, char item, int x, int y);
//void    ft_draw_map_objects(t_datas *datas);
void    ft_draw_spell(t_datas *datas);
void    *ft_spell_cast(void *datas);


int ft_key_up(int keycode, t_datas *datas);
int ft_key_down(int keycode, t_datas *datas);

#endif
