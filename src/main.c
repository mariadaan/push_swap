#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (check_input(argc, argv + 1))
		return (error_msg("Error: non-int arguments", 1));
	init_stack(&stack_a, argc - 1);
	init_stack(&stack_b, argc - 1);
	fill_stack(&stack_a, argv + 1);
	if (has_duplicates(stack_a.items, stack_a.max_size))
		return (error_msg("Error: duplicate numbers", 1));
	if (argc == 4)
		sort_three(&stack_a);
	else if (argc == 6)
		sort_five(&stack_a, &stack_b);
	else
		radix_sort(&stack_a, &stack_b);
	free(stack_a.items);
	free(stack_b.items);
}