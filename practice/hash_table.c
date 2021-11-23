#include <stdio.h>

int push_a(int a, int b)
{
	printf("pa\n");
}
int push_b(int a, int b)
{
	printf("pb\n");
}
int swap_a(int a, int b)
{
	printf("sa\n");
}
int swap_b(int a, int b)
{
	printf("sb\n");
}

int (*p[4]) (int a, int b) = {push_a, push_b, swap_a, swap_b};


void command(int i)
{
	int a = 0;
	int b = 0;
	p[i](a, b);
}

int main(void)
{
	for (int x = 0; x < 4; x++)
	{
		command(x);
	}
}