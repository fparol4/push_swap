#include "../main.h"
#include "./math.c"
#include "./utils.c"
#include "./core/get-cost.c"
#include "./core/get-target.c"
#include <stdlib.h>

t_movement get_stack_mov(t_stack_id id)
{
	if (id == STACK_ONE)
		return M_PA;
	else
		return M_PB;
}

t_option get_upward_option(t_target_cost one, t_target_cost two)
{
	int rr_cost = ft_lowerof((int[]){
		one.upward,
		two.upward,
	}, 2);
	int rx_cost = ft_abs(one.upward - two.upward);
	int rx_direction = M_RA;
	if (one.upward - two.upward < 0)
		rx_direction = M_RB;

	t_option option;
	option.cost = rr_cost + rx_cost + 1;
	option.steps[0] = (t_step) {.times = rr_cost, .mov = M_RR};
	option.steps[1] = (t_step) {.times = rx_cost, .mov = rx_direction};
	option.steps[2] = (t_step) {.times = 1, .mov = get_stack_mov(one.stack_id)};
	return (option);
}

t_option get_downward_option(t_target_cost one, t_target_cost two)
{
	int rr_cost = ft_lowerof((int[]){
		one.downward,
		two.downward,
	}, 2);
	int rx_cost = ft_abs(one.downward - two.downward);
	int rx_direction = M_RRA;
	if (one.downward - two.downward < 0)
		rx_direction = M_RRB;

	t_option option;
	option.cost = rr_cost + rx_cost + 1;
	option.steps[0] = (t_step) {.times = rr_cost, .mov = M_RR};
	option.steps[1] = (t_step) {.times = rx_cost, .mov = rx_direction};
	option.steps[2] = (t_step) {.times = 1, .mov = get_stack_mov(one.stack_id)};
	return (option);
}

t_option get_middle_option(t_target_cost one, t_target_cost two)
{
	int one_cost = one.upward;
	int one_direction = M_RA;
	if (one.upward > one.downward)
	{
		one_cost = one.downward;
		one_direction = M_RRA;
	}

	int two_cost = two.upward;
	int two_direction = M_RA;
	if (two.upward > two.downward)
	{
		two_cost = two.downward;
		two_direction = M_RRA;
	}

	t_option option;
	option.cost = one_cost + two_cost + 1;
	option.steps[0] = (t_step) {.times = one_cost, .mov = one_direction};
	option.steps[1] = (t_step) {.times = two_cost, .mov = two_direction};
	option.steps[2] = (t_step) {.times = 1, .mov = get_stack_mov(one.stack_id)};
	return (option);
}

t_option get_best_option(t_target_cost one, t_target_cost two)
{
	t_option upward_option = get_upward_option(one, two);
	t_option middle_option = get_middle_option(one, two);
	t_option downward_option = get_downward_option(one, two);

	int lower_cost = ft_lowerof((int[]){
		middle_option.cost,
	 	upward_option.cost,
		downward_option.cost
	}, 3);

	if (lower_cost == upward_option.cost)
		return upward_option;
	else if (lower_cost == middle_option.cost)
		return middle_option;
	else
		return downward_option;
}

int main()
{


}
