#include "pathfinding.h"

t_list_meta *create_list(t_list *head, t_list *tail)
{
    t_list_meta *meta;

    meta = malloc(sizeof(t_list_meta));
    if (!meta)
        return (NULL);
    meta->head = head;
    meta->tail = tail;
    if (head && tail)
        meta->size = 2;
    else if (head || tail)
        meta->size = 1;
    else
        meta->size = 0;
    return (meta);    
}

t_list  *create_node(unsigned int x, unsigned int y)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->x = x;
    node->y = y;
    node->next = NULL;
    return (node);
}

t_list_meta  *push_back(t_list *node, t_list_meta *meta)
{
    if (!node || !meta)
        return (NULL);
    if (meta->size == 0)
    {
        meta->head = node;
        meta->tail = node;
    }
    else
    {
        meta->tail->next = node;
        node->next = NULL;
        meta->tail = node;
    }
    meta->size++;
    return (meta);
}

t_list_meta *push_front(t_list *node, t_list_meta *meta)
{
    if (!node || !meta)
        return (NULL);
    node->next = meta->head;
    meta->head = node;
    meta->size++;
    return (meta);
}

t_list_meta *pop_back(t_list_meta *meta)
{
    t_list  *node;

    if (!meta)
        return (NULL);
    if (meta->size == 0)
        return (meta);
    node = meta->head;
    while (node->next != meta->tail)
        node = node->next;
    free(node->next);
    node->next = NULL;
    meta->tail = node;
    meta->size--;
    return (meta);
}

t_list_meta *pop_front(t_list_meta *meta)
{
    t_list  *node;

    if (!meta)
        return (NULL);
    node = meta->head->next;
    meta->head = meta->head->next;
    free(node);
    meta->size--;
    return (meta);
}

int include(unsigned int x, unsigned int y, t_list *head)
{
    t_list  *node;

    if (!head)
        return (-1);
    node = head;
    while (node)
    {
        if (node->x == x && node->y == y)
            return (1);
        node = node->next;
    }
    return (0);
}