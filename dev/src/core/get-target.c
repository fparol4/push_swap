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
