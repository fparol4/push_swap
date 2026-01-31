/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:33:35 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:33:35 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

void	ft_stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->head)
		ft_node_free(stack->head);
	free(stack);
}
