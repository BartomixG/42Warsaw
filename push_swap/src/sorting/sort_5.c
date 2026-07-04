/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 15:17:14 by bgorski           #+#    #+#             */
/*   Updated: 2026/07/04 16:07:00 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->position == 0 || (*stack_a)->position == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_3(stack_a);
	if ((*stack_b)->position < (*stack_b)->next->position)
		sb(stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}
