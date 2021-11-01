#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (check_input(argc, argv + 1))
		return (error_msg("Error", 1));
	init_stack(&stack_a, argc - 1);
	init_stack(&stack_b, argc - 1);
	fill_stack(&stack_a, argv + 1);
	if (has_duplicates(stack_a.items, stack_a.max_size))
		return (error_msg("Error", 1));
	print_stacked("stack a", stack_a);
	// print_stack("stack b", stack_b);
	swap_top(&stack_a);
	push(&stack_b, &stack_a);
	rotate(&stack_a);
	rev_rotate(&stack_a);
	free(stack_a.items);
	free(stack_b.items);
}