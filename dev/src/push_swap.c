#include "../main.h"
# include "./types.h"
# include "./utils.c"
#include "./math.c"
#include "./core/get-best-option.c"
#include "./core/get-cost.c"
#include "./core/get-target.c"

int main()
{
	t_stack s_one = {
		.id = STACK_ONE,
		.size = 4,
		.items = (int[7]) {  }
	};

	t_stack s_two = {
		.id = STACK_TWO,
		.size = 3,
		.items = (int[7]) { 6, 7, 1, 2, 3, 4, 5 }
	};

	int i = 0;
	t_option best_option;
	while (i < s_one.size)
	{
		t_target_cost item_cost = get_target_cost(s_one, i);
		t_target_cost target_cost = get_minmax(s_two, s_one.items[i]);
		t_option transfer_option = get_best_option(item_cost, target_cost);
		// printf("D0:%d\n", best_option.cost);
		if (i == 0 || transfer_option.cost < best_option.cost)
			best_option = transfer_option;
		i++;
	}

	printf("D0:%d\n", best_option.cost);
	printf("D0:%d\n", best_option.steps[2].cost);
	printf("D0:%d\n", best_option.steps[2].movement);
	char **steps = get_steps(best_option);
	while (*steps)
	{
		printf("D0:%s\n", *steps);
		steps++;
	}
}
