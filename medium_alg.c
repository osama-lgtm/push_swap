#include "stacks.h"

int	get_chunk_count(int size)
{
	int	chunks;
	int	i;

	i = 0 ;
	while ( i * i < size)
		i++;
	chunks = i;
	return (chunks);
}

int	get_chunk_size(int size)
{
	int	chunk;

	chunk = size / get_chunk_count(size);
	return (chunk);
}

int	get_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (0);
	max = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (max->value < stack->value)
			max = stack;
	}
	return (max->value);
}

int	get_rank(t_stack *stack, int value)
{
	int			rank;
	t_stack	*current;

	current = stack;
	rank = 0;
	while (current)
	{
		if (current->value < value)
			rank++;
		current = current->next;
	}
	return (rank);
}

void	assign_ranks(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		current->rank = get_rank(stack, current->value);
		current = current->next;
	}
}

void	push_one_chunk(t_stack **a, t_stack **b, int start, int end, t_bench *bench)
{
	int	j;

	j = stack_size(*a);
	while (j > 0 && *a)
	{
		if ((*a)->rank >= start && (*a)->rank <= end)
			pb(a, b, bench, 1);
		else
			ra(a, bench, 1);
		j--;
	}
}

void	push_chunks(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	count;
	int	chunk_size;
	int	start;
	int	end;
	int	i;

	if (!*a)
		return ;
	size = stack_size(*a);
	assign_ranks(*a);
	count = get_chunk_count(size);
	chunk_size = get_chunk_size(size);
	start = 0;
	i = 0;
	while (i < count)
	{
		if (i == count - 1)
			end = size - 1;
		else
			end = start + chunk_size - 1;
		push_one_chunk(a, b, start, end, bench);
		start += chunk_size;
		i++;
	}
}
static void	move_max_to_top(t_stack **b, int position, int size, t_bench *bench)
{
	int	i;

	if (position <= size/2)
	{
		while(position)
		{
			rb(b, bench, 1);
			position--;
		}
	}
	else
	{
		i = size - position;
		while (i)
		{
			rrb(b, bench, 1);
			i--;
		}
	}
}

int	get_max_position(t_stack *b, int max)
{
	int	position;
	int	i;

	position = 0;
	i = 0;
	while (b)
	{
		if (b->value == max)
			position = i;
		b = b->next;
		i++;
	}
	return (position);
}

void	push_back(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max;
	int	position;
	int	size;

	while (*b)
	{
		size = stack_size(*b);
		max = get_max(*b);
		position = get_max_position(*b , max);
		move_max_to_top(b, position, size, bench);
		pa(a, b, bench, 1);
	}
}
void medium_alg(t_stack **a, t_stack **b, t_bench *bench)
{
	push_chunks(a, b, bench);
	push_back(a, b, bench);
}
