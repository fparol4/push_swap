#include "../push-swap.h"

int main(int argc, char **argv)
{
	t_pswap pswap;
    t_node  *args;
    t_path  *path;

    if (argc < 2)
        return (0);
    args = ft_handle_args(argc, argv);
    pswap.sa = ft_stack_new(STACK_A, args);
    pswap.sb = ft_stack_new(STACK_B, args);
    if (!pswap.sa || !pswap.sb)
        return (1);
    t_node *head = pswap.sa->head;
    while (head)
    {
   		printf("NV: %d\n", *head->value);
     	head = head->next;
    }

    // while (a->size > 3)
    // {
    //     if (b->size < 2)
    //     {
    //         ft_apply_movement(MOV_PB, a, b);
    //         ft_putendl_fd(S_PB, 1);
    //     }
    //     else
    //     {
    //         path = ft_calculate_cheapest(a, b);
    //         ft_execute_path(best, a, b);
    //     }
    // }
    // ft_execute_path(ft_sort_three(a), a, b);
    // // Add logic to return from B to A here
    // return (0);
}
