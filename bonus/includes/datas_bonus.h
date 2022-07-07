/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:15:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/10 16:06:08 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAS_BONUS_H
# define DATAS_BONUS_H
# define TILESIZE 64
/*
** edge_imgs[top_left, top, top_right, right, bot_right, bot, bot_left, left]
*/
typedef struct	s_map
{
	int		size_x;
	int		size_y;
	int		portal_open;
	int		frame;
	void	*edges[8];
	void	*ground;
	void	*wall;
	void	*exit_open[8];
	void	*exit_close;
	void	*item_chest[8];
	void	*item_gems[8];
	void	*item_crystal[8];
	void	*item_gold[8];
	char	**blueprint;
}				t_map;

typedef struct	s_player
{
	int				pos_x;
	int				pos_y;
	int				hp;
	int				frame;
	int				damage;
	int				is_attacking;
	int				is_moving;
	int				is_casting;
	int				spell_target;
	void			*portrait;
	void			*player_up[8];
	void			*player_right[8];
	void			*player_down[8];
	void			*player_left[8];
	void			*player_attack[8];
	void			*attack[8];
	void			*spell[8];
	void			*current;
	struct s_foe	*target;
}				t_player;

typedef struct	s_foe
{
	int		pos_x;
	int		pos_y;
	int		hp;
	int		frame;
	int		damage;
	int		is_attacking;
	int		is_dead;
	char	direction;
	char	type;	
	void	*sprites_right[8];
	void	*sprites_left[8];
	void	*sprites_attack_right[8];
	void	*sprites_attack_left[8];
	void	*sprites_death_right[8];
	void	*sprites_death_left[8];
	void	*current;
}				t_foe;

typedef struct	s_datas
{
	void				*mlx;
	void				*win;
	int					move_count;
	int					keycode;
	int					collected;
	int					exit_code;
	struct s_map		*map;
	struct s_player		*player;
	struct s_foe		**foes;
}				t_datas;

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

#endif
