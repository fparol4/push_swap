# include "../../main.h"
// # include "./get-cost.c"

/**
 * Get the min value above target
 * or the maximum value.
 * EX: 3, { 2, 5, 4 } => 4
 */
t_target_cost get_maxmin(t_stack stack, int value)
{
	int i;
	int max;
	int target;

	i = 0;
	max = 0;
	target = -1;
	while (i < stack.size)
	{
		if (i == 0 || stack.items[i] > stack.items[max])
			max = i;
		if (value > stack.items[i])
			if (target == -1 || stack.items[i] > stack.items[target])
				target = i;
		i++;
	}
	if (target == -1)
		return (get_target_cost(stack, max));
	return ((get_target_cost(stack, target)));
}

/**
 * Get the max value below me
 * or the minimum value.
 * EX: 3, { 2, 5, 4 } => 2
 */
t_target_cost get_minmax(t_stack stack, int value)
{
	int i;
	int min;
	int target;

	i = 0;
	min = 0;
	target = -1;
	while (i < stack.size)
	{
		if (i == 0 || stack.items[i] < stack.items[min])
			min = i;
		if (value < stack.items[i])
			if (target == -1 || stack.items[i] < stack.items[target])
				target = i;
		i++;
	}
	if (target == -1)
		return (get_target_cost(stack, min));
	return (get_target_cost(stack, target));
}
