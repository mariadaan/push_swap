#include "push_swap.h"

/*
	Print each number in stack.
*/
void	print_stack(char *name, t_stack stack)
{
	int	i;

	printf("----------\n%s:\n", name);
	i = 0;
	while (i < stack.top)
	{
		printf("%d\n", stack.items[i]);
		i++;
	}
	printf("----------\n");
}

/*
	Print each number in stack zodat het echt een stapel lijkt.
*/
void	print_stacked(char *name, t_stack stack)
{
	int	i;

	printf("----------\n%s:\n", name);
	i = stack.top - 1;
	while (i >= 0)
	{
		printf("%d\n", stack.items[i]);
		i--;
	}
	printf("----------\n");
}