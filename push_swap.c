#include "stacks.h"

static double	compute_disorder(int *a)
{
	int mistakes = 0;
	int pair = 0;
	int temp;

	while (a[pair])
	{
		temp = a[pair];
		pair++;
		if (a[pair] < temp)
			mistakes++;
	}
	return ((double)mistakes / pair);
}
static void strat_select(char *strat)
{
	if (strcmp(strat, "--simple"))
	{

	}
	else if (strcmp(strat, "--medium"))
	{

	}
	else if (strcmp(strat, "--complex"))
	{

	}
}
int	ft_check(int *numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		
	}
	if (i == 0)
		return (0);
}
void	push_swap(int *numbers, char *strat)
{
	t_stack *a;
	t_stack *b;

	if (ft_check(numbers) == 0);
		return (write(2, "Error", 5));
	if (compute_disorder(numbers) < 0.2)
	{
		simple_alg(a, b);
	}
	else if (compute_disorder(numbers) < 0.5 && compute_disorder(numbers) > 0.2)
	{
		medium_alg(a, b);
	}
	else
	{
		complex_alg(a, b);
	}
}
