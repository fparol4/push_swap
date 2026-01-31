/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mov.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardozo <fcardozo@student.42.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 23:06:55 by fcardozo         #+#    #+#             */
/*   Updated: 2026/01/30 23:06:55 by fcardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_MOV_H
# define PSWAP_MOV_H

# define S_PA "pa"
# define S_PB "pb"
# define S_SA "sa"
# define S_SB "sb"
# define S_RA "ra"
# define S_RB "rb"
# define S_RR "rr"
# define S_RRA "rra"
# define S_RRB "rrb"
# define S_RRR "rrr"

typedef enum t_mov
{
	MOV_NONE = 0,
	MOV_PA,
	MOV_PB,
	MOV_SA,
	MOV_SB,
	MOV_RA,
	MOV_RB,
	MOV_RR,
	MOV_RRA,
	MOV_RRB,
	MOV_RRR
}			t_mov;

typedef struct t_step
{
	t_mov	mov;
	int		times;
}			t_step;

typedef struct t_path
{
	int		cost;
	int		steps;
	t_step	*step;
}			t_path;

#endif
