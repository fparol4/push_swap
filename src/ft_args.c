/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:33:35 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:33:35 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

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

void	ft_handle_error(t_node **head, char **split)
{
	int	i;

	if (head && *head)
	{
		ft_node_free(*head);
		*head = NULL;
	}
	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			split[i] = NULL;
			i++;
		}
		free(split);
	}
	ft_putendl_fd("Error", 2);
	exit(1);
}

t_node	*ft_handle_args(int argc, char **argv)
{
	t_node	*head;
	char	**split;
	int		i;
	int		j;

	head = NULL;
	i = 0;
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_handle_error(&head, NULL);
		j = 0;
		while (split[j])
		{
			if (!ft_vatoi(split[j]))
				ft_handle_error(&head, split);
			if (ft_has_duplicate(head, ft_atoi(split[j])))
				ft_handle_error(&head, split);
			ft_node_add_tail(&head, ft_node_new(ft_atoi(split[j])));
			j++;
		}
		j = 0;
		while (split[j])
			free(split[j++]);
		free(split);
	}
	return (head);
}
