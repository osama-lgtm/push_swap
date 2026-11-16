#include "stacks.h"

void	sa(t_stack **a, int print)
{
	int		temp;
	t_stack	*b;

	if (!((*a)->value) || !((*a)->next->value))
		return ;
	temp = (*a)->value;
	b = *a;
	*a = (*a)->next;
	b->value = (*a)->value;
	(*a)->value = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	int		temp;
	t_stack	*a;

	if (!((*b)->value) || !((*b)->next->value))
		return ;
	temp = (*b)->value;
	a = *b;
	*b = (*b)->next;
	a->value = (*b)->value;
	(*b)->value = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, int print)
{
	if (!*b)
		return ;
	(*b)->next = NULL;
	(*b)->next = *a;
	if (print == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	if (!*a)
		return ;
	(*a)->next = NULL;
	(*a)->next = *b;
	if (print == 1)
		write (1, "pb\n", 3);
}
