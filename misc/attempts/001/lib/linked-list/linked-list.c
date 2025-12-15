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

#include "./linked-list.h"
#include <stddef.h>

void ft_secfree(void *content)
{
	if (content == NULL)
		return;
	free(content);
	return;
}

void	*ft_nullp()
{
	return ft_calloc(1, sizeof(void *));
}

/**
 * Write a ft_list_node that gives a new node
 * A node can be represented by:
 * content: *void;
 * previous: s_node;
 * next: s_node;
 */

t_lstnode *ft_lstnode(void *content)
{
	t_lstnode *node = ft_calloc(1, sizeof(t_lstnode));
	if (node == NULL)
		return (NULL);
	node->content = content;
	return node;
}

t_lst *ft_lstfrom(void *items, size_t length, size_t size)
{
	t_lstnode *node;
	t_lst *list;
	char *item_ptr;

	if (length <= 0 || size <= 0)
		return (NULL);
	item_ptr = (char *)items;
	list = (t_lst *)ft_calloc(1, sizeof(t_lst));
	while (list->length < length)
	{
		node = ft_lstnode((void *)item_ptr + (list->length * size));
		if (node == NULL)
			return (ft_lstclear(list));
		if (list->head == NULL)
		{
			list->head = node;
			list->tail = node;
		}
		else
		{
			node->previous = list->tail;
			list->tail->next = node;
			list->tail = node;
		}
		list->length += 1;
	}
	return (list);
}

t_lst *ft_lstempty(size_t length)
{
	t_lstnode 	*node;
	t_lst 		*lst;

	if (length <= 0)
		return (NULL);
	lst = ft_calloc(1, sizeof(t_lst));
	while (lst->length < length)
	{
		node = ft_lstnode(ft_nullp());
		if (node == NULL)
			return (ft_lstclear(lst));
		if (lst->head == NULL)
		{
			lst->head = node;
			lst->tail = node;
		}
		else
		{
			lst->tail->next = node;
			lst->tail = node;
		}
		lst->length += 1;
	}
	return (lst);
}

void *ft_lstclear(t_lst *list)
{
	size_t i;
	t_lstnode *node;

	i = 0;
	while (i < list->length)
	{
		node = list->head;
		list->head = list->head->next;
		list->length -= 1;
		ft_secfree(node);
	}
	ft_secfree(list);
	return (NULL);
}
