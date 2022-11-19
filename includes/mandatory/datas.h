/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datas.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:15:20 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/19 14:52:21 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATAS_H
# define DATAS_H
# define TILESIZE 64

//edge_imgs[top_left, top, top_right, right, bot_right, bot, bot_left, left]
typedef struct	s_map
{
	int		size_x;
	int		size_y;
	int		portal_open;
	void	*edges[8];
	void	*ground;
	void	*wall;
	void	*exit_open;
	void	*exit_close;
	void	*item;
	char	**map;
}				t_map;

typedef struct	s_player
{
	int		size_x;
	int		size_y;
	int		pos_x;
	int		pos_y;
	void	*player[4];
	void	*current;
}				t_player;

typedef struct	s_datas
{
	void			*mlx;
	void			*win;
	int				move_count;
	int				keycode;
	int				collected;
	int				exit_code;
	struct s_map	*map;
	struct s_player	*player;
}				t_datas;

typedef enum	e_directions
{
	SOUTH = 1,
	NORTH = 13,
	EAST = 2,
	WEST = 0,
	ESC = 53,
}				t_directions;

#endif
