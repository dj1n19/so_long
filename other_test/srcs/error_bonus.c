/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:37:11 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/30 15:23:16 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_handler(char *err)
{
	if (!err)
		perror("ERROR");
	else
		ft_printf("ERROR : %s\n", err);
	system("leaks a.out");
	exit(0);
}
