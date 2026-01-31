/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:06:55 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 23:06:55 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_STACK_H
# define PSWAP_STACK_H

# include "../lib/libft/libft.h"

typedef enum t_estack
{
	OTHER = 0,
	STACK_A = 1,
	STACK_B = 2,
}				t_estack;

typedef struct s_item_cost
{
	int			upward;
	int			downward;
}				t_item_cost;

typedef struct s_item
{
	t_node		*node;
	t_estack	stack;
	t_item_cost	cost;
}				t_item;

#endif
