/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:17 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:17 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_has_duplicate(t_node *head, int value)
{
	t_node	*curr;

	curr = head;
	while (curr)
	{
		if (*curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	ft_handle_error(t_node **head, char **split)
{
	if (head && *head)
	{
		ft_node_free(*head);
		*head = NULL;
	}
	ft_free_split(split);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	ft_append_values(char **split, t_node **head)
{
	int	value;
	int	i;

	i = 0;
	while (split[i])
	{
		if (!ft_vatoi(split[i]))
			ft_handle_error(head, split);
		value = ft_atoi(split[i]);
		if (ft_has_duplicate(*head, value))
			ft_handle_error(head, split);
		ft_node_add_tail(head, ft_node_new(value));
		i++;
	}
}

t_node	*ft_handle_args(int argc, char **argv)
{
	t_node	*head;
	char	**split;
	int		i;

	head = NULL;
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
			ft_handle_error(&head, split);
		ft_append_values(split, &head);
		ft_free_split(split);
	}
	return (head);
}
