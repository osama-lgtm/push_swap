#include "stacks.h"

double	compute_disorder(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		inversions;
	int		total_pairs;
	int		n;

	n = stack_size(stack_a);
	if (n < 2)
		return (0.0);
	inversions = 0;
	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				inversions++;
			j = j->next;
		}
		i = i->next;
	}
	total_pairs = (n * (n - 1)) / 2;
	return ((double)inversions / total_pairs);
}
