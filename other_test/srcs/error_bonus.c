/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:37:11 by bgenie            #+#    #+#             */
/*   Updated: 2022/11/11 16:54:58 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	error_handler(char *err)
{
	if (!err)
		perror("ERROR");
	else
		ft_printf("ERROR : %s\n", err);
	exit(EXIT_FAILURE);
}
