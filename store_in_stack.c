#include "stacks.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(const char *str, int *value)
{
	int	num;
	int	n;
	int	i;

	n = 1;
	num = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num += num * 10 + (str[i] - '0');
		i++;
	}
	*value = num * n;
	if (i == 0)
		return (0);
	return (1);
}

int	fill_stack(t_stack **a, int argc, char **argv)
{
	int		i;
	int		value;
	t_stack	*node;

	i = 0;
	while (i < argc)
	{
		if (!ft_atoi(argv[i], &value))
			return (0);
		node = ft_lstnew(value);
		if (!node)
			return (0);
		ft_lstadd_back(a, node);
		i++;
	}
	return (1);
}
