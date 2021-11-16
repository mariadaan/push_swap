#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	while (a->top > 0)
	{
		rotate("ra", a);
		while (b->top > 0 && b->items[b->top - 1] > a->items[0])
			push("pa", a, b);
		rev_rotate("rra", a);
		push("pb", b, a);
	}
	while (a->top != a->max_size)
		push("pa", a, b);
}


/*
	Basic bubble sort algorithm
	Sorts stack with lowest number on top of the stack
*/
void	bubble_sort(t_stack *stack)
{
	int	i;

	print_array("stack", stack->items, stack->max_size);

	while (!(is_sorted(stack->items, stack->max_size)))
	{
		i = 0;
		while (i < stack->max_size)
		{
			if (stack->items[i] < stack->items[i + 1])
				swap(stack, i, i + 1);
			i++;
		}
	}
	print_array("copy ", stack->items, stack->max_size);

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
	Sort copy stack and put the index of where a number needs to come
	in the original stack a
*/
void	radix_sort(t_stack *a)
{
	t_stack	copy;
	int		i;
	int		j;

	i = 0;
	init_stack(&copy, a->max_size);
	copy_stack(a, &copy);
	bubble_sort(&copy);
	print_array("a    ", a->items, a->max_size);
	while (i < a->max_size)
	{
		j = 0;
		while (j < a->max_size)
		{
			if (a->items[i] == copy.items[j])
			{
				a->items[i] = j;
				break;
			}
			j++;
		}
		i++;
	}
	print_array("a    ", a->items, a->max_size);

}

/*
	- if top number is the biggest, rotate
	- if middle number is the biggest, reverse rotate
	- swap top if necessary
	done!
*/
void	sort_three(t_stack *a)
{
	// als bovenste het grootste getal is rotaten
	if (a->items[2] > a->items[1] && a->items[2] > a->items[0])
		rotate("ra", a);
	// als middelste het grootste getal is reverse rotaten
	else if (a->items[1] > a->items[0] && a->items[1] > a->items[2])
		rev_rotate("rra", a);
	// bovenste getallen swappen als nodig
	if (a->items[2] > a->items[1])
		swap_top("sa", a);
}


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

void	sort_five(t_stack *a, t_stack *b)
{
	int	amount_higher;
	int	pushed;

	amount_higher = 0;
	pushed = 0;
	while (pushed < 2)
	{
		amount_higher = count_higher(a->items[a->top - 1], a->items, a->top);
		// push lowest 2 numbers to stack b
		if (amount_higher >= 3) // if 3 numbers or more are higher, push to b stack
		{
			push("pb", b, a);
			pushed++;
		}
		else
			rotate("ra", a);
	}
	if (b->items[0] > b->items[1])
		swap_top("sb", b);
	sort_three(a);
	push("pa", a, b);
	push("pa", a, b);
}

/*
	checks whether array is sorted in descending order
	returns 1 if sorted
	returns 0 if not sorted
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