/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:33:35 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:33:35 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push-swap.h"

static void	ft_push_min(t_pswap *pswap)
{
	t_node	*curr;
	t_node	*min;
	int		pos;

	curr = pswap->sa->head;
	min = curr;
	while (curr)
	{
		if (*curr->value < *min->value)
			min = curr;
		curr = curr->next;
	}
	pos = min->index;
	if (pos <= (int)(pswap->sa->size / 2))
	{
		while (pswap->sa->head != min)
		{
			ft_move(MOV_RA, pswap->sa, pswap->sb);
			ft_putendl_fd(S_RA, 1);
		}
	}
	else
	{
		while (pswap->sa->head != min)
		{
			ft_move(MOV_RRA, pswap->sa, pswap->sb);
			ft_putendl_fd(S_RRA, 1);
		}
	}
	ft_move(MOV_PB, pswap->sa, pswap->sb);
	ft_putendl_fd(S_PB, 1);
}

void	ft_sort_five(t_pswap *pswap)
{
	t_path	*path;

	while (pswap->sa->size > 3)
		ft_push_min(pswap);
	path = ft_sort_three(pswap->sa);
	if (path)
		ft_path_exec(path, pswap);
	while (pswap->sb->size > 0)
	{
		ft_move(MOV_PA, pswap->sa, pswap->sb);
		ft_putendl_fd(S_PA, 1);
	}
}

t_path	*ft_sort_three(t_stack *s)
{
	int		a;
	int		b;
	int		c;
	t_step	steps[3];

	if (s->size != 3)
		return (NULL);
	a = *s->head->value;
	b = *s->head->next->value;
	c = *s->head->next->next->value;
	if (a > b && b < c && a < c)
		steps[0] = (t_step){.mov = MOV_SA, .times = 1};
	else if (a > b && b > c)
	{
		steps[0] = (t_step){.mov = MOV_SA, .times = 1};
		steps[1] = (t_step){.mov = MOV_RRA, .times = 1};
		return (ft_path_new(steps, 2));
	}
	else if (a > b && b < c && a > c)
		steps[0] = (t_step){.mov = MOV_RA, .times = 1};
	else if (a < b && b > c && a < c)
	{
		steps[0] = (t_step){.mov = MOV_SA, .times = 1};
		steps[1] = (t_step){.mov = MOV_RA, .times = 1};
		return (ft_path_new(steps, 2));
	}
	else if (a < b && b > c && a > c)
		steps[0] = (t_step){.mov = MOV_RRA, .times = 1};
	else
		return (NULL);
	return (ft_path_new(steps, 1));
}
