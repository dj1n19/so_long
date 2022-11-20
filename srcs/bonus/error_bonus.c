/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:37:11 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/20 15:40:18 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/bonus/so_long_bonus.h"

void	error_handler(char *err, t_datas *datas)
{
	if (!err)
		perror("ERROR\n");
	else
		ft_printf("ERROR\n%s\n", err);
	ft_close(datas);
}
