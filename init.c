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

// returns 1 if num is within integer value boundaries
// else, returns 0
int		is_int(char *num_str)
{
	int		num_int;
	char	*new_num_str;

	num_int = ft_atoi(num_str);
	new_num_str = ft_itoa(num_int);
	if (ft_strcmp(num_str, new_num_str))
		return (0);
	return (1);
}

// int		has_duplicates(char **input)
// {

// }

int		check_input(int argc, char **input)
{
	int		i;
	char	*num;

	if (argc < 2)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		num = input[i];
		if (num[0] == '-') // accept '-' at start of string but not in the middle
			num++;
		if (!(ft_onlydigits(num)))
			return (1);
		if (!(is_int(num)))
			return (1);
		i++;
	}
	return (0);
}