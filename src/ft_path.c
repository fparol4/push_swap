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

    if (size < 0)
        return (NULL);
    path = ft_calloc(1, sizeof(t_path));
    if (!path)
        return (NULL);
    path->step = ft_calloc(size, sizeof(t_step));
    if (!path->step)
        return (free(path), NULL);
    path->steps = size;
    i = -1;
    while (++i < size)
    {
        path->step[i] = steps[i];
        path->cost += steps[i].times;
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
    best = NULL;
    i = 0;
    while (i < 3)
    {
        if (options[i])
        {
            if (!best || options[i]->cost < best->cost)
            {
                ft_path_free(best);
                best = options[i];
            }
            else
                ft_path_free(options[i]);
        }
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

static void ft_set_best(t_path **best, t_path *path)
{
    if (!path)
        return ;
    if (!*best || path->cost < (*best)->cost)
    {
        ft_path_free(*best);
        *best = path;
    }
    else
        ft_path_free(path);
}

t_path *ft_calc_cheap(t_stack *stack_s, t_stack *stack_d)
{
    t_item  *it;
    t_item  *tg;
    t_path  *best;
    t_path 	*path;
    t_node  *curr;

    if (stack_d->size <= 2)
        return (ft_path_new((t_step[]){{ft_get_pushmov(stack_d->id), 1}}, 1));
    best = NULL;
    curr = stack_s->head;
    while (curr)
    {
        it = ft_get_item(stack_s, curr);
        tg = ft_get_target(stack_d, *curr->value);
        path = ft_get_best_path(it, tg);
        ft_set_best(&best, path);
        ft_secfree((void *[]){it, tg}, 2);
        curr = curr->next;
    }
    return (best);
}

void ft_path_exec(t_path *path, t_pswap *pswap)
{
    int     i;
    int     j;
    char    *name;

    if (!path)
        return ;
    i = 0;
    while (i < path->steps)
    {
        name = ft_moven(path->step[i].mov);
        j = 0;
        while (j < path->step[i].times)
        {
            ft_move(path->step[i].mov, pswap->sa, pswap->sb);
            if (name)
                ft_putendl_fd(name, 1);
            j++;
        }
        i++;
    }
    ft_path_free(path);
}
