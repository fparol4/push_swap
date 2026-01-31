/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_mov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:07:49 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:07:49 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_stack_rot(t_stack *stack)
{
	t_node	*curr;
	int		i;

	if (!stack || stack->size < 2)
		return ;
	stack->tail->next = stack->head;
	stack->head->previous = stack->tail;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	stack->head->previous = NULL;
	stack->tail->next = NULL;
	curr = stack->head;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
}

void	ft_stack_revrot(t_stack *stack)
{
	t_node	*curr;
	int		i;

	if (!stack || stack->size < 2)
		return ;
	stack->tail->next = stack->head;
	stack->head->previous = stack->tail;
	stack->tail = stack->tail->previous;
	stack->head = stack->head->previous;
	stack->tail->next = NULL;
	stack->head->previous = NULL;
	curr = stack->head;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
}

void	ft_stack_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->previous = first;
	else
		stack->tail = first;
	second->previous = NULL;
	second->next = first;
	first->previous = second;
	stack->head = second;
	second->index = 0;
	first->index = 1;
}
