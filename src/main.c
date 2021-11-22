#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (check_input(argc, argv + 1))
		return (error_msg("Error: non-int arguments", 1));
	init_stack(&a, argc - 1);
	init_stack(&b, argc - 1);
	fill_stack(&a, argv + 1);
	if (has_duplicates(a.items, a.max_size))
		return (error_msg("Error: duplicate numbers", 1));
	if (argc == 4)
		sort_three(&a);
	else if (argc == 6)
		sort_five(&a, &b);
	else
		radix_sort(&a, &b);
	free(a.items);
	free(b.items);
}
