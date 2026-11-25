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
	len = 0;
	while (number[len])
		len++;
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

int	where_start(char **argv)
{
	int	start;

	start = 1;
	while (argv[start])
	{
		if (!ft_strcmp(argv[start], "--bench") || !ft_strcmp(argv[start], "--simple")
				|| !ft_strcmp(argv[start], "--medium")
				|| !ft_strcmp(argv[start], "--complex")
				|| !ft_strcmp(argv[start], "--adaptive"))
			start++;
			else
				break ;
	}
	return (start);
}

int	check_repeat(int argc, char **argv, int start)
{
	int	j;

	while (start < argc)
	{
		j = start + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[start]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		start++;
	}
	return (1);
}

int	ft_check(int argc, char **argv)
{
	int	start;
	int	i;

	start = where_start(argv);
	i = start;
	if (start >= argc)
		return (0);
	while (i < argc)
	{
		if (!is_num(argv[i]))
			return (0);
		i++;
	}
	if (!check_repeat(argc, argv, start))
		return (0);
	return (start);
}
