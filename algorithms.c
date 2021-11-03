#include "push_swap.h"

/*
	take top off
	put top on stack b

	take 
*/

void	sort_stack(t_stack *a, t_stack *b)
{
	int	tmp;
	int	count = 0;

	while (a->top > 0)
	{
		tmp = pop_num(a);
		count++;
		// printf("\ntmp:     [%d]\n", tmp);
		// printf("pop a\n");
		// print_array("stack a", a->items, a->top);
		// print_array("stack b", b->items, b->top);
		while (b->top > 0 && b->items[b->top - 1] > tmp)
		{
			push(a, b);
			count++;
			// print_array("stack a", a->items, a->top);
			// print_array("stack b", b->items, b->top);
		}
		add_num(b, tmp);
		count++;

		// printf("add b\n");
		// print_array("stack a", a->items, a->top);
		// print_array("stack b", b->items, b->top);
	}
	printnum("count", count);
}

// void	tryout(t_stack *a, t_stack *b)
// {
// 	while (a->items[0] > a->items[a->top - 1])
// 	{
// 		rotate(a);
// 	}
// 	if (a->items[])
// }

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