#include "libft/libft.h"
#include "push_swap.h"

int main (void)
{
	int x = 2675;
	int f;

	f = x >> 4 & 1;

	ft_putbasenbr(x, 2);
	ft_putchar('\n');
	ft_putbasenbr(f, 2);
	ft_putchar('\n');
}

/*
	checken of er nog een 0 op de place zit ONDER een 1

	returns 1 als er nog een 0 onder zit
	returns 0 als er geen 0 onder zit
*/
int		has_bit(t_stack *a, int place)
{
	int i;
	int j;

	i = a->top - 1;
	while (i > 0)
	{
		if (((a->items[i] >> place) & 1) == 1)
		{
			j = i - 1;
			// checken of er nog een 0 onder zit
			while (j > 0)
			{
				if (((a->items[j] >> place) | 0) == 0)
					return (1);
				j--;
			}

		}
		i++;
	}
	return (0);
}