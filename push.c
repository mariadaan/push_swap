#include "push_swap.h"

/*
	Initialize stack and allocate memory for the items.
*/
void	init_stack(t_stack *stack, int size)
{
	stack->max_size = size;
	stack->top = 0;
	stack->items = malloc((size + 1) * sizeof(int));
	stack->items[size] = 0;
}

/*
	Put numbers that were given as arguments into the stack as integers.
*/
void	fill_stack(t_stack *stack, char **numbers)
{
	int	i;
	int	number;

	i = 0;
	while (i < stack->max_size)
	{
		number = ft_atoi(numbers[i]);
		stack->items[i] = number;
		stack->top++;
		i++;
	}
}

/*
	Print each number in stack.
*/
void	print_stack(char *name, t_stack stack)
{
	int	i;

	printf("----------\n%s:\n", name);
	i = 0;
	while (i < stack.top)
	{
		printf("%d\n", stack.items[i]);
		i++;
	}
	printf("----------\n");
}

/*
	Swap 2 elements in stack.
	Do nothing if indexes of the elements are above top of stack.
*/
void	swap(t_stack *stack, int index_one, int index_two)
{
	int	temp;

	if (index_one >= stack->top || index_two >= stack->top)
		return;
	temp = stack->items[index_one];
	stack->items[index_one] = stack->items[index_two];
	stack->items[index_two] = temp;
}

/*
	Swap the first 2 elements at the top of stack.
	Do nothing if there is only one or no elements.
*/
void	swap_top(t_stack *stack)
{
	if (stack->top < 2)
		return;
	swap(stack, stack->top - 1, stack->items[stack->top - 2]);
}

/*
	Removes a number from the top of the stack.
	Return this number.
*/
int	remove_num(t_stack *stack)
{
	int	top_number;

	top_number = stack->items[stack->top - 1];
	stack->items[stack->top - 1] = 0;
	stack->top--;
	return (top_number);
}

/*
	Adds a number at the top of a stack.
	Only possible when there is room in the stack.
*/
void	add_num(t_stack *stack, int number)
{
	if (stack->top >= stack->max_size)
		return;
	stack->items[stack->top] = number;
	stack->top++;
}

/*
	Take the first element at the top of stack two and
	put it at the top of stack one.
	Do nothing if two is empty
*/
void	push(t_stack *one, t_stack *two)
{
	int	number;

	if (two->top == 0 || one->top >= one->max_size)
		return;
	number = remove_num(two);
	add_num(one, number);
}

/*
	Shift up all elements of stack by 1.
	The first element becomes the last one.
*/
void	rotate(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->max_size - 1)
	{
		swap(stack, i, i + 1);
		i++;
	}
}

/*
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rev_rotate(t_stack *stack)
{
	int	i;

	i = stack->max_size - 1;
	while (i > 0)
	{
		swap(stack, i, i - 1);
		i--;
	}
}

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