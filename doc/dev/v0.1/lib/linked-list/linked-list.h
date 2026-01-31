/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked-list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:42:00 by fparola           #+#    #+#             */
/*   Updated: 2025/10/23 22:42:00 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/libft.h"

typedef struct s_node
{
	void *content;
	struct s_node *next;
	struct s_node *previous;
} t_lstnode;

typedef struct s_list
{
	t_lstnode *head;
	t_lstnode *tail;
	size_t length;
} t_lst;

void	*ft_nullp();
void 	ft_secfree(void *content);

/** FUNCTIONS */
void 		*ft_lstclear(t_lst *list);
t_lst 		*ft_lstfrom(void *items, size_t length, size_t size);
t_lst		*ft_lstempty(size_t length);
t_lstnode 	*ft_lstnode(void *content);
