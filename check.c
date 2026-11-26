#include "stacks.h"

int	check_overflow(char *number)
{
	char	*limit;
	int		len;
	int		neg;

	neg = 0;
	if (number[0] == '-' || number[0] == '+')
	{
		if (number[0] == '-')
			neg = 1;
		number++;
	}
	while (*number == '0' && number[1])
		number++;
	len = ft_strlen(number);
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	limit = "2147483647";
	if (neg == 1)
		limit = "2147483648";
	return (ft_strcmp(number, limit) > 0);
}

int	is_num(char *a)
{
	int	i;

	if (check_overflow(a))
		return (0);
	i = 0;
	if (a[i] == '-' || a[i] == '+')
		i++;
	if (!a[i])
		return (0);
	while (a[i])
	{
		if (a[i] > '9' || a[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

static int	is_strat(char *arg)
{
	if (!arg)
		return (0);
	return (!ft_strcmp(arg, "--simple") || !ft_strcmp(arg, "--medium")
		|| !ft_strcmp(arg, "--complex") || !ft_strcmp(arg, "--adaptive"));
}

int	where_start(char **argv)
{
	if (!argv || !argv[1])
		return (1);
	if (!ft_strcmp(argv[1], "--bench"))
	{
		if (is_strat(argv[2]))
		{
			if (is_strat(argv[3])
				|| (argv[3] && !ft_strcmp(argv[3], "--bench")))
				return (0);
			return (3);
		}
		if (argv[2] && !ft_strcmp(argv[2], "--bench"))
			return (0);
		return (2);
	}
	if (is_strat(argv[1]))
	{
		if (is_strat(argv[2]) || (argv[2] && !ft_strcmp(argv[2], "--bench")))
			return (0);
		return (2);
	}
	return (1);
}

int	ft_check(int argc, char **argv)
{
	int	start;
	int	i;
	int	j;
	int	n1;
	int	n2;

	start = where_start(argv);
	if (start <= 0 || start >= argc)
		return (0);
	i = start - 1;
	while (++i < argc)
	{
		if (!is_num(argv[i]))
			return (0);
		j = i;
		while (++j < argc)
		{
			if (!ft_atoi(argv[i], &n1) || !ft_atoi(argv[j], &n2))
				return (0);
			if (n1 == n2)
				return (0);
		}
	}
	return (start);
}
