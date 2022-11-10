#include "../includes/so_long_bonus.h"

static unsigned long	get_next_x(t_map *map,
	unsigned int **cost_map, t_list *node, t_list *head)
{
	unsigned int	lower_cost;
	unsigned long	next;

	lower_cost = UINT_MAX;
	next = 0;
	if (!include(node->x - 1, node->y, head)
		&& cost_map[node->y][node->x - 1] < lower_cost
			&& map->map[node->y][node->x - 1] != '1')
	{
		lower_cost = cost_map[node->y][node->x - 1];
		next = ((unsigned long)node->y << 32);
		next += (unsigned long)(node->x - 1);
	}
	if (!include(node->x + 1, node->y, head)
		&& cost_map[node->y][node->x + 1] < lower_cost
		&& map->map[node->y][node->x + 1] != '1')
	{
		lower_cost = cost_map[node->y][node->x + 1];
		next = ((unsigned long)node->y << 32);
		next += (unsigned long)(node->x + 1);
	}
	return (next);
}

static unsigned long	get_next_y(t_map *map,
	unsigned int **cost_map, t_list *node, t_list *head)
{
	unsigned int	lower_cost;
	unsigned long	next;

	lower_cost = UINT_MAX;
	next = 0;
	if (!include(node->x, node->y - 1, head)
		&& cost_map[node->y - 1][node->x] < lower_cost
		&& map->map[node->y - 1][node->x] != '1')
	{
		lower_cost = cost_map[node->y - 1][node->x];
		next = ((unsigned long)(node->y - 1) << 32);
		next += (unsigned long)node->x;
	}
	if (!include(node->x, node->y + 1, head)
		&& cost_map[node->y + 1][node->x] < lower_cost
		&& map->map[node->y + 1][node->x] != '1')
	{
		lower_cost = cost_map[node->y + 1][node->x];
		next = ((unsigned long)(node->y + 1) << 32);
		next += (unsigned long)node->x;
	}
	return (next);
}

t_list	*get_next(t_map *map, unsigned int **cost_map,
	t_list *node, t_list *head)
{
	unsigned int	lower_cost;
	unsigned long	next_x;
	unsigned long	next_y;
	t_list			*next_node;

	next_x = get_next_x(map, cost_map, node, head);
	next_y = get_next_y(map, cost_map, node, head);
	if (next_x == 0 && next_y == 0)
		return (NULL);
	if (cost_map[(unsigned int)(next_x >> 32)][(unsigned int)next_x]
		< cost_map[(unsigned int)(next_y >> 32)][(unsigned int)next_y])
		next_node = create_node((unsigned int)next_x,
				(unsigned int)(next_x >> 32));
	else
		next_node = create_node((unsigned int)next_y,
				(unsigned int)(next_y >> 32));
	return (next_node);
}

int	has_next(t_map *map, unsigned int x, unsigned int y)
{
	int	has_next;

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
