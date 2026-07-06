/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:22:33 by bgorski           #+#    #+#             */
/*   Updated: 2026/07/04 18:59:56 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <unistd.h>

static int	ft_iserror(char **arr)
{
	if (ft_argcgen(arr) < 2)
	{
		if (!ft_isint(arr[0]))
			write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

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

void	ft_scenario(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (ft_issorted(*stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else if (size > 5)
		ft_radix(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	char	**read;
	t_stack	*stack_a;
	t_stack	*stack_b;

	read = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		read = ft_split(argv[1], ' ');
		if (ft_iserror(read))
			return (ft_freesplit(read), argc);
		stack_a = get_stack(ft_argcgen(read), read);
		ft_freesplit(read);
	}
	else
		stack_a = get_stack(argc, argv);
	if (!stack_a)
		return (ft_stackclear(&stack_a), 0);
	ft_scenario(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	return (0);
}
