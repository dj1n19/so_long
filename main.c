/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:54:00 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/09 16:57:31 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TEST
#include <stdio.h>
// END TEST
#include "so_long.h"

int	main(int argc, char **argv)
{
	char **map;

	if (argc < 2)
		exit(-1);
	map = ft_load_map(*++argv);
	int i = 0;
	while (i < 10)
		printf("%s", map[i]);
	return (0);
}
