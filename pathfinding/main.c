
#include "pathfinding.h"

void    error_handler(char *err)
{
    if (errno != 0)
        perror("ERROR");
    else if (err)
        dprintf(2, "\e[31mERROR: no argument\n\e[0m");
    else
        dprintf(2, "\e[31mERROR\e[0m");
    exit(1);
}

static t_map   *load_map(char *file, t_map *map)
{
    FILE            *f;
    char            *buf;
    size_t          buf_size;
    char            **cmap;
    unsigned int    i;

    f = fopen(file, "r");
    if (!f)
        error_handler(NULL);
    buf_size = 256;
    buf = malloc(buf_size);
    if (!buf)
        error_handler(NULL);
    map->x = getline(&buf, &buf_size, f) - 1;
    map->y = map->x;
    cmap = (char **) malloc(sizeof(char *) * map->y);
    if (!cmap)
        error_handler(NULL);
    i = 0;
    cmap[i++] = strdup(buf);
    while (i < map->y)
    {
        getline(&buf, &buf_size, f);
        cmap[i++] = strdup(buf);
    }
    map->map = cmap;
    fclose(f);
    return map;    
}

int main(int argc, char **argv)
{
    t_map   *map;

    if (argc != 2)
    {
        dprintf(2, "\e[31mERROR: no argument\n\e[0m");
        return 1;
    }
    ++argv;
    map = (t_map *) malloc(sizeof(t_map));
    if (!map)
        error_handler(NULL);
    map = load_map(*argv, map);
    for (int i = 0; i < map->y; i++)
        printf("%s", map->map[i]);
    printf(">>> %d <<<\n", pathfinding(map, 3, 1));
    return 0;
}