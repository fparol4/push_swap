/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:18 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:18 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *s)
{
	t_node	*curr;

	if (!s || !s->head)
		return (1);
	curr = s->head;
	while (curr->next)
	{
		if (*curr->value > *curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}
