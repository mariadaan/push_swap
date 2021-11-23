#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (check_input(argc, argv + 1))
		return (1);
	if (check_fill_stacks(&a, &b, argv, argc))
		return (1);
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
