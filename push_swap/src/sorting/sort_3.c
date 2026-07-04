/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 15:16:56 by bgorski           #+#    #+#             */
/*   Updated: 2026/07/04 16:07:47 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_stacklast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == -1)
		ft_printf("-1\n");
	ft_printf("rra\n");
}

void	sort_3(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->position;
	second = (*stack_a)->next->position;
	third = (*stack_a)->next->next->position;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
		sa(stack_a);
}
