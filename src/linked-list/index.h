/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked-list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:42:00 by fparola           #+#    #+#             */
/*   Updated: 2025/10/23 22:42:00 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"
#include <stdlib.h>

typedef struct s_node
{
	void *content;
	struct s_node *next;
	struct s_node *previous;
} t_node;

typedef struct s_linked
{
	t_node *head;
	t_node *tail;
} t_linked;
