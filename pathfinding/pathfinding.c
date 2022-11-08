#include "pathfinding.h"

unsigned long   get_exit(t_map *map)
{
    unsigned int    x_exit;
    unsigned int    y_exit;
    unsigned long   exit_pos;

    y_exit = 1;
    while (y_exit < map->y - 1)
    {
        x_exit = 1;
        while (x_exit < map->x - 1)
        {
            if (map->map[y_exit][x_exit] == 'E')
            {
                exit_pos = ((unsigned long)y_exit << 32);
                exit_pos += (unsigned long)x_exit;
                return exit_pos;
            }
            ++x_exit;
        }
        ++y_exit;
    }
    return 0;
}

unsigned int    calc_cost(unsigned long exit_pos, unsigned int x, unsigned int y)
{
    unsigned int    dist;

    if ((unsigned int)(exit_pos >> 32) > y)
        dist = (unsigned int)(exit_pos >> 32) - y;
    else
        dist = y - (unsigned int)(exit_pos >> 32);
    if ((unsigned int)exit_pos > x)
        dist += ((unsigned int)(exit_pos)) - x;
    else
        dist += x - ((unsigned int)(exit_pos));
    return dist;
}

unsigned int **get_cost_map(t_map *map)
{
    unsigned long   exit_pos;
    unsigned int    x;
    unsigned int    y;
    unsigned int    **cost_map;

    cost_map = (unsigned int **) malloc(sizeof(unsigned int *) * map->y);
    if (!cost_map)
        error_handler(NULL);
    exit_pos = get_exit(map);
    y = 0;
    while (y < map->y)
    {
        x = 0;
        cost_map[y] = (unsigned int *) malloc(sizeof(unsigned int) * map->x);
        if (!cost_map[y])
            error_handler(NULL);
        while (x < map->x)
        {
                cost_map[y][x] = calc_cost(exit_pos, x, y);
            ++x;
        }
        ++y;
    }
    return cost_map;
}

t_list    *get_next(t_map *map, unsigned int **cost_map, t_list *node, t_list *head)
{
    unsigned int    lower_cost;
    unsigned long   next;
    t_list          *next_node;

    lower_cost = UINT_MAX;
    next = 0;
    if (!include(node->x - 1, node->y, head) && cost_map[node->y][node->x - 1] < lower_cost && map->map[node->y][node->x - 1] != '1')
    {
        lower_cost = cost_map[node->y][node->x - 1];
        next = ((unsigned long)node->y << 32);
        next += (unsigned long)(node->x - 1);
    }
    if (!include(node->x + 1, node->y, head) && cost_map[node->y][node->x + 1] < lower_cost && map->map[node->y][node->x + 1] != '1')
    {
        lower_cost = cost_map[node->y][node->x + 1];
        next = ((unsigned long)node->y << 32);
        next += (unsigned long)(node->x + 1);
    }
    if (!include(node->x, node->y - 1, head) && cost_map[node->y - 1][node->x] < lower_cost && map->map[node->y - 1][node->x] != '1')
    {
        lower_cost = cost_map[node->y - 1][node->x];
        next = ((unsigned long)(node->y - 1) << 32);
        next += (unsigned long)node->x;
    }
    if (!include(node->x, node->y + 1, head) && cost_map[node->y + 1][node->x] < lower_cost && map->map[node->y + 1][node->x] != '1')
    {
        lower_cost = cost_map[node->y + 1][node->x];
        next = ((unsigned long)(node->y + 1) << 32);
        next += (unsigned long)node->x;
    }
    if (next != 0)
        return (create_node((unsigned int)next, (unsigned int)(next >> 32)));
    return (NULL);
}

int has_next(t_map *map, unsigned int x, unsigned int y)
{
    int has_next;
    
    has_next = 0;
    if (map->map[y][x - 1] != '1')
        has_next++;
    if (map->map[y][x + 1] != '1')
        has_next++;
    if (map->map[y - 1][x] != '1')
        has_next++;
    if (map->map[y + 1][x] != '1')
        has_next++;
    return (has_next);
}

void    print_map(t_map *map, unsigned int x, unsigned int y)
{
    for (int i = 0; i < map->y; i++)
    {
        for (int j = 0; j < map->x; j++)
        {
            if (i == y && j == x)
                printf("\e[31m%c\e[0m", map->map[i][j]);
            else
                printf("%c", map->map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int pathfinding(t_map *map, unsigned int px, unsigned int py)
{
    unsigned int **cost_map;
    t_list          *next;
    t_list_meta     *meta;

    cost_map = get_cost_map(map);
    next = create_node(px, py);
    meta = create_list(NULL, NULL);
    while (1)
    {
        meta = push_back(next, meta);
        if (has_next(map, meta->tail->x, meta->tail->y) == 0)
            return 0;
        if (cost_map[meta->tail->y][meta->tail->x] == 0)
            return 1;
        next = get_next(map, cost_map, next, meta->head);
        if (!next)
        {
            map->map[meta->tail->y][meta->tail->x] = '1';
            meta = pop_back(meta);
            next = meta->tail;
        }
        print_map(map, meta->tail->x, meta->tail->y);
        usleep(250000);
        system("clear");
    }
    return 0;
}