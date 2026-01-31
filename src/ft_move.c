/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:19 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:19 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_mov	ft_get_pushmov(t_estack stack)
{
	if (stack == STACK_A)
		return (MOV_PB);
	return (MOV_PA);
}

static int	ft_try_push(t_mov mov, t_stack *a, t_stack *b)
{
	if (mov == MOV_PA && b && b->head)
	{
		ft_stack_add_head(a, ft_stack_pop_head(b));
		return (1);
	}
	if (mov == MOV_PB && a && a->head)
	{
		ft_stack_add_head(b, ft_stack_pop_head(a));
		return (1);
	}
	return (0);
}

static void	ft_handle_rot(t_mov mov, t_stack *a, t_stack *b)
{
	if (mov == MOV_RA || mov == MOV_RB || mov == MOV_RR)
	{
		if (mov != MOV_RB)
			ft_stack_rot(a);
		if (mov != MOV_RA)
			ft_stack_rot(b);
		return ;
	}
	if (mov == MOV_RRA || mov == MOV_RRB || mov == MOV_RRR)
	{
		if (mov != MOV_RRB)
			ft_stack_revrot(a);
		if (mov != MOV_RRA)
			ft_stack_revrot(b);
	}
}

char	*ft_moven(t_mov mov)
{
	static const char	*names[] = {
		NULL,
		S_PA,
		S_PB,
		S_SA,
		S_SB,
		S_RA,
		S_RB,
		S_RR,
		S_RRA,
		S_RRB,
		S_RRR
	};

	if (mov < MOV_NONE || mov > MOV_RRR)
		return (NULL);
	return ((char *)names[mov]);
}

void	ft_move(t_mov mov, t_stack *a, t_stack *b)
{
	if (ft_try_push(mov, a, b))
		return ;
	if (mov == MOV_SA || mov == MOV_SB)
	{
		if (mov == MOV_SA)
			ft_stack_swap(a);
		else
			ft_stack_swap(b);
		return ;
	}
	ft_handle_rot(mov, a, b);
}
