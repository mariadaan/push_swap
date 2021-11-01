#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdio.h>

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


#endif