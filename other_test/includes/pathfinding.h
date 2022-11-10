#ifndef PATHFINDING_H
# define PATHFINDING_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

typedef struct s_list
{
    unsigned int    x;
    unsigned int    y;
    struct s_list   *next;
}   t_list;

typedef struct s_list_meta
{
    struct s_list   *head;
    struct s_list   *tail;
    unsigned int    size;
}   t_list_meta;


void    error_handler(char *err);
int pathfinding(t_map *map, unsigned int px, unsigned int py);

t_list_meta *create_list(t_list *head, t_list *tail);
t_list      *create_node(unsigned int x, unsigned int y);
t_list_meta *push_back(t_list *node, t_list_meta *meta);
t_list_meta *push_front(t_list *node, t_list_meta *meta);
t_list_meta *pop_back(t_list_meta *meta);
t_list_meta *pop_front(t_list_meta *meta);
int         include(unsigned int x, unsigned int y, t_list *head);

#endif