#include "stacks.h"

void	rra(t_stack **a, t_bench *bench, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!a || !*a || !(*a)->next)
		return ;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *a;
	second_last->next = NULL;
	*a = last;
	if (bench)
		bench->rra++;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_bench *bench, int print)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	second_last = *b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *b;
	second_last->next = NULL;
	*b = last;
	if (bench)
		bench->rrb++;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rra(a, bench, 0);
	rrb(b, bench, 0);
	if (bench)
		bench->rrr++;
	write (1, "rrr\n", 4);
}
