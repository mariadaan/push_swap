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
	print_array("stack a", stack_a.items, stack_a.top);
	print_array("stack b", stack_b.items, stack_b.top);
	sort_stack(&stack_a, &stack_b);
	print_array("stack a", stack_a.items, stack_a.top);
	print_array("stack b", stack_b.items, stack_b.top);
	free(stack_a.items);
	free(stack_b.items);
}