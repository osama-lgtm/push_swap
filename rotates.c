#include "stacks.h"

void ra(t_stack **a, int print)
{
    t_stack *first;
    t_stack *last;

    first = *a;
    last = *a;

    while (last->next)
        last = last->next;
    (*a)->next = NULL;
    last->next = first;
	if (print == 1)
		write(1, "ra\n", 3);
}

void rb(t_stack **b, int print)
{
    t_stack *first;
    t_stack *last;

    first = *b;
    last = *b;

    while (last->next)
        last = last->next;
    (*b)->next = NULL;
    last->next = first;
	if (print == 1)
		write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rb(b, 0);
    ra(a, 0);
	write(1, "rr\n", 3);
}

void rra(t_stack **a, int print)
{
    t_stack *first;
    t_stack *last;
    t_stack *temp;

    first = *a;
    last = *a;

    while (last->next)
    {
        if (!(last->next->next))
            temp = last;
        last = last->next;
    }

    last->next = first;
    temp->next = NULL;
    *a = last;
	if (print == 1)
		write(1, "rra\n", 4);
}

void rrb(t_stack **b, int print)
{
    t_stack *first;
    t_stack *last;
    t_stack *temp;

    first = *b;
    last = *b;

    while (last->next)
    {
        if (!(last->next->next))
            temp = last;
        last = last->next;
    }

    last->next = first;
    temp->next = NULL;
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
