void sa(stack a)
{
    int temp;

    temp = a.digit;
    b = a.next;
    a.digit = ;
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