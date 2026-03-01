/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:22:51 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/26 22:02:24 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_2power(int exponent)
{
	int	value;

	value = 1;
	while (exponent-- > 0)
		value *= 2;
	return (value);
}

int	ft_howmanybits(t_stack *stack)
{
	int	size;
	int	bits;

	bits = 0;
	size = ft_stacksize(stack);
	while (ft_2power(bits) <= size)
		bits++;
	return (bits);
}

int	ft_issorted(t_stack *stack)
{
	t_stack	*current;
	t_stack	*further;

	if (stack->position != 0)
		return (0);
	current = stack;
	further = stack->next;
	while (further)
	{
		if (current->position + 1 != further->position)
			return (0);
		current = further;
		further = further->next;
	}
	return (1);
}
// //Issorted test
// int	main(int argc, char **argv)
// {
// 	t_stack *stack_a;
// 	t_stack	*head;
//
// 	stack_a = get_stack(argc, argv);
// 	head = stack_a;
// 	ft_printf("Is sorted: %i\n", ft_issorted(head));
// 	while (stack_a != NULL)
// 	{
// ft_printf("value: %i position: %i\n", stack_a->value, stack_a->position);
// 		stack_a = stack_a->next;
// 	}
// 	ft_stackclear(&head);
// 	return (0);	
// }
// //How man bits test
// int	main(int argc, char **argv)
// {
// 	t_stack *a;
//
// 	a = get_stack(argc, argv);
// 	ft_printf("how many bits for 15?: %d", ft_howmanybits(a));
// 	ft_stackclear(&a);
// }