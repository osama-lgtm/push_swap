#include "stacks.h"

static void	set_strat_info(t_bench *b, char *name, char *complexity)
{
	b->strat_name = name;
	b->complexity = complexity;
}
void	putnbr_fd(int n, int fd)
{
	char	c;

	if (n >= 10)
		putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void	print_ops(t_bench *bench)
{
	write(2, "[bench] sa: ", 12);
	putnbr_fd(bench->sa, 2);
	write(2, " sb: ", 4);
	putnbr_fd(bench->sb, 2);
	write(2, " ss: ", 4);
	putnbr_fd(bench->ss, 2);
	write(2, " pa: ", 4);
	putnbr_fd(bench->pa, 2);
	write(2, " pb: ", 4);
	putnbr_fd(bench->pb, 2);
	write(2, "\n[bench] ra: ", 13);
	putnbr_fd(bench->ra, 2);
	write(2, " rb: ", 4);
	putnbr_fd(bench->rb, 2);
	write(2, " rr: ", 4);
	putnbr_fd(bench->rr, 2);
	write(-2, " rra: ", 5);
	putnbr_fd(bench->rra, 2);
	write(2, " rrb: ", 5);
	putnbr_fd(bench->rrb, 2);
	write(2 , " rrr: ", 5);
	putnbr_fd(bench->rrr, 2);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	print_benchmark(t_bench *b)
{
	int	total;
	int	whole;
	int	frac;

	total = b->sa + b->sb + b->ss + b->pa + b->pb
			+ b->ra + b->rb + b->rr + b->rra + b->rrb + b->rrr;
	whole = (int)(b->disorder * 100);
	frac = (int)((b->disorder * 100 - whole) * 100);
	write (2, "[bench] disorder: ", 18);
	putnbr_fd(whole, 2);
	write (2, ".", 1);
	if (frac < 10)
		write (2, "0", 1);
	putnbr_fd(frac, 2);
	write (2, "%\n[bench] strategy: ", 20);
	write (2, b->strat_name, ft_strlen(b->strat_name));
	write (2, "/ ", 3);
	write (2, b->complexity, ft_strlen(b->complexity));
	write (2, "\n[bench] total_ops: ", 20);
	putnbr_fd(total, 2);
	write (2, "\n", 1);
	print_ops(b);
}

static void	run_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench->disorder < 0.2)
	{
		set_strat_info(bench, "Adaptive ", "O(n^2)");
		simple_alg(a, b, bench);
	}
	else if (bench->disorder < 0.5)
	{
		set_strat_info(bench, "Adaptive ", "O(nsqrt(n))");
		medium_alg(a, b,bench);
	}
	else
	{
		set_strat_info(bench, "Adaptive ", "O(nlogn)");
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
