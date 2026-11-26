#include "stacks.h"

static void	set_strat_info(t_bench *b, char *name, char *complexity)
{
	b->strat_name = name;
	b->complexity = complexity;
}

static void	run_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->disorder == 0)
		return ;
	if (bench->disorder < 0.2)
	{
		set_strat_info(bench, "Adaptive ", "O(n^2)");
		simple_alg(a, b, bench);
	}
	else if (bench->disorder < 0.5)
	{
		set_strat_info(bench, "Adaptive ", "O(n√n)");
		medium_alg(a, b,bench);
	}
	else
	{
		set_strat_info(bench, "Adaptive ", "O(n log n)");
		complex_alg(a, b,bench);
	}
}

void	strat_select(char *flag, t_stack **a, t_stack **b, t_bench *bench)
{
	if (flag && !ft_strcmp(flag, "--simple"))
	{
		set_strat_info(bench, "Simple", "O(n^2)");
		simple_alg(a, b,bench);
	}
	else if (flag && !ft_strcmp(flag, "--medium"))
	{
		set_strat_info(bench, "Medium", "O(nsqrt(n))");
		medium_alg(a, b,bench);
	}
	else if (flag && !ft_strcmp(flag, "--complex"))
	{
		set_strat_info(bench, "Complex", "O(nlogn)");
		complex_alg(a, b,bench);
	}
	else
		run_adaptive(a, b, bench);
}
