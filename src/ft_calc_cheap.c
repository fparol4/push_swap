/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_cheap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:18 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:18 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_set_best(t_path **best, t_path *path)
{
	if (!path)
		return ;
	if (!*best || path->cost < (*best)->cost)
	{
		ft_path_free(*best);
		*best = path;
	}
	else
		ft_path_free(path);
}

t_path	*ft_calc_cheap(t_stack *stack_s, t_stack *stack_d)
{
	t_item	*it;
	t_item	*tg;
	t_path	*best;
	t_path	*path;
	t_node	*curr;

	if (stack_d->size == 0)
		return (ft_path_new((t_step[]){{ft_get_pushmov(stack_s->id), 1}}, 1));
	best = NULL;
	curr = stack_s->head;
	while (curr)
	{
		it = ft_get_item(stack_s, curr);
		tg = ft_get_target(stack_d, *curr->value);
		path = ft_get_best_path(it, tg);
		ft_set_best(&best, path);
		ft_secfree((void *[]){it, tg}, 2);
		if (best && best->cost == 1)
			return (best);
		curr = curr->next;
	}
	return (best);
}

void	ft_path_exec(t_path *path, t_pswap *pswap)
{
	int		i;
	int		j;
	char	*name;

	if (!path)
		return ;
	i = 0;
	while (i < path->steps)
	{
		name = ft_moven(path->step[i].mov);
		j = 0;
		while (j < path->step[i].times)
		{
			ft_move(path->step[i].mov, pswap->sa, pswap->sb);
			if (name)
				ft_putendl_fd(name, 1);
			j++;
		}
		i++;
	}
	ft_path_free(path);
}
