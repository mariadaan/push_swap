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
	int	number;

	i = 0;
	while (i < stack->max_size)
	{
		number = ft_atoi(numbers[i]);
		stack->items[i] = number;
		stack->top++;
		i++;
	}
}