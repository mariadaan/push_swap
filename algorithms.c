#include "push_swap.h"

/*
	take top off
	put top on stack b

	take 
*/

void	sort_stack(t_stack *a, t_stack *b)
{
	int	tmp;

	while (a->top > 0)
	{
		tmp = pop_num(a);
		while (b->top > 0 && b->items[b->top - 1] > tmp)
		{
			push(a, b);
		}
		add_num(b, tmp);
		// print_array("stack a", a->items, a->top);
		// print_array("stack b", b->items, b->top);
	}
}