/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_foes_attack_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:19:28 by bgenie            #+#    #+#             */
/*   Updated: 2022/08/02 15:26:07 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void load_unicorn_attack_right(t_datas *datas, t_foe *unicorn, void *mlx)
{
    int     i;
    int     x;
    int     y;
    void    **u;

    u = unicorn->sprites_attack_right;
    x = TILESIZE;
    y = TILESIZE;
    u[0] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_1.xpm", &x, &y);
    u[1] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_2.xpm", &x, &y);
    u[2] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_3.xpm", &x, &y);
    u[3] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_4.xpm", &x, &y);
    u[4] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_5.xpm", &x, &y);
    u[5] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_6.xpm", &x, &y);
    u[6] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_7.xpm", &x, &y);
    u[7] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_r_8.xpm", &x, &y);
    i = 0;
    while (i < 8)
    {
        if (!u[i])
            ft_e_load(5, datas);
        i++;
    }
}

static void load_unicorn_attack_left(t_datas *datas, t_foe *unicorn, void *mlx)
{
    int     i;
    int     x;
    int     y;
    void    **u;

    u = unicorn->sprites_attack_left;
    x = TILESIZE;
    y = TILESIZE;
    u[0] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_1.xpm", &x, &y);
    u[1] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_2.xpm", &x, &y);
    u[2] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_3.xpm", &x, &y);
    u[3] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_4.xpm", &x, &y);
    u[4] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_5.xpm", &x, &y);
    u[5] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_6.xpm", &x, &y);
    u[6] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_7.xpm", &x, &y);
    u[7] = mlx_xpm_file_to_image(mlx, "../../assets/u_attack_l_8.xpm", &x, &y);
    i = 0;
    while (i < 8)
    {
        if (!u[i])
            ft_e_load(5, datas);
        i++;
    }
}

static void load_dragon_attack_right(t_datas *datas, t_foe *dragon, void *mlx)
{
    int     i;
    int     x;
    int     y;
    void    **d;

    d = dragon->sprites_attack_right;
    x = TILESIZE;
    y = TILESIZE;
    d[0] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_1.xpm", &x, &y);
    d[1] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_2.xpm", &x, &y);
    d[2] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_3.xpm", &x, &y);
    d[3] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_4.xpm", &x, &y);
    d[4] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_5.xpm", &x, &y);
    d[5] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_6.xpm", &x, &y);
    d[6] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_7.xpm", &x, &y);
    d[7] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_r_8.xpm", &x, &y);
    i = 0;
    while (i < 8)
    {
        if (!d[i])
            ft_e_load(5, datas);
        i++;
    }
}

static void load_dragon_attack_left(t_datas *datas, t_foe *dragon, void *mlx)
{
    int     i;
    int     x;
    int     y;
    void    **d;

    d = dragon->sprites_attack_left;
    x = TILESIZE;
    y = TILESIZE;
    d[0] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_1.xpm", &x, &y);
    d[1] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_2.xpm", &x, &y);
    d[2] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_3.xpm", &x, &y);
    d[3] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_4.xpm", &x, &y);
    d[4] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_5.xpm", &x, &y);
    d[5] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_6.xpm", &x, &y);
    d[6] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_7.xpm", &x, &y);
    d[7] = mlx_xpm_file_to_image(mlx, "../../assets/d_attack_l_8.xpm", &x, &y);
    i = 0;
    while (i < 8)
    {
        if (!d[i])
            ft_e_load(5, datas);
        i++;
    }
}

void    ft_load_foes_attack(t_datas *datas)
{
    int i;

    i = 0;
    while (datas->foes[i])
    {
        if (datas->foes[i]->type == 'U')
        {
            load_unicorn_attack_right(datas, datas->foes[i], datas->mlx);
            load_unicorn_attack_left(datas, datas->foes[i], datas->mlx);
        }
        else if (datas->foes[i]->type == 'D')
        {
            load_dragon_attack_right(datas, datas->foes[i], datas->mlx);
            load_dragon_attack_left(datas, datas->foes[i], datas->mlx);
        }
        i++;
    }
}