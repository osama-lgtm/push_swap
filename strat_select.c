int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void strat_select(char *strat)
{
    if (strcmp(strat, "--simple"))
    {
        simple_alg();
    }
    else if (strcmp(strat, "--medium"))
    {
        medium_alg();
    }
    else if (strcmp(strat, "--complex"))
    {
        complex_alg();
    }
}
