#include "push_swap.h"


/*
	Old sorting algorithm
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
	Basic bubble sort algorithm
	Sorts stack with lowest number on top of the stack
	- Example:
	before: [28, -16, 5, 1, -30, 70]
	after:  [70, 28, 5, 1, -16, -30]
*/
void	bubble_sort(t_stack *stack)
{
	int	i;

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
}

/*
	Radix sort!!
*/
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	j;

	simplify_stack(a);
	// a->max_size - 1 is het hoogste nummer op de stack na het simplifien
	// dus max_bits is 
	max_bits = 0; // how many bits for (a->max_size - 1) 
	while (((a->max_size - 1) >> max_bits) != 0)
	{
		++max_bits;
	}
	// printnum("max_bits", max_bits);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < a->max_size)
		{
			if (((a->items[a->top - 1] >> i) & 1) == 1)
				rotate("ra", a); // if the (i + 1)-th bit is 1, leave in stack a
			else
				push("pb", b, a); // otherwise push to stack b
			j++;
		}
		// put into boxes done
		while (b->top > 0)
		{
			push("pa", a, b); // while stack b is not empty, do pa
		}
		i++;
		// connect numbers done
	}
}

/*
	Sort stack of three numbers
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

/*
	Sort stack of five numbers
	- push lowest 2 numbers to stack b
	- use sort_three to sort remaining numbers
	- push numbers from b back to a
	done!
*/
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
