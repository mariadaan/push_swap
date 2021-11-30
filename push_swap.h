#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*
	Stack struct
	- max_size:			Maximum amount of numbers on stack
	- top:				Number of items pushed to stack so far
						Top index is pointing to the place in
						the array where the next element is to be inserted
	- items:			Array of items on the stack

	items[0]:			Bottom of stack
	items[top - 1]:		Last item on stack
	items[top]:			Where next element is to be inserted
*/
typedef struct s_stack
{
	int	max_size;
	int	top;
	int	*items;
}				t_stack;

// init
void	init_stack(t_stack *stack, int size);
void	fill_stack(t_stack *stack, char **numbers);

// check_input
int		is_int(char *num_str);
int		has_duplicates(int *items, int size);
int		is_all_ints(int argc, char **input);
int		check_input(t_stack *a, int argc, char **input);

// operations
void	swap_top(char *name, t_stack *stack);
void	push(char *name, t_stack *one, t_stack *two);
void	rotate(char *name, t_stack *stack);
void	rev_rotate(char *name, t_stack *stack);

// operations_extra
void	swap(t_stack *stack, int index_one, int index_two);
int		pop_num(t_stack *stack);
void	add_num(t_stack *stack, int number);

// utils
int		count_higher(int num, int *items, int len);
int		count_bits(int num);
void	copy_stack(t_stack *a, t_stack *copy);
void	simplify_stack(t_stack *a);

// algorithms
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	bubble_sort(t_stack *stack);
void	radix_sort(t_stack *a, t_stack *b);

#endif