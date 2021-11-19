#include "push_swap.h"

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
			if (stack->items[i] > stack->items[i + 1])
				swap(stack, i, i + 1);
			i++;
		}
	}
}

/*
	Radix sort!!

	- simplify stack
	Example:
	original stack:		[28, -16, 5, 1, -30, 70]
	simplified stack:	[4, 1, 3, 2, 0, 5]
	stack in binary:	[100, 1, 011, 010, 101]

	- calculate maximum number of bits for numbers on the simplified stack.
		- Example: highest number is 5 -> 101 in binary -> 3 bits
	
	- loop through stack for each bit position
		- check bit in current position. 
			If it's 1, leave in stack a by rotating stack a.
			If it's 0, push to stack b.
		- push numbers back to a
*/
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit_place;
	int	stack_place;

	simplify_stack(a);
	max_bits = count_bits(a->max_size - 1);
	bit_place = 0;
	while (bit_place < max_bits)
	{
		stack_place = 0;
		while (stack_place < a->max_size) // door hele stack heen loopen voor 1 bit
		{
			if (((a->items[a->top - 1] >> bit_place) & 1) == 1) // check the most right bit
				rotate("ra", a); // if the bit is 1, leave in stack a
			else //if (has_bit(a, i, j))// ik wil alleen pb doen als er niks anders dan pa meer na gaat komen in deze ronde
				push("pb", b, a); // otherwise push to stack b
			stack_place++;
		}
		// put into boxes done
		while (b->top > 0)
		{
			push("pa", a, b); // while stack b is not empty, do pa
		}
		bit_place++;
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
