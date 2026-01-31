#ifndef PSWAP_STACK_H
#define PSWAP_STACK_H

# include "../lib/libft/libft.h"

typedef enum e_stack
{
	OTHER = 0,
	STACK_A = 1,
	STACK_B = 2,
} e_stack;

typedef struct s_item_cost
{
	int upward;
	int downward;
} t_item_cost;

typedef struct s_item
{
	t_node *node;
	e_stack stack;
	t_item_cost cost;
} t_item;

#endif
