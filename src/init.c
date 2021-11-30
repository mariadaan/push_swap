#include "push_swap.h"

/*
	Initialize stack and allocate memory for the items.
*/
void	init_stack(t_stack *stack, int size)
{
	stack->max_size = size;
	stack->top = 0;
	stack->items = malloc((size + 1) * sizeof(int));
	stack->items[size] = 0;
}

/*
	Put numbers that were given as arguments into the stack as integers.
*/
void	fill_stack(t_stack *stack, char **numbers)
{
	int	i;
	int	j;
	int	number;

	i = stack->max_size - 1;
	j = 0;
	while (i >= 0)
	{
		number = ft_atoi(numbers[i]);
		stack->items[j] = number;
		stack->top++;
		j++;
		i--;
	}
}
