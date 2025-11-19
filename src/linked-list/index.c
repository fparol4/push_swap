
#include "index.h"
#include <stdio.h>

t_node *ft_node(void *content)
{
	t_node *node;

	node = (t_node *)calloc(1, sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	return node;
}

t_linked *ft_list(int length, void *items, size_t size)
{
	t_node *node;
	t_linked *list = (t_linked *)calloc(1, sizeof(t_linked));

	int i = 0;
	char *c_ptr = (char *)items;
	while (i < length)
	{
		node = ft_node((void *)c_ptr + (i * size));
		if (node == NULL)
			return (NULL);
		if (list->head == NULL)
		{
			list->head = node;
			list->tail = node;
		}
		else
		{
			list->tail->next = node;
			list->tail = node;
		}
		i++;
	}

	return (list);
}

int main(int argc, char *argv[])
{
	int	v[] = { 1, 2, 3, 4 };
	int c = ()

	t_linked *int_list = ft_list(4, v, sizeof(int));
	printf("x0: %d\n", *(int *)int_list->tail->content);

	// char *strs[] = {"hellowolrd"};
	// t_linked *strs_list = ft_list(1, strs, sizeof(char *));
	// printf("x0: %s\n", *(char **)strs_list->head->content);

	return 0;
}
