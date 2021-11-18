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
			if (stack->items[i] > stack->items[i + 1])
				swap(stack, i, i + 1);
			i++;
		}
	}
}


/*
	checken of er nog een 0 op de place zit ONDER een 1

	returns 1 als er nog een 0 onder zit
	returns 0 als er geen 0 onder zit
*/
int		has_bit(t_stack *a, int place)
{
	int i;
	int j;

	i = a->top - 1;
	while (i >= 0) // door getallen in stack lopen van boven naar beneden
	{
		if (((a->items[i] >> place) & 1) == 1) // als place een 1 is
		{
			j = i - 1;
			// checken of er nog een 0 onder zit
			while (j > 0)
			{
				if (((a->items[j] >> place) | 0) == 0)
					return (1);
				j--;
			}
		}
		i--;
	}
	return (0);
}

/*
	Radix sort!!

	- max_bits kan maximaal 32 zijn want integer is max 32 bits
	- niet onnodig vaak loopen door eerst te kijken hoeveel bits het grootste getal op de stack gebruikt
		- bijvoorbeeld 28 is hoogste cijfer op de stack -> 11100 in binary -> 5 bits
	
	Example:
	original stack:		[28, -16, 5, 1, -30, 70]
	simplified stack:	[4, 1, 3, 2, 0, 5]
	stack in binary:	[100, 1, 011, 010, 101]
	max_bits = 3

	- check most right bit. If it's 1, leave in stack a. If it's 0, push to stack b.
	- push numbers back to a
	- repeat for the bit next to most right bit, then the one next to that, etc.

	plannetje:

	als er tussen de bovenste cijfers geen 1 bit tussen zit, niet pushen naar b

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
	while (i < max_bits) // door alle bits heen loopen
	{
		j = 0;
		while (j < a->max_size) // door hele stack heen loopen
		{
			if (((a->items[a->top - 1] >> i) & 1) == 1) // check the most right bit
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
