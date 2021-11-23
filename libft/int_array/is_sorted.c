/*
	Checks whether array is sorted in ascending order
	- returns 1 if sorted
	- returns 0 if not sorted
*/
int	is_sorted_ascending(int *items, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (items[i] > items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
	Checks whether array is sorted in descending order
	- returns 1 if sorted
	- returns 0 if not sorted
*/
int	is_sorted_descending(int *items, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (items[i] < items[i + 1])
			return (0);
		i++;
	}
	return (1);
}
