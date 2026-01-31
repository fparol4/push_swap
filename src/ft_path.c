/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:18 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:18 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_path_free(t_path *path)
{
	if (!path)
		return ;
	if (path->step)
		free(path->step);
	free(path);
}

t_path	*ft_path_new(t_step *steps, int size)
{
	t_path	*path;
	int		i;

	if (size < 0)
		return (NULL);
	path = ft_calloc(1, sizeof(t_path));
	if (!path)
		return (NULL);
	path->step = ft_calloc(size, sizeof(t_step));
	if (!path->step)
		return (free(path), NULL);
	path->steps = size;
	i = -1;
	while (++i < size)
	{
		path->step[i] = steps[i];
		path->cost += steps[i].times;
	}
	return (path);
}

t_path	*ft_get_best_path(t_item *a, t_item *b)
{
	t_path	*options[3];
	t_path	*best;
	int		i;

	options[0] = ft_get_upward_option(a, b);
	options[1] = ft_get_downward_option(a, b);
	options[2] = ft_get_mixed_option(a, b);
	best = NULL;
	i = 0;
	while (i < 3)
	{
		if (options[i])
		{
			if (!best || options[i]->cost < best->cost)
			{
				ft_path_free(best);
				best = options[i];
			}
			else
				ft_path_free(options[i]);
		}
		i++;
	}
	return (best);
}

t_item	*ft_get_target(t_stack *dest, int value)
{
	if (dest->id == STACK_A)
		return (ft_get_next_greater(dest, value));
	return (ft_get_next_smaller(dest, value));
}
