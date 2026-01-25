#include "../push-swap.h"

void ft_handle_error(t_node **head, char **split)
{
    int i;

    if (head && *head)
    {
        ft_node_free(*head);
        *head = NULL;
    }
    if (split)
    {
        i = 0;
        while (split[i])
            free(split[i++]);
        free(split);
    }
    ft_putendl_fd("Error", 2);
    exit(1);
}

t_node *ft_handle_args(int argc, char **argv)
{
    t_node  *head;
    char    **split;
    int     i;
    int     j;

    head = NULL;
    i = 0;
    while (++i < argc)
    {
        split = ft_split(argv[i], ' ');
        if (!split)
            ft_handle_error(&head, NULL);
        j = 0;
        while (split[j])
        {
            if (!ft_vatoi(split[j]))
                ft_handle_error(&head, split);
            ft_node_add_tail(&head, ft_node_new(ft_atoi(split[j])));
            free(split[j++]);
        }
        free(split);
    }
    return (head);
}
