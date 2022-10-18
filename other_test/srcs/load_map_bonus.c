/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgenie <bgenie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:10:39 by bgenie            #+#    #+#             */
/*   Updated: 2022/09/11 15:18:53 by bgenie           ###   ########.fr       */
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
		//printf(">>%s\n", *map);
		if (size != ft_strlen(*map))
			return (0);
		++map;
	}
	//ft_printf("GNAH?\n");
	return (1);
}

t_map	*load_map(char *file, t_map *map_datas)
{
	char	**map;
	int		fd;
	int		i;

	get_map_size(file, map_datas);
	//ft_printf("X:%d, Y:%d\n", map_datas->x, map_datas->y);
	map = (char **) malloc(sizeof(char *) * (map_datas->y + 1));
	if (!map)
		return (NULL); // TODO ERROR 
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL); // TODO ERROR
	i = 0;
	printf("[[%p]]\n", map);
	while (i < map_datas->y)
	{
		map[i] = get_next_line(fd);
		printf("[%p]:%03d:%s", map[i], ft_strlen(map[i]), map[i]);
		++i;
	}
	map[i] = NULL;
	if (is_map_rect(map) == 0)
		exit(EXIT_FAILURE); // TODO ERROR
	map_datas->map = map;
	return (map_datas);
}
