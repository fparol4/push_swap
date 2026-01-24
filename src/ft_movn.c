#include "../push-swap.h"

const char	*ft_movn(e_mov mov)
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
