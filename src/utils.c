#include "push_swap.h"

/*
	Checks whether array is sorted in ascending order
	- returns 1 if sorted
	- returns 0 if not sorted
*/
int	is_sorted(int *items, int size)
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
	Count how many numbers on the stack are higher than num
*/
int	count_higher(int num, int *items, int len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		if (items[i] > num)
			count++;
		i++;
	}
	return (count);
}

/*
	Counts the amount of bits an integer uses
*/
int	count_bits(int num)
{
	int	max_bits;

	max_bits = 0;
	while (((num - 1) >> max_bits) != 0)
		++max_bits;
	return (max_bits);
}

/*
	Copy stack a into copy stack
*/
void	copy_stack(t_stack *a, t_stack *copy)
{
	int	i;

	i = 0;
	while (i < a->max_size)
	{
		copy->items[i] = a->items[i];
		copy->top++;
		i++;
	}
}

/*
	Replace numbers in stack a with simplified version of number
	- Example:
	before: [28, -16, 5, 1, -30, 70]
	after:  [4, 1, 3, 2, 0, 5]
	- Highest number gets value 5
	- Lowest number gets value 0
*/
void	simplify_stack(t_stack *a)
{
	t_stack	copy;
	int		i;
	int		j;

	i = 0;
	init_stack(&copy, a->max_size);
	copy_stack(a, &copy);
	bubble_sort(&copy);
	while (i < a->max_size)
	{
		j = 0;
		while (j < a->max_size)
		{
			if (a->items[i] == copy.items[j])
			{
				a->items[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy.items);
}
