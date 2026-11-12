#include "stacks.h"

static double  compute_disorder(int *a)
{
    mistakes = 0
    total_pairs = 0
    for i from 0 to size(a)-1:
        for j from i+1 to size(a)-1:
            total_pairs += 1
    if a[i] > a[j]:
        mistakes += 1
    return ((double)mistakes / total_pairs)
}
static void strat_select(char *strat)
{
    if (strcmp(strat, "--simple"))
    {

    }
    else if (strcmp(strat, "--medium"))
    {

    }
    else if (strcmp(strat, "--complex"))
    {

    }
}

void    push_swap(int *a)
{
    double  disorder;

    if (ft_check(int *a) == 0);
        return(printf("error"));
    disorder = compute_disorder(a);
    if (disorder < 0.2)
    {
	    simple_alg();
    }
    else if (disorder < 0.5 && disorder > 0.2)
    {
	    medium_alg();
    }
    else
    {
	    complex_alg();
    }
}
