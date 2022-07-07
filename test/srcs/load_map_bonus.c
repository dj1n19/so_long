/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:10:39 by bgenie            #+#    #+#             */
/*   Updated: 2022/05/21 02:32:01 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	get_map_size(char *file, t_datas *datas)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_e_open(datas);
	line = get_next_line(fd);
	x = ft_strlen(line) - 1;
	free(line);
	y++;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		y++;
	}
	datas->map->size_x = x;
	datas->map->size_y = y;
	close(fd);
}

void	ft_load_map(char *file, t_datas *datas)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	get_map_size(file, datas);
	datas->map->blueprint = (char **) calloc(sizeof(char *),
			datas->map->size_y + 1);
	if (!datas->map->blueprint)
		ft_e_malloc(datas);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_e_open(datas);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		datas->map->blueprint[i++] = line;
	}
	datas->map->blueprint[i] = NULL;
	if (!datas->map->blueprint)
		ft_e_map(1, datas);
	close(fd);
}
