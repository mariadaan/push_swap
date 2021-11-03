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

/*
	Checks whether string contains an integer value
	Returns 1 if num is within integer value boundaries
	else, returns 0
*/
int		is_int(char *num_str)
{
	int		num_int;
	char	*new_num_str;

	if (!(num_str[0]))
			return (1);
	num_int = ft_atoi(num_str);
	new_num_str = ft_itoa(num_int);
	if (ft_strcmp(num_str, new_num_str))
	{
		free(new_num_str);
		return (0);
	}
	free(new_num_str);
	return (1);
}

/*
	Checks whether int array contains duplicate numbers
*/
int		has_duplicates(int *items, int size)
{
	int	i;
	int	j;
	int	number;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		number = items[i];
		while (j < size)
		{
			if (number == items[j])
			{
				free(items);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

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
		if (!(ft_isint(num)))
			return (1);
		i++;
	}
	return (0);
}