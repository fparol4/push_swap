/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 21:31:12 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 21:31:12 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* -- LIBS (C) -- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* -- LIBS (EXT) -- */
# include "./lib/libft/libft.h"

/* -- HEADERS -- */
# include "./types/ft_mov.h"
# include "./types/ft_stack.h"

/* -- GENERAL -- */
typedef struct s_pswap
{
	t_stack	*sa;
	t_stack	*sb;
	t_stack *path; // t_stack<t_path>
}			t_pswap;

/* -- FILES -- */

/* src/utils.c */
void		ft_secfree(void **ptrs, int size);

/* src/fr_movn.c */
char		*ft_moven(e_mov mov);
e_mov		ft_get_pushmov(e_stack stack);
void		ft_move(e_mov mov, t_stack *a, t_stack *b);

/* src/ft_math.c */
int			ft_lowerof(int a, int b);

/* src/ft_path.c */
t_path		*ft_path_new(t_step *steps, int size);

/* src/ft_target */
t_item		*ft_get_item(t_stack *s, t_node *node);
t_item		*ft_get_next_smaller(t_stack *s, int value);
t_item		*ft_get_next_greater(t_stack *s, int value);

/* src/ft_option.c */
t_path		*ft_get_upward_option(t_item *item_a, t_item *item_b);
t_path		*ft_get_downward_option(t_item *item_a, t_item *item_b);
t_path		*ft_get_mixed_option(t_item *item_a, t_item *item_b);

/* unorganized */
t_node		*ft_handle_args(int argc, char **argv);

void		ft_secfree(void **ptrs, int size);
void		ft_node_free(t_node *node);
void		ft_node_add_tail(t_node **head, t_node *node);
t_node		*ft_node_new(int value);

t_path		*ft_sort_three(t_stack *s);
t_path		*ft_calc_cheap(t_stack *stack_s, t_stack *stack_d);
void		ft_move(e_mov mov, t_stack *a, t_stack *b);
void		ft_path_exec(t_path *path, t_pswap *pswap);
void		ft_stack_free(t_stack *stack);
int			ft_is_sorted(t_stack *s);

#endif
