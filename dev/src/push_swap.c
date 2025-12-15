#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

typedef struct
{
	int *items;
	int size;
	char name;
} t_stack;

typedef struct
{
	t_stack *s_one;
	t_stack *s_two;
} t_pswap;

typedef struct
{
	int rx;
	int rrx;
} t_cost;

typedef struct
{
	int cost;
	const char **steps;
} t_transfer_option;

typedef enum
{
	M_PA = 1,
	M_PB = 2,
	M_SA = 3,
	M_SB = 4,
	M_RA = 5,
	M_RB = 6,
	M_RR = 7,
	M_RRA = 8,
	M_RRB = 9,
	M_RRR = 10,
} t_movements;

const char* get_movement(t_movements movement)
{
	const char *MOVEMENTS[] = {
		"PA", "PB", "SA", "SB", "RA", "RB", "RR", "RRA", "RRB", "RRR",
	};
	return MOVEMENTS[movement - 1];
}

int ft_abs(int v)
{
	if (v == INT_MIN)
		return (-1);
	if (v < 0)
		return (-v);
	return (v);
}

int ft_signal(int v)
{
	if (v < 0)
		return (-1);
	return (1);
}

int ft_lowerof(int one, int two)
{
	if (one > two)
		return two;
	return one;
}

int get_rotmov(int signal)
{
	if (signal == 1)
		return M_RA;
	if (signal == -1)
		return M_RB;
	return (0);
}

t_cost get_cost(int idx, t_stack stack)
{
	t_cost cost;

	cost.rx = idx;
	cost.rrx = stack.size - idx;
	return (cost);
}

/** B WILL BE ORDERED FROM HIGH TO LOW
 - 1. 2x PB
 - 2. FIND THE LOWEST ABOVE ME
	- IF NOT & SIZE > 2 ON TOP OF THE HIGHER
*/

int get_target(int value, t_stack stack)
{
	int i;
	int max;
	int target;

	i = 0;
	while (i < stack.size)
	{
		if (stack.items[i] > stack.items[max])
			max = i;
		if (value > stack.items[i])
			if (stack.items[i] > stack.items[target])
				target = i;
	}
	if (target != -1)
		return (target);
	return (max);
}

void add_steps(const char **steps, const char* movement, int times)
{
	int i = 0;
	while (i < times)
		steps[i++] = movement;
}

t_transfer_option get_transfer_option(t_cost one, t_cost two)
{
	// OPTION should find the approach with
	// minor steps, and then return the quantity of steps
	// and what steps should be executed
	// based on the name of the stack add the last step PA or PB

	// RX - CLOCK
	int rr_cost = ft_lowerof(one.rx, two.rx);
	int rx_cost = ft_abs(one.rx - two.rx);
	int rx_total = rr_cost + rx_cost;
	int rx_direction = get_rotmov(ft_signal(one.rx - two.rx));

	// RRX - ANTI CLOCK
	int rrr_cost = ft_lowerof(one.rx, two.rx);
	int rrx_cost = ft_abs(one.rx - two.rx);
	int rrx_total = rrr_cost + rrx_cost;
	int rrx_direction = get_rotmov(ft_signal(one.rx - two.rx));

	t_transfer_option option;
	if (rx_total < rrx_total)
	{
		option.cost = rx_total;
		option.steps = calloc(rx_total, sizeof(char *));
		add_steps(option.steps, get_movement(M_RR), rr_cost);
		add_steps(option.steps, get_movement(rx_direction), rx_cost);
	} else {
		option.cost = rrx_total;
		option.steps = calloc(rrx_total, sizeof(char *));
		add_steps(option.steps, get_movement(M_RRR), rrr_cost);
		add_steps(option.steps, get_movement(rrx_direction), rrx_cost);
	}
	return (option);
}

int get_option(t_stack one, t_stack two)
{
	int i;
	int option;
	int target;
	t_cost target_cost;
	t_cost option_cost;
	t_transfer_option transfer_option;

	if (two.size < 2)
		return (0);
	i = 0;
	while (i < one.size)
	{
		target = get_target(one.items[i], two);
		target_cost = get_cost(target, two);
		option_cost = get_cost(i, one);
		transfer_option = get_transfer_option(target_cost, option_cost);
	}
}

int main()
{
	const char **s = calloc(3, sizeof(char**));
	add_steps(s, get_movement(M_PA), 3);

	/* --- */
	// int items[] = {1, 2, 3, 4};
	// t_stack one = {.items = items, .size = sizeof(items) / sizeof(int)};
	// t_cost c = get_cost(1, one);
	// printf("D0:%d\n", c.rx);
	// printf("D0:%d\n", c.rrx);
	/* --- */

}
