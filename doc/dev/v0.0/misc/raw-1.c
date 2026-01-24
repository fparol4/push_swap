t_transfer_option get_transfer_option(t_cost one, t_cost two)
{
	// OPTION should find the approach with
	// minor steps, and then return the quantity of steps
	// and what steps should be executed
	// based on the name of the stack add the last step PA or PB

	// EACH
	int one_cost = ft_minof((int[]){one.rx, one.rrx}, 2);
	int one_direction = one.rx < one.rrx ? M_RA : M_RRA;
	int two_cost = ft_minof((int[]){two.rx, two.rrx}, 2);
	int two_direction = two.rx < two.rrx ? M_RB : M_RRB;
	int each_total = one_cost + two_cost;

	// RX - CLOCK
	int rr_cost = ft_minof((int[]){one.rx, two.rx}, 2);
	int rx_cost = ft_abs(one.rx - two.rx);
	int rx_direction = 0;
	if (rx_cost)
		rx_direction = (one.rx - two.rx > 0) ? M_RA : M_RB;
	int rx_total = rr_cost + rx_cost;

	// RRX - ANTI CLOCK
	int rrr_cost = ft_minof((int[]){one.rrx, two.rrx}, 2);
	int rrx_cost = ft_abs(one.rrx - two.rrx);
	int rrx_direction = 0;
	if (rrx_cost)
		rrx_direction = (one.rrx - two.rrx > 0) ? M_RRA : M_RRB;
	int rrx_total = rrr_cost + rrx_cost;

	// Add the steps
	t_transfer_option option;
	// printf("D0:%d\n", each_total);
	// printf("D1:%d\n", rx_total);
	// printf("D2:%d\n", rrx_total);
	int best_total = ft_minof((int[]){each_total, rx_total, rrx_total}, 3);
	option.cost = best_total;
	option.steps = calloc(best_total + 2, sizeof(char *));
	option.steps[best_total + 1] = get_movement(M_PA);
	if (best_total == rx_total)
	{
		add_steps(option.steps, get_movement(M_RR), rr_cost);
		add_steps(option.steps, get_movement(rx_direction), rr_cost);
	}
	else if (best_total == rrx_total)
	{
		add_steps(option.steps, get_movement(M_RRR), rrr_cost);
		add_steps(option.steps, get_movement(rrx_direction), rrx_cost);
	}
	else
	{
		add_steps(option.steps, get_movement(one_direction), one_cost);
		add_steps(option.steps, get_movement(two_direction), two_cost);
	}
	return (option);
}


t_option option;
	option.cost = 7;
	option.steps[0] = (t_step){.cost = 3, .movement = M_RA};
	option.steps[1] = (t_step){.cost = 2, .movement = M_RB};
	option.steps[2] = (t_step){.cost = 2, .movement = M_PA};

	char **steps = get_steps(option);
	while (*steps)
	{
		printf("D0:%s\n", *steps);
		steps++;
	}
