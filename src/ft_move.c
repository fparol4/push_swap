#include "../push-swap.h"

e_mov ft_get_pushmov(e_stack stack)
{
    if (stack == STACK_A)
        return (MOV_PB);
    return (MOV_PA);
}

char	*ft_moven(e_mov mov)
{
	if (mov == MOV_PA)
		return (S_PA);
	else if (mov == MOV_PB)
		return (S_PB);
	else if (mov == MOV_SA)
		return (S_SA);
	else if (mov == MOV_SB)
		return (S_SB);
	else if (mov == MOV_RA)
		return (S_RA);
	else if (mov == MOV_RB)
		return (S_RB);
	else if (mov == MOV_RR)
		return (S_RR);
	else if (mov == MOV_RRA)
		return (S_RRA);
	else if (mov == MOV_RRB)
		return (S_RRB);
	else if (mov == MOV_RRR)
		return (S_RRR);
	return (NULL);
}

void ft_move(e_mov mov, t_stack *a, t_stack *b)
{
    if (mov == MOV_PA && b && b->head)
        ft_stack_add_head(a, ft_stack_pop_head(b));
    else if (mov == MOV_PB && a && a->head)
        ft_stack_add_head(b, ft_stack_pop_head(a));
    else if (mov == MOV_SA)
        ft_stack_swap(a);
    else if (mov == MOV_SB)
        ft_stack_swap(b);
    else if (mov == MOV_RA)
        ft_stack_rot(a);
    else if (mov == MOV_RB)
        ft_stack_rot(b);
    else if (mov == MOV_RR)
    {
        ft_stack_rot(a);
        ft_stack_rot(b);
    }
    else if (mov == MOV_RRA)
        ft_stack_revrot(a);
    else if (mov == MOV_RRB)
        ft_stack_revrot(b);
    else if (mov == MOV_RRR)
    {
        ft_stack_revrot(a);
        ft_stack_revrot(b);
    }
}
