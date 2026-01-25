#include "../push-swap.h"

void ft_path_free(t_path *path)
{
    if (!path)
        return ;
    if (path->step)
        free(path->step);
    free(path);
}

t_path *ft_path_new(t_step *steps, int size)
{
    t_path  *path;
    int     i;

    path = ft_calloc(1, sizeof(t_path));
    if (!path)
        return (NULL);
    path->step = ft_calloc(size, sizeof(t_step));
    if (!path->step)
    {
        free(path);
        return (NULL);
    }
    path->steps = size;
    path->cost = 0;
    i = 0;
    while (i < size)
    {
        path->step[i] = steps[i];
        path->cost += steps[i].times;
        i++;
    }
    return (path);
}

t_path *ft_get_best_path(t_item *a, t_item *b)
{
    t_path *options[3];
    t_path *best;
    int    i;

    options[0] = ft_get_upward_option(a, b);
    options[1] = ft_get_downward_option(a, b);
    options[2] = ft_get_mixed_option(a, b);
    best = options[0];
    i = 1;
    while (i < 3)
    {
        if (options[i] && options[i]->cost < best->cost)
        {
            ft_path_free(best);
            best = options[i];
        }
        else
            ft_path_free(options[i]);
        i++;
    }
    return (best);
}

t_item *ft_get_target(t_stack *dest, int value)
{
    if (dest->id == STACK_B)
        return (ft_get_next_smaller(dest, value));
    return (ft_get_next_greater(dest, value));
}

t_path *ft_calculate_cheapest(t_stack *src, t_stack *dest)
{
	t_item  *item;
    t_item  *target;
    t_path  *best_path;
    t_path  *current_path;
    t_node  *current_node;

    best_path = NULL;
    current_node = src->head;
    while (current_node)
    {
        item = ft_get_item(src, current_node);
        target = ft_get_target(dest, *current_node->value);
        current_path = ft_get_best_path(item, target);
        if (!best_path || current_path->cost < best_path->cost)
        {
            ft_path_free(best_path);
            best_path = current_path;
        }
        else
            ft_path_free(current_path);
        ft_secfree((void *[]){item, target}, 2);
        current_node = current_node->next;
    }
    return (best_path);
}

void ft_execute(t_path *path, t_stack *a, t_stack *b)
{
    int i;
    int j;

    if (!path)
        return ;
    i = 0;
    while (i < path->steps)
    {
        j = 0;
        while (j < path->step[i].times)
        {
            ft_move(path->step[i].mov, a, b);
            ft_putendl_fd(ft_moven(path->step[i].mov), 1);
            j++;
        }
        i++;
    }
    ft_path_free(path);
}
