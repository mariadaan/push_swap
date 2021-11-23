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

int	check_fill_stacks(t_stack *a, t_stack *b, char *argv[], int argc)
{
	init_stack(a, argc - 1);
	fill_stack(a, argv + 1);
	if (is_sorted_descending(a->items, a->max_size))
	{
		free(a->items);
		return (1);
	}
	init_stack(b, argc - 1);
	if (has_duplicates(a->items, a->max_size))
	{
		free(a->items);
		free(b->items);
		return (error_msg("Error: duplicate numbers", 1));
	}
	return (0);
}
