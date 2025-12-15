/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:42:00 by fparola           #+#    #+#             */
/*   Updated: 2025/10/23 22:42:00 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"
#include <limits.h>
#include <stddef.h>

void ft_lstprint(t_lst *lst)
{
	t_lstnode *node;

	node = lst->head;
	for (int i = 0; i < lst->length; i++)
	{
		printf("D0:%d\n", *(int *)node->content);
		node = node->next;
	}
}

/**
	1. movements
	- [x] sa - swap first two a
	- [x] sb - swap first two b
	- [x] ss - swap first two a/b
	- [x] pa - push first element b -> a
	- [x] pb - push first element a -> b
	- [x] ra - rotate list a by one - first became last
	- [x] rb - rotate list b by one - first became last
	- [x] rr - rotate list a/b by one - first became last
	- [x] rra - reverse rotate list a by one - last became first
	- [x] rrb - reverse rotate list b by one - last became first
	- [x] rrr - reverse rotate list a/a by one - last became first

	1.1 movements - handlers
	- [ ] based on the movements described below, write a handler
	that accepts a movement (string) and executes it

	When things get harder, be simple. You need to achieve the total
	but being simple is the best thing to aways do.
*/

t_lst *ft_lstswap(t_lst *lst)
{
	t_lstnode *head;
	t_lstnode *next;

	if (lst->length < 2)
		return (lst);
	head = lst->head;
	next = head->next;
	head->previous = next;
	head->next = next->next;
	next->previous = NULL;
	next->next = head;
	lst->head = next;
	if (next == lst->tail)
		lst->tail = head;
	return (lst);
}

t_lst *ft_lstadd_head(t_lst *lst, t_lstnode *node)
{
	t_lstnode *head;

	if (node == NULL)
		return (lst);
	head = lst->head;
	head->previous = node;
	node->next = head;
	lst->head = node;
	return (lst);
}

t_lst *ft_lstpop_head(t_lst *lst)
{
	t_lstnode *head;
	t_lstnode *next;

	if (lst->length <= 0)
		return (lst);

	if (lst->length == 1)
	{
		ft_secfree(lst->head);
		lst->head = NULL;
		lst->tail = NULL;
		lst->length = 0;
		return (lst);
	}

	head = lst->head;
	lst->head = head->next;
	lst->head->previous = NULL;
	lst->length--;
	ft_secfree(head);
	return (lst);
}


t_lst *ft_lst_htswp(t_lst *lst)
{
	t_lstnode *head;

	head = lst->head;
	lst->head->previous = lst->tail;
	lst->tail->next = head;
	lst->head = lst->tail;
	lst->tail = head;
	lst->head->previous = NULL;
	lst->tail->next = NULL;
	return (lst);
}

t_lst *ft_lst_rotrev(t_lst *lst)
{
	t_lstnode *head;

	if (lst->length <= 1)
		return (lst);
	if (lst->length == 2)
		return (ft_lst_htswp(lst));
	head = lst->head;
	lst->head->previous = lst->tail;
	lst->tail->next = lst->head;
	lst->head = lst->head->next;
	lst->head->previous = NULL;
	return (lst);
}

t_lst *ft_lst_rot(t_lst *lst)
{
	t_lstnode *head;

	if (lst->length <= 1)
		return (lst);
	if (lst->length == 2)
		return (ft_lst_htswp(lst));
	head = lst->head;
	lst->head = lst->tail;
	lst->head->next = head;
	lst->tail = lst->head->previous;
	lst->tail->next = NULL;
	lst->head->previous = NULL;
	return (lst);
}

int main(int argc, char *argv[])
{
	int items[] = { 42, 21, 33, 64 };
	int len = sizeof(items) / sizeof(int);

	t_lst *list_A = ft_lstfrom(items, len, sizeof(int));

	ft_lstprint(list_A);
	printf("----\n");
	ft_lst_rot(list_A);
	ft_lstprint(list_A);
	ft_lstclear(list_A);

	// t_lst *list_B = ft_lstempty(len);

	return 0;
}
