#include "stacks.h"

void	pa(t_stack **a, t_stack **b, t_bench *bench, int print)
{
	t_stack	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (bench)
		bench->pa++;
	if (print == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, t_bench *bench, int print)
{
	t_stack	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (bench)
		bench->pb++;
	if (print == 1)
		write(1, "pb\n", 3);
}
