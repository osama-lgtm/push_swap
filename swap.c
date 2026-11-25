#include "stacks.h"

void	sa(t_stack **a, t_bench *bench, int print)
{
	int	temp;

	if (!a || !*a || !((*a)->next))
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
	if (bench)
		bench->sa++;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, t_bench *bench, int print)
{
	int	temp;

	if (!b || !*b || !((*b)->next))
		return ;
	temp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = temp;
	if (bench)
		bench->sb++;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa(a, bench, 0);
	sb(b, bench, 0);
	if (bench)
		bench->ss++;
	write(1, "ss\n", 3);
}
