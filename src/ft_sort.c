#include "../push-swap.h"

t_path *ft_sort_three(t_stack *s)
{
    int     a;
    int     b;
    int     c;
    t_step  steps[3];

    if (s->size != 3)
        return (NULL);
    a = *s->head->value;
    b = *s->head->next->value;
    c = *s->head->next->next->value;
    if (a > b && b < c && a < c)
        steps[0] = (t_step){.mov = MOV_SA, .times = 1};
    else if (a > b && b > c)
    {
        steps[0] = (t_step){.mov = MOV_SA, .times = 1};
        steps[1] = (t_step){.mov = MOV_RRA, .times = 1};
        return (ft_path_new(steps, 2));
    }
    else if (a > b && b < c && a > c)
        steps[0] = (t_step){.mov = MOV_RA, .times = 1};
    else if (a < b && b > c && a < c)
    {
        steps[0] = (t_step){.mov = MOV_SA, .times = 1};
        steps[1] = (t_step){.mov = MOV_RA, .times = 1};
        return (ft_path_new(steps, 2));
    }
    else if (a < b && b > c && a > c)
        steps[0] = (t_step){.mov = MOV_RRA, .times = 1};
    else
        return (NULL);
    return (ft_path_new(steps, 1));
}
