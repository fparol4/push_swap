/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:18 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:18 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_step	ft_align_step(t_stack *a)
{
	t_node	*curr;
	t_node	*min_node;
	t_step	step;

	min_node = a->head;
	curr = a->head;
	while (curr)
	{
		if (*curr->value < *min_node->value)
			min_node = curr;
		curr = curr->next;
	}
	step.times = min_node->index;
	step.mov = MOV_RA;
	if (min_node->index > (int)(a->size / 2))
	{
		step.times = (int)a->size - min_node->index;
		step.mov = MOV_RRA;
	}
	return (step);
}

void	ft_stack_align(t_stack *a, t_pswap *pswap)
{
	t_step	step;

	if (!a || a->size < 2)
		return ;
	step = ft_align_step(a);
	ft_path_exec(ft_path_new((t_step[1]){step}, 1), pswap);
}

int	main(int argc, char **argv)
{
	t_pswap	pswap;

	if (argc < 2)
		return (0);
	ft_memset(&pswap, 0, sizeof(t_pswap));
	if (!ft_init_pswap(&pswap, argc, argv))
		return (1);
	if (ft_handle_small_cases(&pswap))
		return (0);
	ft_reduce_to_three(&pswap);
	ft_rebuild_stack(&pswap);
	ft_stack_align(pswap.sa, &pswap);
	ft_free_pswap(&pswap);
	return (0);
}
