void add_steps(const char **steps, const char *movement, int times)
{
	int i = 0;
	while (i < times)
		steps[i++] = movement;
}
