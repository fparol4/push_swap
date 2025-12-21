#include "../../main.h"

t_target_cost get_target_cost(t_stack stack, int pos)
{
	t_target_cost cost;

	cost.upward = pos;
	cost.downward = stack.size - pos;
	return (cost);
}
