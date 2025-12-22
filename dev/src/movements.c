/**
	1. movements
	- [x] sa - swap first two a
	- [x] sb - swap first two b
	- [x] ss - swap first two a/b
	- [x] pa - push first element b -> a
	- [x] pb - push first element a -> b
	- [x] ra - rotate list a by one - first became last
	- [x] rb - rotate list b by one - first became last
	- [x] rr - rotate list a/b by one - first became last
	- [x] rra - reverse rotate list a by one - last became first
	- [x] rrb - reverse rotate list b by one - last became first
	- [x] rrr - reverse rotate list a/a by one - last became first
*/
#include "../main.h"
#include <string.h>
#include <threads.h>

typedef struct s_node {
	void *value;
	struct s_node *next;
	struct s_node *prev;
} t_node;


typedef struct
{
	int size;
	t_stack_id id;
	t_node *head;
	t_node *tail;
} t_lstack;

t_pswap start(int items[], int size)
{
	t_stack *one;
	t_stack *two;

	one = (t_stack *)calloc(1, sizeof(t_stack));
	one->id = STACK_ONE;
	one->size = size;
	one->items = (int *) calloc (size, sizeof(int));
	memcpy(one->items, items, size);

	two = (t_stack *)calloc(1, sizeof(t_stack));
	two->id = STACK_TWO;
	two->size = 0;
	two->items = (int *) calloc (size, sizeof(int));

	return (t_pswap) {
		.one = one,
		.two = two
	};
}


t_stack *n_stack(int items[], int size)
{
	t_stack *stack;

	stack = (t_stack *)calloc(1, sizeof(t_stack));
	stack->size = size;
	stack->items = (int *) calloc (size, sizeof(int));
	memcpy(stack->items, items, size * sizeof(int));
	return stack;
}

void p_stack(t_lstack *stack) {
	t_node *node;

	node = stack->head;
	while (node)
	{
		printf("P:%p\n", node);
		printf("V:%d\n", *(int *)node->value);
		node = node->next;
	}
}



t_node *new_node(void *value, t_node *next, t_node *prev)
{
	t_node *node;

	node = (t_node *)calloc(1, sizeof(t_node));
	node->value = value;
	node->next = next;
	node->prev = prev;
}

t_lstack *new_lstack(t_stack_id id, int items[], int size)
{
	int	i;
	t_node *c_node;
	t_lstack *stack;

	stack = (t_lstack *)calloc(1, sizeof(t_lstack));
	stack->id = id;
	stack->size = size;
	if (size == 0)
		return stack;
	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			stack->head = new_node(items, NULL, NULL);
			c_node = stack->head;
		}
		else {
			c_node->next = new_node(items + i, NULL, c_node);
			c_node->next->prev = c_node;
			c_node = c_node->next;
		}
		if (i == size - 1)
			stack->tail = c_node;
		i++;
	}
	return (stack);
}


void	lstack_swap(t_lstack *stack)
{
	t_node *node;

	if (!stack->head || !stack->head->next)
		return ;
	node = stack->head->next;
	stack->head->prev = node;
	stack->head->next = node->next;
	node->prev = NULL;
	node->next = stack->head;
	stack->head = node;
}

void	lstack_rot(t_lstack *stack)
{
	t_node *node;

	if (!stack->head || stack->head == stack->tail)
		return ;

	if (stack->size == 2)
		return lstack_swap(stack);

	node = stack->head;
	stack->head->prev = stack->tail->prev;
	stack->head->prev->next = stack->head;
	stack->tail->next = stack->head->next;
	stack->tail->next->prev = stack->tail;
	stack->head->next = NULL;
	stack->tail->prev = NULL;
	stack->head = stack->tail;
	stack->tail = node;
}

int main(int argc, char *argv[])
{

	// t_lstack *one = new_lstack(1, (int []) { 4, 2, 7, 0, 0, 0, 0 }, 7);
	t_lstack *one = new_lstack(1, (int []) { 4, 2, 5, 3 }, 4);
	// printf("D0:%d\n", *(int *) one->head->value);
	// printf("D0:%d\n", *(int *) one->head->next->value);
	// printf("D0:%p\n", one->head);
	// printf("D0:%p\n", one->head->next);
	// printf("D0:%p\n", one->head->prev);
	// printf("D0:%d\n", *(int *) one->tail->value);
	// printf("D0:%d\n", *(int *) one->tail->prev->value);
	// printf("D0:%p\n", one->tail);
	// printf("D0:%p\n", one->tail->next);
	// printf("D0:%p\n", one->tail->prev);
	p_stack(one);
	lstack_rot(one);
	printf("----\n");
	// printf("D0:%d\n", *(int *) one->head->value);
	// printf("D0:%d\n", *(int *) one->head->next->value);
	// printf("D0:%p\n", one->head);
	// printf("D0:%p\n", one->head->next);
	// printf("D0:%p\n", one->head->prev);
	// printf("D0:%d\n", *(int *) one->tail->value);
	// printf("D0:%d\n", *(int *) one->tail->prev->value);
	// printf("D0:%p\n", one->tail);
	// printf("D0:%p\n", one->tail->next);
	// printf("D0:%p\n", one->tail->prev);

	// lstack_swap(ne);
	p_stack(one);
	// t_lstack *two = new_lstack(2, (int []) {}, 0);
	return 0;
}

void exec_movement(t_stack one, t_stack two, t_step step)
{
	int i;

	i = 0;
	while (i < step.cost)
	{
		// if (step.movement === M_PA)
		// if (step.movement === M_PB)
		// if (step.movement === M_SA)
		// if (step.movement === M_SB)
		// if (step.movement === M_RA)
		// if (step.movement === M_RB)
		// if (step.movement === M_RR)
		// if (step.movement === M_RRA)
		// if (step.movement === M_RRB)
		// if (step.movement === M_RRR)
	}
}
