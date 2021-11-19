#include "libft/libft.h"
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

int main (void)
{
	int array[7] = {28, -16, 5, 1, -30, 70, 0};

	t_stack stack_a;
	t_stack stack_b;

	init_stack(&stack_a, 6);
	init_stack(&stack_b, 6);
	stack_a.items = array;
	stack_a.max_size = 6;
	stack_a.top = 6;
	radix_sort(&stack_a, &stack_b);
	print_array("a", stack_a.items, stack_a.max_size);

}

// 28 -16 5 1 -30 70

/*

	is niet genoeg want soms moet er nog een rotate plaatsvinden 
	checken of er nog een 0 op de place zit ONDER een 1

	returns 1 als er nog een 0 onder zit
	returns 0 als er geen 0 onder zit
*/
int		has_bit(t_stack *a, int bit_place, int stack_place)
{
	int i;
	int j;

	stack_place = 0;
	i = a->top - 1;
	while (i >= 0) // door getallen in stack lopen van boven naar beneden
	{
		if (((a->items[i] >> bit_place) & 1) == 1) // als bit_place een 1 is
		{
			j = i - 1;
			// checken of er nog een 0 onder zit
			while (j > 0)
			{
				if (((a->items[j] >> bit_place) | 0) == 0)
					return (1);
				j--;
			}
		}
		i--;
	}
	return (0);
}
