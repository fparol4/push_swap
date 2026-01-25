#include "../push-swap.h"

t_item *ft_get_item(t_stack *s, t_node *node)
{
    t_item *item;

    if (!s || !node)
        return (NULL);
    item = ft_calloc(1, sizeof(t_item));
    if (!item)
        return (NULL);
    item->node = node;
    item->stack = s->id;
    item->cost.upward = node->index;
    item->cost.downward = 0;
    if (node->index != 0)
        item->cost.downward = s->size - node->index;
    return (item);
}

t_item *ft_get_next_smaller(t_stack *s, int value)
{
    t_node *max;
    t_node *target;
    t_node *current;

    if (!s || !s->head)
        return (NULL);
    target = NULL;
    max = s->head;
    current = s->head;
    while (current != NULL)
    {
        if (*current->value > *max->value)
            max = current;
        if (*current->value < value)
            if (!target || *current->value > *target->value)
                target = current;
        current = current->next;
    }
    if (!target)
        return (ft_get_item(s, max));
    return (ft_get_item(s, target));
}

t_item *ft_get_next_greater(t_stack *s, int value)
{
    t_node *min;
    t_node *target;
    t_node *current;

    if (!s || !s->head)
        return (NULL);
    target = NULL;
    min = s->head;
    current = s->head;
    while (current != NULL)
    {
        if (*current->value < *min->value)
            min = current;
        if (*current->value > value)
            if (!target || *current->value < *target->value)
                target = current;
        current = current->next;
    }
    if (!target)
        return (ft_get_item(s, min));
    return (ft_get_item(s, target));
}
