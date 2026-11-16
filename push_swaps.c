#include "stacks.h"
void sa(t_stack *a)
{
    int temp;
    int b;

    temp = a->value;
    a = a->next;
    a->value = ;
    a[1] = temp;
    printf("sa ");
}

void sb(stack b)
{
    int temp;

    temp = b[0];
    b[0] = b[1];
    b[1] = temp;
    printf("sb ");
}

void ss(stack a, stack b)
{
    sa(stack a);
    sb(stack b);
    printf("ss ");
}

void pa()
{
    b[0] = a[0];
}

void pb()
{
    a[0] = b[0];
}