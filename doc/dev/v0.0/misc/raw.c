#include <limits.h>
#include <stdint.h>
#include <stdio.h>

// int ft_lowerof(int v[])
// {
// 	int low;
// 	int size;

// 	size = sizeof(v) / sizeof(int);
// 	printf("D0: what %d\n", size);
// 	return 0;
// 	if (!size) return -1;
// 	low = 0;
// 	while (*v)
// 	{
// 		if (*v < low)
// 			low = *v;
// 		v++;
// 	}
// 	return low;
// }

int ft_minof(int *items, int size)
{
	int	i;
	int smaller;

	i = 0;
	smaller = INT_MAX;
	if (!size) return smaller;
	while (i < size)
	{
		if (items[i] < smaller)
			smaller = items[i];
		i++;
	}
	return smaller;
}

int main(int argc, char *argv[])
{
	// int low = ft_lowerof((t_array), 6);
	printf("D0:%s\n", "helloi");
	return 0;
}
