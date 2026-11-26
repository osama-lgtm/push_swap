#include "stacks.h"

int stack_size(t_stack *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
        stack = stack->next;
    }
    return (count);
}
int find_min(t_stack *stack)
{
    t_stack *min;

    min = stack;
    while (stack->next)
    {
        stack = stack -> next;
        if (min->value  > stack->value)
            min = stack;
    }

    return (min->value);

}
int get_min_position(t_stack *stack)
{
    int position;
    int i ;
    int  min;

    min = find_min(stack);
    i = 0;
    position = 0;
    while (stack)
    {
        if (min == stack->value)
            position= i;
        i++;
        stack = stack->next;
    }
    return (position);
}
void move_min_to_top(t_stack **a,int position , int size, t_bench *bench)
{
	int	i;

    if (position <= size/2)
    {
		i = 0;
        while(position)
        {
            ra(a, bench, 1);
            position--;
        }
    }
    else
    {
        i = size - position;
        while (i)
        {
            rra(a, bench, 1);
            i--;
        }
    }
}

void	when_3elems(t_stack **a, t_stack **b, t_bench *bench, int position)
{
	if (position == 0)
	{
		pb(a, b, bench, 1);
		sa(a, bench, 1);
		pa(a, b, bench, 1);
	}
	else if (position == 1 && ft_lstlast(*a)->value > (*a)->value)
		sa(a, bench, 1);
	else if (position == 1)
		ra(a, bench, 1);
	else if (position == 2 && (*a)->value < (*a)->next->value)
		rra(a, bench, 1);
	else
	{
		sa(a, bench, 1);
		rra(a, bench, 1);
	}
}

void simple_alg(t_stack **a, t_stack **b, t_bench *bench)
{
    int size;
    int position;

    while (*a)
    {
    size = stack_size(*a);
    position = get_min_position(*a);
	if (size == 3)
	{
		when_3elems(a, b, bench, position);
		return ;
	}
    move_min_to_top(a, position, size, bench);
    pb(a, b, bench, 1);
    }
    while (*b)
        pa(a, b, bench, 1);
}
