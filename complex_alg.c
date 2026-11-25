#include "stacks.h"

static int get_max_bits(int size)
{
    int max;
    int bits;

    max = size - 1;
    bits = 0;
    while(max > 0)
    {
        bits++;
        max = max / 2;
    }
    return(bits);
}

 static void radix_pass(t_stack **a, t_stack **b, int bit, t_bench *bench)
{
    int size;
    int j;
    int num;
    size = stack_size(*a);
    j = 0 ;

    if (!*a)
        return;
    while (j < size)
    {
        num = (*a)->rank;
        if (((num >> bit) & 1) == 0 )
            pb(a, b, bench, 1);
        else
            ra(a, bench, 1);
        j++;
    }
    while(*b)
        pa(a, b, bench, 1);
}
void radix_sort(t_stack **a,t_stack **b, t_bench *bench)
{
    int size;
    int bits;
    int i;

    i = 0 ;
    size = stack_size(*a);
    assign_ranks(*a);
    bits = get_max_bits(size);
    while (i < bits )
    {
        radix_pass(a, b, i, bench);
        i++;
    }
}
void complex_alg(t_stack **a, t_stack **b, t_bench *bench)
{
    radix_sort(a, b, bench);

}
