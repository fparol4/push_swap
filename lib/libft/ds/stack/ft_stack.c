/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:29:12 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:29:12 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_stack	*ft_stack_new(int id, t_node *node)
{
	t_stack	*stack;
	t_node	*curr;
	int		i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->id = id;
	stack->head = node;
	stack->size = 0;
	curr = node;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		stack->tail = curr;
		stack->size++;
		curr = curr->next;
	}
	return (stack);
}

void	ft_stack_add_head(t_stack *stack, t_node *node)
{
	t_node	*curr;
	int		i;

	if (!stack || !node)
		return ;
	node->next = stack->head;
	node->previous = NULL;
	if (stack->head)
		stack->head->previous = node;
	else
		stack->tail = node;
	stack->head = node;
	stack->size++;
	curr = stack->head;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
}

void	ft_stack_add_tail(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->previous = stack->tail;
	node->next = NULL;
	node->index = (int)stack->size;
	if (stack->tail)
		stack->tail->next = node;
	else
		stack->head = node;
	stack->tail = node;
	stack->size++;
}

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

t_node	*ft_stack_pop_head(t_stack *stack)
{
	t_node	*node;
	t_node	*curr;
	int		i;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->previous = NULL;
	else
		stack->tail = NULL;
	stack->size--;
	node->next = NULL;
	node->previous = NULL;
	curr = stack->head;
	i = 0;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
	return (node);
}

t_node	*ft_stack_pop_tail(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->tail)
		return (NULL);
	node = stack->tail;
	stack->tail = node->previous;
	if (stack->tail)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	stack->size--;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
