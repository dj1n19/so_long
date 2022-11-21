/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:35:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/21 13:37:40 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <pthread.h>
# include <errno.h>
# include <limits.h>
# include <stdio.h>
# include "mlx.h"
# include "assets_bonus.h"
# include "structures_bonus.h"
# include "error_bonus.h"
# include "pathfinding_bonus.h"
# include "libft.h"
# define TILESIZE 64

typedef enum e_keys
{
	SOUTH = 1,
	NORTH = 13,
	EAST = 2,
	WEST = 0,
	ESC = 53,
	LETTER_E = 14,
	NUM_1 = 18
}				t_keys;

void		*ft_player_attack(void *d);
void		ft_foe_attack(t_datas *datas);
int			is_at_range(t_foe *f, t_player *p);
void		kill_target(t_player *player);
void		unset_target(t_datas *datas, void *save);
int			set_target(t_player *player, t_foe **foes);
int			ft_check_unicorns(t_map *map);
int			ft_check_dragons(t_map *map);
void		ft_check_player(t_datas *datas);
void		foe_death(t_foe *foe, t_textures *textures);
void		error_handler(char *err, t_datas *datas);
int			ft_close(t_datas *datas);
int			ft_key_up(int keycode, t_datas *datas);
int			ft_key_down(int keycode, t_datas *datas);
int			ft_hook(t_datas *datas);
t_datas		*ft_init_datas(char *file);
t_player	*init_player(void);
void		init_foes(t_datas *datas);
void		load_foes_attack(t_datas *datas);
void		load_foes(t_datas *datas);
void		load_foes_death(t_datas *datas);
void		load_items(t_datas *datas);
t_map		*load_map(t_datas *datas, char *file, t_map *map_datas);
void		load_player_attack(t_datas *datas);
void		load_player(t_datas *datas);
void		load_textures(t_datas *datas);
int			map_check(t_map *map, int *items);
void		*move_foes(void *d);
void		*move_player(void *datas);
void		ft_place_foes(t_datas *datas);
void		ft_player_anim_north(t_player *player, t_textures *textures);
void		ft_player_anim_east(t_player *player, t_textures *textures);
void		ft_player_anim_south(t_player *player, t_textures *textures);
void		ft_player_anim_west(t_player *player, t_textures *textures);
void		write_to_img(t_img *dst_img, void *src_datas, int x, int y);
int			draw(t_datas *d);
void		draw_characters(t_img *img, t_player *player, t_foe **foes);
void		draw_items(t_img *img, t_datas *datas, int x, int y);
void		draw_map(t_img *img, t_textures *textures, t_map *map);
void		draw_map_objects(t_img *img, t_datas *datas);
void		draw_spell(t_img *img, t_player *p, t_textures *tex);
void		*ft_spell_cast(void *dt);
void		loot_item(t_datas *datas);
void		clear_list(t_list_meta *meta);
void		reset_player_anim(t_datas *datas);
void		free_map(t_map *map);

#endif
