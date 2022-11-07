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

unsigned long    get_next(t_map *map, unsigned int **cost_map, unsigned int x, unsigned int y, unsigned long prev)
{
    unsigned int    lower_cost;
    unsigned long   next;

    lower_cost = UINT_MAX;
    next = prev;
    if (x - 1 != (unsigned int)prev && cost_map[y][x - 1] < lower_cost && map->map[y][x - 1] != '1')
    {
        lower_cost = cost_map[y][x - 1];
        next = ((unsigned long)y << 32);
        next += (unsigned long)(x - 1);
    }
    if (x + 1 != (unsigned int)prev && cost_map[y][x + 1] < lower_cost && map->map[y][x + 1] != '1')
    {
        lower_cost = cost_map[y][x + 1];
        next = ((unsigned long)y << 32);
        next += (unsigned long)(x + 1);
    }
    if (y - 1 != (unsigned int)(prev >> 32) && cost_map[y - 1][x] < lower_cost && map->map[y - 1][x] != '1')
    {
        lower_cost = cost_map[y - 1][x];
        next = ((unsigned long)(y - 1) << 32);
        next += (unsigned long)x;
    }
    if (y + 1 != (unsigned int)(prev >> 32) && cost_map[y + 1][x] < lower_cost && map->map[y + 1][x] != '1')
    {
        lower_cost = cost_map[y + 1][x];
        next = ((unsigned long)(y + 1) << 32);
        next += (unsigned long)x;
    }
    return next;
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
    unsigned int    x;
    unsigned int    y;
    unsigned long   next;
    unsigned long   prev;
    unsigned int    mvt;

    cost_map = get_cost_map(map);
    for (int i = 1; i < map->y - 1; ++i)
    {
        for (int j = 1; j < map->x -1; ++j)
            printf("%u ", cost_map[i][j]);
        printf("\n");
    }
    x = px;
    y = py;
    mvt = map->x * map->y;
    while (mvt--)
    {
        if (has_next(map, x, y) == 0)
            return 0;
        if (cost_map[y][x] == 0)
            return 1;
        if (has_next(map, x, y) == 1)
            map->map[y][x] = '1';
        next = get_next(map, cost_map, x, y, prev);
        prev = (unsigned long)x;
        prev += ((unsigned long)y << 32);
        x = (unsigned int)next;
        y = (unsigned int)(next >> 32);
        print_map(map, x, y);
        usleep(500000);
        system("clear");
    }
    return 0;
}