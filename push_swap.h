/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:08:59 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 23:08:59 by fcardozo         ###   ########.fr       */
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
# include "./types/pswap_mov.h"
# include "./types/pswap_stack.h"

/* -- GENERAL -- */
typedef struct s_pswap
{
	t_stack	*sa;
	t_stack	*sb;
	t_stack	*path;
}			t_pswap;

/* -- FILES -- */

/* src/utils.c */
void		ft_secfree(void **ptrs, int size);

/* src/ft_args.c */
t_node		*ft_handle_args(int argc, char **argv);
void		ft_handle_error(t_node **head, char **split);
int			ft_has_duplicate(t_node *head, int value);

/* src/ft_node.c */
void		ft_node_free(t_node *node);
void		ft_node_add_tail(t_node **head, t_node *node);
t_node		*ft_node_new(int value);

/* src/fr_movn.c */
char		*ft_moven(t_mov mov);
t_mov		ft_get_pushmov(t_estack stack);
void		ft_move(t_mov mov, t_stack *a, t_stack *b);

/* src/ft_math.c */
int			ft_lowerof(int a, int b);

/* src/ft_path.c */
void		ft_path_free(t_path *path);
t_path		*ft_path_new(t_step *steps, int size);
t_path		*ft_get_best_path(t_item *a, t_item *b);
t_item		*ft_get_target(t_stack *dest, int value);
void		ft_path_exec(t_path *path, t_pswap *pswap);
t_path		*ft_calc_cheap(t_stack *stack_s, t_stack *stack_d);

/* src/ft_process.c */
void		ft_free_pswap(t_pswap *pswap);
int			ft_init_pswap(t_pswap *pswap, int argc, char **argv);
int			ft_handle_small_cases(t_pswap *pswap);
void		ft_reduce_to_three(t_pswap *pswap);
void		ft_rebuild_stack(t_pswap *pswap);
void		ft_stack_align(t_stack *a, t_pswap *pswap);

/* src/ft_target.c */
t_item		*ft_get_item(t_stack *s, t_node *node);
t_item		*ft_get_next_smaller(t_stack *s, int value);
t_item		*ft_get_next_greater(t_stack *s, int value);

/* src/ft_option.c */
t_path		*ft_get_upward_option(t_item *item_a, t_item *item_b);
t_path		*ft_get_downward_option(t_item *item_a, t_item *item_b);
t_path		*ft_get_mixed_option(t_item *item_a, t_item *item_b);

/* src/ft_sort.c */
t_path		*ft_sort_three(t_stack *s);

/* src/ft_stack_free.c */
void		ft_stack_free(t_stack *stack);

/* src/ft_utils.c */
int			ft_is_sorted(t_stack *s);

#endif
