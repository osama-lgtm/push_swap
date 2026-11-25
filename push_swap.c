#include "stacks.h"

static void	init_bench(t_bench *bench)
{
	bench->enabled = 0;
	bench->disorder = 0.0;
	bench->strat_name = "";
	bench->complexity = "";
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

static void	check_bench_mode(int argc, char **argv, t_bench *bench)
{
	int	i;

	i = 1;
	while (i < argc && argv[i])
	{
		if (!ft_strcmp(argv[i], "--bench"))
		{
			bench->enabled = 1;
			break ;
		}
		i++;
	}
}

static char	*get_strategy_flag(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--simple")
			|| !ft_strcmp(argv[i], "--medium")
			|| !ft_strcmp(argv[i], "--complex")
			|| !ft_strcmp(argv[i], "--adaptive"))
			return (argv[i]);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_bench	bench;
	int			start;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_bench(&bench);
	check_bench_mode(argc, argv, &bench);
	start = ft_check(argc, argv);
	if (!start)
		return (write(2, "Error\n", 6), 1);
	if (!fill_stack(&stack_a, argc - start, &argv[start]))
	{
		free_stack(&stack_a);
		return (write(2, "Error\n", 6), 1);
	}
	bench.disorder = compute_disorder(stack_a);
	strat_select(get_strategy_flag(argv), &stack_a, &stack_b, &bench);
	if (bench.enabled)
		print_benchmark(&bench);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
