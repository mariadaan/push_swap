#include "../push_swap.h"

static int	is_operation(char *operation)
{
	char	**operations;
	int		function_index;

	operations = ft_split("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	function_index = ft_strin2darray(operations, operation);
	free_2darray(operations);
	return (function_index);
}

static void	exec_rotate(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strcmp(operation, "ra") == 0)
		rotate(NULL, a);
	else if (ft_strcmp(operation, "rb") == 0)
		rotate(NULL, b);
	else if (ft_strcmp(operation, "rr") == 0)
	{
		rotate(NULL, a);
		rotate(NULL, b);
	}
	else if (ft_strcmp(operation, "rra") == 0)
		rev_rotate(NULL, a);
	else if (ft_strcmp(operation, "rrb") == 0)
		rev_rotate(NULL, b);
	else if (ft_strcmp(operation, "rrr") == 0)
	{
		rev_rotate(NULL, a);
		rev_rotate(NULL, b);
	}
}

static void	exec_operation(char *operation, t_stack *a, t_stack *b)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap_top(NULL, a);
	else if (ft_strcmp(operation, "sb") == 0)
		swap_top(NULL, b);
	else if (ft_strcmp(operation, "ss") == 0)
	{
		swap_top(NULL, a);
		swap_top(NULL, b);
	}
	else if (ft_strcmp(operation, "pa") == 0)
		push(NULL, a, b);
	else if (ft_strcmp(operation, "pb") == 0)
		push(NULL, b, a);
	else
		exec_rotate(operation, a, b);
}

static int	free_stacks(t_stack *a, t_stack *b)
{
	free(a->items);
	free(b->items);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	*line;

	if (argc < 2)
		return (0);
	if (check_input(&a, argc, argv))
		return (error_msg("Error", 1));
	init_stack(&b, argc - 1);
	while (get_next_line(0, &line))
	{
		if (is_operation(line) != -1)
			exec_operation(line, &a, &b);
		else
			exit_msg("Error", 1);
		free(line);
	}
	free(line);
	if (a.top == a.max_size && is_sorted_descending(a.items, a.max_size))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stacks(&a, &b);
	return (0);
}
