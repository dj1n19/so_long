/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:15:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/23 17:56:28 by bgenie           ###   ########.fr       */
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
	void	*items[4][8];
	char	**blueprint;
}				t_map;

typedef struct	s_player
{
	int		pos_x;
	int		pos_y;
	int		hp;
	int		frame;
	int		damage;
	void	*player[4][8];
	void	*current;
}				t_player;

typedef struct	s_foe
{
	int		pos_x;
	int		pos_y;
	int		hp;
	int		frame;
	int		damage;
	char	direction;
	char	type;	
	void	*sprites[3][8];
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
