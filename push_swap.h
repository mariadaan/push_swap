#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

/*
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
int		check_input(int argc, char **input);
int		has_duplicates(int *items, int size);

// operations
void	swap(t_stack *stack, int index_one, int index_two);
int		pop_num(t_stack *stack);
void	add_num(t_stack *stack, int number);
void	swap_top(char *name, t_stack *stack);
void	push(char *name, t_stack *one, t_stack *two);
void	rotate(char *name, t_stack *stack);
void	rev_rotate(char *name, t_stack *stack);

// utils
int		is_sorted(int *items, int size);
int		count_higher(int num, int *items, int len);
int		count_bits(int num);
void	copy_stack(t_stack *a, t_stack *copy);
void	simplify_stack(t_stack *a);

void	print_stack(char *name, t_stack stack);
void	print_stacked(char *name, t_stack stack);
void	print_stacked_binary(char *name, t_stack stack);
void	print_array(char *name, int *numbers, int len);


// algorithms
void	bubble_sort(t_stack *stack);
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);

void	sort_stack(t_stack *a, t_stack *b);
int		has_bit(t_stack *a, int bit_place, int stack_place);


#endif