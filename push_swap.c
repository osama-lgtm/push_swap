#include "stacks.h"

static double  compute_disorder(int argc,char **argv)
{
    int mistakes;
    int total_pairs;
	int i;

	mistakes = 0;
	i = 0;
    total_pairs = 0;
    while(i < argc)
    {
        while (argv[1 + total_pairs][i])
        {
            if (ft_atoi(argv[total_pairs]) > ft_atoi(argv[total_pairs + 1]))
                mistakes++;
            total_pairs++;
        }
    }
    return ((double)mistakes / total_pairs);
}

static int  ft_check(int argc,char **argv)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while(i < argc)
    {
        while(argv[i][j])
        {
            if (argv[i][j] == '-' || argv[i][j] == '+')
                j++;
            if (!(argv[i][j] <= '9' && argv[i][j] >= '0'))
                return (0);
            j++;
        }
        i++;
    }
}

int	push_swap(int argc, char **argv)
{
    double 	disorder;
    t_stack	*stack;
    if (!ft_check(argc, argv));
        return(write(1, "error", 5));
    disorder = compute_disorder(argc, argv);
    fill_stack(stack,argc,argv);
    strat_select(argv[1]);
}
