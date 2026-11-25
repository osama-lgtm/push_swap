#include "stacks.h"

void	ra(t_stack **a, t_bench *bench, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (bench)
		bench->ra++;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, t_bench *bench, int print)
{
	t_stack	*first;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (bench)
		bench->rb++;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a, bench, 0);
	rb(b, bench, 0);
	if (bench)
		bench->rr++;
	write (1, "rr\n", 3);
}
