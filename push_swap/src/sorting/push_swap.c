/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:22:33 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/27 01:31:49 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	bit;
	int	i;
	int	n;
	int	bits;

	n = ft_stacksize(*stack_a);
	bits = ft_howmanybits(*stack_a);
	bit = 0;
	while (bit < bits)
	{
		if (ft_issorted(*stack_a))
			return ;
		i = 0;
		while (i++ < n)
		{
			if (((*stack_a)->position >> bit) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	char	**read;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*head;

	read = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		read = ft_split(argv[1], ' ');
		if (ft_argcgen(read) < 2)
			return (ft_freesplit(read), argc);
		stack_a = get_stack(ft_argcgen(read), read);
	}
	else
		stack_a = get_stack(argc, argv);
	if (!stack_a)
		return (ft_freesplit(read), argc);
	while (stack_a != NULL)
	{
		ft_printf("value: %i position: %i\n", stack_a->value, stack_a->position);
		stack_a = stack_a->next;
	}
	ft_radix(&stack_a, &stack_b);
	head = stack_a;
	if (read)
		ft_freesplit(read);
	ft_stackclear(&head);
	return (argc);
}
