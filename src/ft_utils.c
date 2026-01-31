/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:33:36 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:33:36 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void	ft_secfree(void **ptrs, int size)
{
	int	i;

	if (!ptrs)
		return ;
	i = 0;
	while (i < size)
	{
		if (ptrs[i])
			free(ptrs[i]);
		i++;
	}
}

void	ft_node_free(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		if (node->value)
			free(node->value);
		free(node);
		node = tmp;
	}
}

t_node	*ft_node_new(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = ft_calloc(1, sizeof(int));
	if (!node->value)
	{
		free(node);
		return (NULL);
	}
	*node->value = value;
	return (node);
}

void	ft_node_add_tail(t_node **head, t_node *new)
{
	t_node	*curr;

	if (!*head)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	new->previous = curr;
}
