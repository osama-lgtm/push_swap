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
void move_min_to_top(t_stack **a,int position , int size)
{
    if (position <= size/2)
    {
        while(position)
        {
            ra(a,1);
            position--;
        }
    }
    else
    {
        int i = 0 ;
        i = size - position;
        while (i)
        {
            rra(a,1);
            i--;
        }
    }

}
void simple_alg(t_stack **a, t_stack **b)
{
    int size ;
    int position;

    while (*a)
    {
    size = stack_size(*a);
    position = get_min_position(*a);
    move_min_to_top(a, position, size);
    pb(a,b,1);

    }
    while (*b)
    {
        pa(a,b,1);
    }

}
