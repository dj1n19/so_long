/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:43:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/21 13:40:36 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATHFINDING_BONUS_H
# define PATHFINDING_BONUS_H

typedef struct s_list
{
	unsigned int	x;
	unsigned int	y;
	struct s_list	*next;
}	t_list;

typedef struct s_list_meta
{
	struct s_list	*head;
	struct s_list	*tail;
	unsigned int	size;
}	t_list_meta;

int				pathfinding(t_datas *datas, t_map *map,
					unsigned int px, unsigned int py);
t_list			*get_next(t_map *map, unsigned int **cost_map,
					t_list *node, t_list *head);
int				has_next(t_map *map, unsigned int x, unsigned int y);
void			free_all(t_map *map_cpy, unsigned int **cost_map,
					t_list_meta *meta, int free_mc);
t_list_meta		create_list(t_list *head, t_list *tail, t_list_meta *meta);
t_list			*create_node(unsigned int x, unsigned int y);
t_list_meta		*push_back(t_list *node, t_list_meta *meta);
t_list_meta		*pop_back(t_list_meta *meta);
int				include(unsigned int x, unsigned int y, t_list *head);
t_map			*create_map_cpy(t_map *map);
int				pathfinding_loop(t_map *map_cpy, unsigned int **cost_map,
					t_list_meta *meta, t_list *next);
unsigned int	**get_cost_map(t_map *map, t_map *map_cpy);
t_map			*copy_map(t_map *map);
void			is_item_valid(t_datas *datas);

#endif