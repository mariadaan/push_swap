#include "../libft.h"

/*
	Checks whether str is in array
	Return -1 if not
	Return index of str in array if yes
*/
int	ft_strin2darray(char **array, char *str)
{
	int	i;
	int	rows;

	if (!array || !str)
		return (-1);
	i = 0;
	rows = ft_count_rows(array);
	while (i < rows)
	{
		if (ft_strcmp(array[i], str) == 0)
			return (i);
		i++;
	}
	return (-1);
}
