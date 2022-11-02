/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:54:54 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/29 11:51:25 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct  s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
}   t_img;

typedef struct  s_textures
{
    void    *ground;
    void    *wall;
    void    *portal_close;
    void    *map_edges[8];
    void    *portal_open[8];
    void    *chest[8];
    void    *gems[8];
    void    *crystal[8];
    void    *gold[8];
    void    *player_up[8];
    void    *player_down[8];
    void    *player_left[8];
    void    *player_right[8];
    void    *player_attack[8];
    void    *player_sfx[8];
    void    *player_spell[8];
    void    *unicorn_left[8];
    void    *unicorn_right[8];
    void    *unicorn_death_left[8];
    void    *unicorn_death_right[8];
    void    *unicorn_attack_left[8];
    void    *unicorn_attack_right[8];
    void    *dragon_left[8];
    void    *dragon_right[8];
    void    *dragon_death_left[8];
    void    *dragon_death_right[8];
    void    *dragon_attack_left[8];
    void    *dragon_attack_right[8];
}   t_textures;

typedef struct  s_foe
{
    int     x;
    int     y;
    int     hp;
    int     frame;
    int     dmg;
    int     in_combat;
    int     is_dead;
    char    type;
    char    dir;
    void    *current;
}   t_foe;

typedef struct  s_player
{
    int     x;
    int     y;
    int     hp;
    int     frame;
    int     dmg;
    int     move_count;
    char    dir;
    int     is_attacking;
    char    spell_target;
    void    *current;
    t_foe   *target;
}   t_player;


typedef struct  s_map
{
    int     x;
    int     y;
    int     is_portal_open;
    int     frame;
    char    **map;    
}   t_map;

typedef struct  s_datas
{
    void                *mlx;
    void                *win;
    int                 moves;
    int                 items;
    int                 pt_running;
    int                 mt_running;
    int                 it_running;
    int                 ft_running;
    int                 keycode;
    struct s_img        *img;
    struct s_textures   *textures;
    struct s_player     *player;
    struct s_foe        **foes;
    struct s_map        *map;
    pthread_t           *player_thread;
    pthread_t           *move_thread;
    pthread_t           *foe_thread;
    pthread_t           *item_thread;
    pthread_attr_t      *attr;
}   t_datas;

#endif