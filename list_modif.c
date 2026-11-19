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

void ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return;
	new->next = *lst;
	*lst = new;
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
