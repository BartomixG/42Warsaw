/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 21:55:36 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/26 21:57:21 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack)
	{
		if (stack->next == NULL)
			break ;
		stack = stack->next;
	}
	return (stack);
}

static void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = ft_stacklast(*stack);
	tmp->next = new;
}

static int	ft_position(char **argv, int index, int argc)
{
	int	nb;
	int	position;
	int	i;

	i = 1;
	position = 0;
	nb = atoi(argv[index]);
	if (argc < 2)
		return (-1);
	while (i < argc)
	{
		if (nb > atoi(argv[i++]))
			position++;
	}
	return (position);
}

static t_stack	*new_node(int argc, int index, char **argv)
{
	t_stack	*node;

	if (ft_isint(argv[index]) == 0)
		return (NULL);
	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = ft_atoi(argv[index]);
	node->position = ft_position(argv, index, argc);
	if (node->position < 0)
		return (NULL);
	node->next = NULL;
	return (node);
}

t_stack	*get_stack(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;

	stack_a = NULL;
	i = 0;
	if (ft_isdigit(argv[0][0]) == 0 && argv[0][0] != '-')
		i++;
	while (i < argc)
	{
		tmp = new_node(argc, i++, argv);
		if (!tmp || ft_instack(stack_a, tmp->value) == 1)
		{
			free(tmp);
			ft_stackclear(&stack_a);
			ft_printf("Error\n");
			return (NULL);
		}
		ft_stackadd_back(&stack_a, tmp);
	}
	return (stack_a);
}
//
// int	main(int argc, char **argv)
// {
// 	t_stack *stack_a;
// 	t_stack	*head;
//
// 	stack_a = get_stack(argc, argv);
// 	head = stack_a;
// 	while (stack_a != NULL)
// 	{
// ft_printf("value: %i position: %i\n", stack_a->value, stack_a->position);
// stack_a = stack_a->next;
// 	}
// 	ft_stackclear(&head);
// 	return (0);	
// }
