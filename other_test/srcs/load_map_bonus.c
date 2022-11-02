/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:10:39 by bgenie            #+#    #+#             */
/*   Updated: 2022/10/31 14:56:10 by bgenie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	get_map_size(char *file, t_map *map)
{
	int		fd;
	int		x;
	int		y;
	char	*line;

	x = 0;
	y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
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
	map->x = x;
	map->y = y;
	close(fd);
}

static int	is_map_rect(char **map)
{
	int	size;	

	if (!map)
		return (-1);
	size = ft_strlen(*map);
	while (*map)
	{
		if ((size_t)size != ft_strlen(*map))
			return (0);
		++map;
	}
	return (1);
}

t_map	*load_map(char *file, t_map *map_datas)
{
	char	**map;
	int		fd;
	int		i;

	get_map_size(file, map_datas);
	map = (char **) malloc(sizeof(char *) * (map_datas->y + 1));
	if (!map)
		error_handler(E_MALLOC);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handler(NULL);
	i = 0;
	while (i < map_datas->y)
	{
		map[i] = get_next_line(fd);
		++i;
	}
	map[i] = NULL;
	if (is_map_rect(map) == 0)
		error_handler(E_MAP);
	map_datas->map = map;
	return (map_datas);
}
