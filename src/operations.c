#include "push_swap.h"

/*
	Swap the first 2 elements at the top of stack.
	Do nothing if there is only one or no elements.
*/
void	swap_top(char *name, t_stack *stack)
{
	if (stack->top < 2)
		return ;
	swap(stack, stack->top - 1, stack->top - 2);
	ft_putendl_fd(name, 1);
}

/*
	Take the first element at the top of stack two and
	put it at the top of stack one.
	Do nothing if two is empty
*/
void	push(char *name, t_stack *one, t_stack *two)
{
	int	number;

	if (two->top == 0 || one->top >= one->max_size)
		return ;
	number = pop_num(two);
	add_num(one, number);
	ft_putendl_fd(name, 1);
}

/*
	Shift up all elements of stack by 1.
	The first element becomes the last one.
*/
void	rotate(char *name, t_stack *stack)
{
	int	i;

	i = stack->max_size - 1;
	while (i > 0)
	{
		swap(stack, i, i - 1);
		i--;
	}
	ft_putendl_fd(name, 1);
}

/*
	Shift down all elements of stack a by 1.
	The last element becomes the first one.
*/
void	rev_rotate(char *name, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->max_size - 1)
	{
		swap(stack, i, i + 1);
		i++;
	}
	ft_putendl_fd(name, 1);
}
