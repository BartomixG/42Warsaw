/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:14:21 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/26 21:53:21 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_stackdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*next_node;
	t_stack	*current;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		current = *lst;
		next_node = (*lst)->next;
		ft_stackdelone(current);
		*lst = next_node;
	}
	*lst = NULL;
}

int	ft_instack(t_stack *stack, int check)
{
	while (stack != NULL)
	{
		if (stack->value == check)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	ft_isint(char *str)
{
	long	nb;
	int		positive;

	nb = 0;
	positive = 1;
	if (!str || *str == '\0')
		return (0);
	if (str[0] == '-')
	{
		positive = 0;
		str++;
	}
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		nb = nb * 10 + (*(str++) - '0');
		if (positive == 1 && nb > INT_MAX)
			return (0);
		if (positive == 0 && - nb < INT_MIN)
			return (0);
	}
	return (1);
}

int	ft_stacksize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
