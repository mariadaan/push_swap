#include "push_swap.h"

/*
	take top off
	put top on stack b

	take 
*/

void	sort_stack(t_stack *a, t_stack *b)
{
	// int	tmp;
	int	count = 0;

	while (a->top > 0)
	{
		// tmp = pop_num(a);
		rev_rotate(a);
		count++;
		// printf("\ntmp:     [%d]\n", tmp);
		// printf("pop a\n");
		// print_array("stack a", a->items, a->top);
		// print_array("stack b", b->items, b->top);
		while (b->top > 0 && b->items[b->top - 1] > a->items[0])
		{
			push(a, b);
			count++;
			// print_array("stack a", a->items, a->top);
			// print_array("stack b", b->items, b->top);
		}
		rotate(a);
		push(b, a);
		// add_num(b, tmp);
		count++;
		count++;

		// printf("add b\n");
		// print_array("stack a", a->items, a->top);
		// print_array("stack b", b->items, b->top);
	}
	printnum("count", count);
}

void	sort_three(t_stack *a)
{
	int	count = 0;
	// als bovenste het grootste getal is rotaten
	if (a->items[2] > a->items[1] && a->items[2] > a->items[0])
	{
		rotate(a);
		count++;
	}
	// als middelste het grootste getal is reverse rotaten
	if (a->items[1] > a->items[0] && a->items[1] > a->items[2])
	{
		rev_rotate(a);
		count++;
	}
	// bovenste getallen swappen als nodig
	if (a->items[2] > a->items[1])
	{
		swap_top(a);
		count++;
	}
	printnum("count", count);
}

// void	swap_five(t_stack *a, t_stack *b)
// {

// }

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