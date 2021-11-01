#include "push_swap.h"

int	main(int argc, char *argv[])
{
	// check input if digit
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a, argc - 1);
	init_stack(&stack_b, argc - 1);
	fill_stack(&stack_a, argv + 1);
	print_stack("stack a", stack_a);
	swap_top(&stack_a);
	print_stack("stack a", stack_a);
	push(&stack_b, &stack_a);
	print_stack("stack a", stack_a);
	print_stack("stack b", stack_b);
	rotate(&stack_a);
	print_stack("stack a", stack_a);
	rev_rotate(&stack_a);
	print_stack("stack a", stack_a);

}