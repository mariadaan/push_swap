#include "push_swap.h"

/*
	Check whether string contains an integer value
	Returns 1 if num is within integer value boundaries
	else, returns 0
*/
int	is_int(char *num_str)
{
	int		num_int;
	char	*new_num_str;

	if (!num_str)
		return (0);
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
	Check whether int array contains duplicate numbers
*/
int	has_duplicates(int *items, int size)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
	Check whether given arguments are an array of integers
	Returns
	- 1 if all ints
	- 0 if not all ints
*/
int	is_all_ints(int argc, char **input)
{
	int		i;
	char	*num;

	if (argc < 2)
		return (1);
	i = 0;
	while (i < argc - 1)
	{
		num = input[i];
		if (!(is_int(num)))
			return (0);
		i++;
	}
	return (1);
}

/*
	Check whether input is integers only and whether it has duplicate numbers
	Returns
	- 1 if input is not valid
	- 0 if input is valid
*/
int	check_input(t_stack *a, int argc, char **input)
{
	if (is_all_ints(argc, input + 1) == 0)
		return (1);
	init_stack(a, argc - 1);
	fill_stack(a, input + 1);
	if (has_duplicates(a->items, a->max_size))
	{
		free(a->items);
		return (1);
	}
	return (0);
}