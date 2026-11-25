#include "stacks.h"
#include <stdio.h>

t_stack *ft_lstlast(t_stack *lst)
{
    while (lst && lst->next)
        lst = lst->next;
    return (lst);
}

void ft_lstadd_back(t_stack **lst, t_stack *new)
{
    if (!lst || !new)
        return;
    if (!*lst)
        *lst = new;
    else
        ft_lstlast(*lst)->next = new;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

t_stack *ft_lstnew(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}
