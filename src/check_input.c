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
*/
int	check_input(int argc, char **input)
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
			return (error_msg("Error: non-int arguments", 1));
		i++;
	}
	return (0);
}
