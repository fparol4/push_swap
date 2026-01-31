/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 22:59:18 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 22:59:18 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_path	*ft_singlt_move(t_mov mov)
{
	t_step	step;

	step = (t_step){.mov = mov, .times = 1};
	return (ft_path_new(&step, 1));
}

static t_path	*ft_doublt_move(t_mov first, t_mov second)
{
	t_step	steps[2];

	steps[0] = (t_step){.mov = first, .times = 1};
	steps[1] = (t_step){.mov = second, .times = 1};
	return (ft_path_new(steps, 2));
}

t_path	*ft_sort_three(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	if (s->size != 3)
		return (NULL);
	a = *s->head->value;
	b = *s->head->next->value;
	c = *s->head->next->next->value;
	if (a > b && b < c && a < c)
		return (ft_singlt_move(MOV_SA));
	if (a > b && b > c)
		return (ft_doublt_move(MOV_SA, MOV_RRA));
	if (a > b && b < c && a > c)
		return (ft_singlt_move(MOV_RA));
	if (a < b && b > c && a < c)
		return (ft_doublt_move(MOV_SA, MOV_RA));
	if (a < b && b > c && a > c)
		return (ft_singlt_move(MOV_RRA));
	return (NULL);
}
