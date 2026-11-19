#include "stacks.h"
#include <unistd.h>

void ra(t_stack **a, int print)
{
	t_stack *first;
	t_stack *last;

	if (!a || !*a || !(*a)->next)
		return;

	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	if (print == 1)
		write(1, "ra\n", 3);
}

void rb(t_stack **b, int print)
{
	t_stack *first;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
		return;

	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
	*b = first->next;
	if (print == 1)
		write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void rra(t_stack **a, int print)
{
	t_stack *last;
	t_stack *second_last;

	if (!a || !*a || !(*a)->next)
		return;
	last = *a;
	second_last = *a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *a;
	second_last->next = NULL;
	*a = last;
	if (print == 1)
		write(1, "rra\n", 4);
}

void rrb(t_stack **b, int print)
{
	t_stack *second_last;
	t_stack *last;

	if (!b || !*b || !(*b)->next)
		return;
	last = *b;
	second_last = *b;

	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *b;
	second_last->next = NULL;
	*b = last;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
