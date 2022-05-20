/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:35:13 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 16:10:57 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "datas.h"
# include "error.h"
# include "libft.h"

void	ft_load_map(char *file, t_datas *datas);
void	ft_load_textures(t_datas *datas);
int		ft_draw(t_datas *datas);
void	ft_draw_map_objects(t_map *map, void *mlx, void *win);
int		ft_move(int keycode, t_datas *datas);
int		ft_check_map(t_datas *datas);
void	ft_e_open(t_datas *datas);
void	ft_e_map(int errnum, t_datas *datas);
void	ft_e_load(int errnum, t_datas *datas);
int		ft_close(t_datas *datas);
int		ft_key_hook(int keycode, t_datas *datas);

#endif
