/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_player_attack_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 13:55:22 by bgenie            #+#    #+#             */
/*   Updated: 2022/06/03 14:45:39 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void load_player_anim_attack(t_datas *datas, void *mlx)
{
    int		i;
	int		w;
	int		h;
	void	**p;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player->player_attack;
	i = 0;
	p[0] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_1.xpm", &w, &h);
	p[1] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_2.xpm", &w, &h);
	p[2] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_3.xpm", &w, &h);
	p[3] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_4.xpm", &w, &h);
	p[4] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_5.xpm", &w, &h);
	p[5] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_6.xpm", &w, &h);
	p[6] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_7.xpm", &w, &h);
	p[7] = mlx_xpm_file_to_image(mlx, "../../assets/p_anim_att_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[i])
			ft_e_load(1, datas);
		i++;
	}
}

static void load_player_attack(t_datas *datas, void *mlx)
{
    int		i;
	int		w;
	int		h;
	void	**p;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player->attack;
	i = 0;
	p[0] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_1.xpm", &w, &h);
	p[1] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_2.xpm", &w, &h);
	p[2] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_3.xpm", &w, &h);
	p[3] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_4.xpm", &w, &h);
	p[4] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_5.xpm", &w, &h);
	p[5] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_6.xpm", &w, &h);
	p[6] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_7.xpm", &w, &h);
	p[7] = mlx_xpm_file_to_image(mlx, "../../assets/p_att_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[i])
			ft_e_load(1, datas);
		i++;
	}
}

static void load_player_spell(t_datas *datas, void *mlx)
{
    int		i;
	int		w;
	int		h;
	void	**p;

	w = TILESIZE;
	h = TILESIZE;
	p = datas->player->spell;
	i = 0;
	p[0] = mlx_xpm_file_to_image(mlx, "../../assets/spell_1.xpm", &w, &h);
	p[1] = mlx_xpm_file_to_image(mlx, "../../assets/spell_2.xpm", &w, &h);
	p[2] = mlx_xpm_file_to_image(mlx, "../../assets/spell_3.xpm", &w, &h);
	p[3] = mlx_xpm_file_to_image(mlx, "../../assets/spell_4.xpm", &w, &h);
	p[4] = mlx_xpm_file_to_image(mlx, "../../assets/spell_5.xpm", &w, &h);
	p[5] = mlx_xpm_file_to_image(mlx, "../../assets/spell_6.xpm", &w, &h);
	p[6] = mlx_xpm_file_to_image(mlx, "../../assets/spell_7.xpm", &w, &h);
	p[7] = mlx_xpm_file_to_image(mlx, "../../assets/spell_8.xpm", &w, &h);
	while (i < 8)
	{
		if (!p[i])
			ft_e_load(1, datas);
		i++;
	}
}

void    ft_load_player_attack(t_datas *datas)
{
    load_player_anim_attack(datas, datas->mlx);
    load_player_attack(datas, datas->mlx);
    load_player_spell(datas, datas->mlx);
}