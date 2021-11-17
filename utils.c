#include "push_swap.h"

/*
	Checks whether array is sorted in descending order
	- returns 1 if sorted
	- returns 0 if not sorted
*/
int	is_sorted(int *items, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (items[i] < items[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/*
	Count how many numbers on the stack are higher than num
*/
int		count_higher(int num, int *items, int len)
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
	Replace numbers in stack a with the index of where they
	have to be at the end.
	- Example:
	before: [28, -16, 5, 1, -30, 70]
	after:  [1, 4, 2, 3, 5, 0]
	- Biggest number gets index 0, which is the bottom of the stack
	- Lowest number gets index 5, which is the top number of the stack
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



/*
	Print each number in stack.
*/
void	print_stack(char *name, t_stack stack)
{
	int	i;

	printf("----------\n%s:\n", name);
	i = 0;
	while (i < stack.top)
	{
		printf("%d\n", stack.items[i]);
		i++;
	}
	printf("----------\n");
}

/*
	Print each number in stack zodat het echt een stapel lijkt.
*/
void	print_stacked(char *name, t_stack stack)
{
	int	i;

	printf("----------\n%s:\n", name);
	i = stack.top - 1;
	while (i >= 0)
	{
		printf("%d\n", stack.items[i]);
		i--;
	}
	printf("----------\n");
}

/*
	Print each number in stack zodat het echt een stapel lijkt.
*/
void	print_stacked_binary(char *name, t_stack stack)
{
	int	i;

	printf("----------\n%s:\n", name);
	i = stack.top - 1;
	while (i >= 0)
	{
		ft_putbasenbr(stack.items[i], 2);
		ft_putchar('\n');
		i--;
	}
	printf("----------\n");
}

void	print_array(char *name, int *numbers, int len)
{
	int i;

	i = 0;
	printf("%s:   [", name);
	while (i < len)
	{
		printf("%d", numbers[i]);
		i++;
		if (i != len)
			printf(", ");
	}
	printf("]\n");
}