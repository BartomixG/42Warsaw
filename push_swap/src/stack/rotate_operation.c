/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 11:19:03 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/26 21:54:44 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate_up(t_stack **s)
{
	t_stack	*first;
	t_stack	*last;

	if (!s || !*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	first->next = NULL;
	last = ft_stacklast(*s);
	last->next = first;
}

void	ra(t_stack **a)
{
	rotate_up(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate_up(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate_up(a);
	rotate_up(b);
	ft_printf("rr\n");
}
