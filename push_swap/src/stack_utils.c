#include "push_swap.h"

t_stack	*ft_lstnew_ps(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_ps(*lst);
	last->next = new;
}

int	ft_lstsize_ps(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*next;

	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

int	ft_stack_min(t_stack *lst)
{
	int	min;

	if (!lst)
		return (INT_MAX);
	min = lst->value;
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	ft_stack_max(t_stack *lst)
{
	int	max;

	if (!lst)
		return (INT_MIN);
	max = lst->value;
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}

int	ft_is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_error(t_stack **a, t_stack **b)
{
	ft_lstclear_ps(a);
	ft_lstclear_ps(b);
	write(2, "Error\n", 6);
	exit(1);
}
