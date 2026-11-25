#include "stacks.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	n;

	n = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num += num * 10 + (*str - '0');
		str++;
	}
	return (num * n);
}

int	fill_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	int		value;
	t_stack	*node;

	i = 0;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (!value)
			return (0);
		node = ft_lstnew(value);
		if (!node)
			return (0);
		ft_lstadd_back(a, node);
		i++;
	}
	return (1);
}
