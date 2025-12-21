#include "../main.h"

const char *get_movement(t_movement mov)
{
    const char *movements[10];

    movements[0] = "PA";
    movements[1] = "PB";
    movements[2] = "SA";
    movements[3] = "SB";
    movements[4] = "RA";
    movements[5] = "RB";
    movements[6] = "RR";
    movements[7] = "RRA";
    movements[8] = "RRB";
    movements[9] = "RRR";
    if (mov < 0 || mov > 9)
        return (0);
    return (movements[mov]);
}

t_movement get_stack_movement(t_stack_id id)
{
	if (id == STACK_ONE)
		return M_PA;
	else
		return M_PB;
}

char **get_steps(t_option option)
{
	int i;
 	int j;
	int cost = 0;
	char *step;
	char **steps;

	i = 0;
	j = 0;
	cost = 0;
	steps = (char **)calloc(option.cost + 1, sizeof(char *));
	while (cost < option.cost)
	{
		step = (char *)get_movement(option.steps[i].movement);
		j = 0;
		while (j < option.steps[i].cost)
		{
			steps[cost + j] = step;
			j++;
		}
		cost += option.steps[i].cost;
		i++;
	}
	return steps;
}
