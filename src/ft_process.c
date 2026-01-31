/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:18 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:18 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_pswap(t_pswap *pswap)
{
	if (pswap->sa)
		ft_stack_free(pswap->sa);
	if (pswap->sb)
		ft_stack_free(pswap->sb);
}

int	ft_init_pswap(t_pswap *pswap, int argc, char **argv)
{
	t_node	*args;

	args = ft_handle_args(argc, argv);
	pswap->sa = ft_stack_new(STACK_A, args);
	pswap->sb = ft_stack_new(STACK_B, NULL);
	if (!pswap->sa || !pswap->sb)
	{
		ft_free_pswap(pswap);
		return (0);
	}
	return (1);
}

int	ft_handle_small_cases(t_pswap *pswap)
{
	if (ft_is_sorted(pswap->sa))
	{
		ft_free_pswap(pswap);
		return (1);
	}
	if (pswap->sa->size == 2)
	{
		if (*pswap->sa->head->value > *pswap->sa->head->next->value)
		{
			ft_move(MOV_SA, pswap->sa, pswap->sb);
			ft_putendl_fd(ft_moven(MOV_SA), 1);
		}
		ft_free_pswap(pswap);
		return (1);
	}
	return (0);
}

void	ft_reduce_to_three(t_pswap *pswap)
{
	t_path	*path;

	while (pswap->sa->size > 3)
	{
		path = ft_calc_cheap(pswap->sa, pswap->sb);
		ft_path_exec(path, pswap);
	}
}

void	ft_rebuild_stack(t_pswap *pswap)
{
	t_path	*path;

	path = ft_sort_three(pswap->sa);
	if (path)
		ft_path_exec(path, pswap);
	while (pswap->sb->size > 0)
	{
		path = ft_calc_cheap(pswap->sb, pswap->sa);
		ft_path_exec(path, pswap);
	}
}
