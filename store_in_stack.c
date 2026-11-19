#include "stacks.h"
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	num;
	int	n;

	n = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (*str - '0');
		str++;
	}
	return (num * n);
}

int fill_stack(t_stack **a, int argc, char **argv)
{
	int      i;
	t_stack *node;

	i = 1;
	while (i < argc)
	{
		node = ft_lstnew(ft_atoi(argv[i]));
		if (!node)
			return (0);
		ft_lstadd_back(a, node);
		i++;
	}
	return (1);
}
