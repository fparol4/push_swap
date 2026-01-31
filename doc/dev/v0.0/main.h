/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparola <fabricio.parola@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 22:42:00 by fparola           #+#    #+#             */
/*   Updated: 2025/10/23 22:42:00 by fparola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include "src/types.h"

t_target_cost get_maxmin_cost(t_stack stack, int value);
t_target_cost get_minmax_cost(t_stack stack, int value);

t_option get_upward_option(t_target_cost one, t_target_cost two);
t_option get_downward_option(t_target_cost one, t_target_cost two);
t_target_cost get_target_cost(t_stack stack, int pos);
t_option get_middle_option(t_target_cost one, t_target_cost two);
t_option get_option(t_target_cost one, t_target_cost two);

int ft_abs(int v);
int ft_signal(int v);
int ft_lowerof(int *items, int size);

const char *get_movement(t_movement mov);
t_movement get_stack_movement(t_stack_id id);
char **get_steps(t_option option);

t_option get_best_option(t_stack one, t_stack two);
void push_swap(t_stack one, t_stack two);

#endif
