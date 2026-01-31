/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:33:35 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:33:35 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void	ft_stack_print(t_stack *s, char *name)
{
	t_node	*curr;

	if (!s)
		return ;
	ft_putstr_fd("--- Stack ", 1);
	ft_putstr_fd(name, 1);
	ft_putendl_fd(" ---", 1);
	curr = s->head;
	while (curr)
	{
		ft_putstr_fd("[", 1);
		ft_putnbr_fd(curr->index, 1);
		ft_putstr_fd("] Value: ", 1);
		ft_putnbr_fd(*curr->value, 1);
		ft_putchar_fd('\n', 1);
		curr = curr->next;
	}
}

void	ft_stack_align(t_stack *a, t_pswap *pswap)
{
	t_node	*curr;
	t_node	*min_node;
	t_path	*path;
	t_step	step;

	if (!a || a->size < 2)
		return ;
	curr = a->head;
	min_node = curr;
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
	path = ft_path_new((t_step[1]){step}, 1);
	ft_path_exec(path, pswap);
}

int	main(int argc, char **argv)
{
	t_pswap	pswap;
	t_node	*args;
	t_path	*path;

	if (argc < 2)
		return (0);
	ft_memset(&pswap, 0, sizeof(t_pswap));
	args = ft_handle_args(argc, argv);
	pswap.sa = ft_stack_new(STACK_A, args);
	pswap.sb = ft_stack_new(STACK_B, NULL);
	if (!pswap.sa || !pswap.sb)
		return (1);
	if (ft_is_sorted(pswap.sa))
	{
		ft_stack_free(pswap.sa);
		ft_stack_free(pswap.sb);
		return (0);
	}
	if (pswap.sa->size == 2)
	{
		if (*pswap.sa->head->value > *pswap.sa->head->next->value)
		{
			ft_move(MOV_SA, pswap.sa, pswap.sb);
			ft_putendl_fd(ft_moven(MOV_SA), 1);
		}
		ft_stack_free(pswap.sa);
		ft_stack_free(pswap.sb);
		return (0);
	}
	ft_chunk_push(&pswap);
	path = ft_sort_three(pswap.sa);
	if (path)
		ft_path_exec(path, &pswap);
	while (pswap.sb->size > 0)
	{
		path = ft_calc_cheap(pswap.sb, pswap.sa);
		ft_path_exec(path, &pswap);
	}
	ft_stack_align(pswap.sa, &pswap);
	// ft_stack_print(pswap.sa, "A");
	// ft_stack_print(pswap.sb, "B");
	ft_stack_free(pswap.sa);
	ft_stack_free(pswap.sb);
	return (0);
}
