/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 15:35:30 by bgorski           #+#    #+#             */
/*   Updated: 2026/07/04 16:00:12 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_position;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_printf("Error\n");
	tmp_val = head->value;
	tmp_position = head->position;
	head->value = next->value;
	head->position = next->position;
	next->value = tmp_val;
	next->position = tmp_position;
	return (0);
}

void	sa(t_stack **stack_a)
{
	if (swap(stack_a) == -1)
		ft_printf("Error\n");
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b) == -1)
		ft_printf("Error\n");
	ft_printf("sb\n");
}
