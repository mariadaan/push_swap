#include "push_swap.h"

/*
	take top off
	put top on stack b

	take 
*/

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
	checks whether array is sorted in ascending order
	returns 1 if sorted
	returns 0 if not sorted
*/
int	is_sorted(int *items, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (items[i] > items[i + 1])
			return (0);
		i++;
	}
	return (1);
}