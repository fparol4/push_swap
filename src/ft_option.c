#include "../push-swap.h"

t_path *ft_get_upward_option(t_item *item_a, t_item *item_b)
{
    int     rr_times;
    int     rx_times;
    e_mov   rx_dir;
    t_step  steps[3];

    if (!item_a || !item_b)
        return (NULL);
    rr_times = ft_lowerof(item_a->cost.upward, item_b->cost.upward);
    rx_times = ft_abs(item_a->cost.upward - item_b->cost.upward);
    rx_dir = MOV_RA;
    if (item_a->cost.upward < item_b->cost.upward)
        rx_dir = MOV_RB;
    steps[0] = (t_step){.mov = MOV_RR, .times = rr_times};
    steps[1] = (t_step){.mov = rx_dir, .times = rx_times};
    steps[2] = (t_step){.mov = ft_get_pushmov(item_a->stack), .times = 1};
    return (ft_path_new(steps, 3));
}

t_path *ft_get_downward_option(t_item *item_a, t_item *item_b)
{
    int     rrr_times;
    int     rrx_times;
    e_mov   rrx_dir;
    t_step  steps[3];

    if (!item_a || !item_b)
        return (NULL);
    rrr_times = ft_lowerof(item_a->cost.downward, item_b->cost.downward);
    rrx_times = ft_abs(item_a->cost.downward - item_b->cost.downward);
    rrx_dir = MOV_RRA;
    if (item_a->cost.downward < item_b->cost.downward)
        rrx_dir = MOV_RRB;
    steps[0] = (t_step){.mov = MOV_RRR, .times = rrr_times};
    steps[1] = (t_step){.mov = rrx_dir, .times = rrx_times};
    steps[2] = (t_step){.mov = ft_get_pushmov(item_a->stack), .times = 1};
    return (ft_path_new(steps, 3));
}

t_path *ft_get_mixed_option(t_item *item_a, t_item *item_b)
{
    int     mov_a;
    int     mov_b;
    e_mov   dir_a;
    e_mov   dir_b;
    t_step  steps[3];

    if (!item_a || !item_b)
        return (NULL);
    mov_a = ft_lowerof(item_a->cost.upward, item_a->cost.downward);
    dir_a = MOV_RA;
    if (item_a->cost.downward < item_a->cost.upward)
        dir_a = MOV_RRA;
    mov_b = ft_lowerof(item_b->cost.upward, item_b->cost.downward);
    dir_b = MOV_RB;
    if (item_b->cost.downward < item_b->cost.upward)
        dir_b = MOV_RRB;
    steps[0] = (t_step){.mov = dir_a, .times = mov_a};
    steps[1] = (t_step){.mov = dir_b, .times = mov_b};
    steps[2] = (t_step){.mov = ft_get_pushmov(item_a->stack), .times = 1};
    return (ft_path_new(steps, 3));
}
