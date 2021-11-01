#include "push_swap.h"

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