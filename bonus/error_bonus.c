/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:54:30 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/20 19:16:59 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_e_open(t_datas *datas)
{
	ft_printf("\e[31mERROR: %s\n\e[0m", E_OPEN);
	datas->exit_code = 1;
	ft_close(datas);
}

void	ft_e_map(int errnum, t_datas *datas)
{
	if (errnum == 1)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_NULL_MAP);
	else if (errnum == 2)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_WALL);
	else if (errnum == 3)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_ITEM);
	else if (errnum == 4)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_EXIT);
	else if (errnum == 5)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_START);
	else if (errnum == 6)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_MALLOC);
	datas->exit_code = 1;
	ft_close (datas);
}

void	ft_e_load(int errnum, t_datas *datas)
{
	if (errnum == 1)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_TEX_PLAYER);
	else if (errnum == 2)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_TEX_ITEM);
	else if (errnum == 3)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_TEX_EDGE);
	else if (errnum == 4)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_TEX_OBJ);
	else if (errnum == 5)
		ft_printf("\e[31mERROR: %s\n\e[0m", E_TEX_FOE);
	datas->exit_code = 1;
	ft_close(datas);
}
