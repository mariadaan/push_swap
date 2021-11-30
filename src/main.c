#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (check_input(&a, argc, argv))
		return (error_msg("Error", 1));
	if (is_sorted_descending(a.items, a.max_size))
	{
		free(a.items);
		return (1);
	}
	init_stack(&b, argc - 1);
	if (argc == 4)
		sort_three(&a);
	else if (argc == 6)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	free(a.items);
	free(b.items);
	return (0);
}
