#ifndef PATHFINDING_H
# define PATHFINDING_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# define ABS(i) i < 0 ? -i : i

typedef struct s_map
{
    unsigned int    x;
    unsigned int    y;
    char            **map;
}   t_map;

void    error_handler(char *err);
int pathfinding(t_map *map, unsigned int px, unsigned int py);

#endif