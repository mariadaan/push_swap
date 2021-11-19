#include "push_swap.h"

/*
	Removes a number from the top of the stack.
	Return this number.
*/
int	pop_num(t_stack *stack)
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
		return ;
	stack->items[stack->top] = number;
	stack->top++;
}

/*
	Swap 2 elements in stack.
	Do nothing if indexes of the elements are above top of stack.
*/
void	swap(t_stack *stack, int index_one, int index_two)
{
	int	temp;

	if (index_one >= stack->top || index_two >= stack->top)
		return ;
	temp = stack->items[index_one];
	stack->items[index_one] = stack->items[index_two];
	stack->items[index_two] = temp;
}
