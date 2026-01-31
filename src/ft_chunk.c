/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:33:35 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:33:35 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

static void	ft_assign_ranks(t_stack *s)
{
	t_node	*curr;
	t_node	*inner;
	int		rank;

	curr = s->head;
	while (curr)
	{
		rank = 0;
		inner = s->head;
		while (inner)
		{
			if (*inner->value < *curr->value)
				rank++;
			inner = inner->next;
		}
		curr->rank = rank;
		curr = curr->next;
	}
}

static int	ft_get_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

static int	ft_in_range(t_node *node, int low, int high)
{
	return (node->rank >= low && node->rank <= high);
}

static t_node	*ft_find_cheapest(t_stack *s, int low, int high, int *cost)
{
	t_node	*curr;
	t_node	*best;
	int		pos;
	int		curr_cost;

	curr = s->head;
	best = NULL;
	pos = 0;
	*cost = -1;
	while (curr)
	{
		if (ft_in_range(curr, low, high))
		{
			curr_cost = ft_get_cost(pos, (int)s->size);
			if (*cost == -1 || curr_cost < *cost)
			{
				*cost = curr_cost;
				best = curr;
			}
		}
		pos++;
		curr = curr->next;
	}
	return (best);
}

static void	ft_rotate_to_top(t_pswap *pswap, t_node *target)
{
	int	pos;

	pos = target->index;
	if (pos <= (int)(pswap->sa->size / 2))
	{
		while (pswap->sa->head != target)
		{
			ft_move(MOV_RA, pswap->sa, pswap->sb);
			ft_putendl_fd(S_RA, 1);
		}
	}
	else
	{
		while (pswap->sa->head != target)
		{
			ft_move(MOV_RRA, pswap->sa, pswap->sb);
			ft_putendl_fd(S_RRA, 1);
		}
	}
}

void	ft_chunk_push(t_pswap *pswap)
{
	int		total;
	int		range;
	int		pushed;
	int		cost;
	t_node	*target;

	ft_assign_ranks(pswap->sa);
	total = (int)pswap->sa->size;
	if (total <= 100)
		range = total / 5;
	else
		range = total / 11;
	pushed = 0;
	while (pswap->sa->size > 3)
	{
		target = ft_find_cheapest(pswap->sa, pushed - range, pushed + range,
				&cost);
		if (!target)
		{
			pushed += range;
			continue ;
		}
		ft_rotate_to_top(pswap, target);
		ft_move(MOV_PB, pswap->sa, pswap->sb);
		ft_putendl_fd(S_PB, 1);
		if (pswap->sb->size > 1
			&& *pswap->sb->head->value < *pswap->sb->head->next->value)
		{
			ft_move(MOV_RB, pswap->sa, pswap->sb);
			ft_putendl_fd(S_RB, 1);
		}
		pushed++;
	}
}
