#include "libft.h"

/*
	Checks whether string contains an integer value
	Returns 1 if num is within integer value boundaries
	else, returns 0
*/
int		ft_isint(char *num_str)
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