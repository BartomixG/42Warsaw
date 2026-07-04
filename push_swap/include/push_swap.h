/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:51:47 by bgorski           #+#    #+#             */
/*   Updated: 2026/07/04 15:53:36 by bgorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				position;
	struct s_stack	*next;
}					t_stack;

t_stack	*get_stack(int argc, char **argv);
void	ft_stackclear(t_stack **lst);
int		ft_instack(t_stack *stack, int check);
int		ft_stacksize(t_stack *stack);
int		ft_isint(char *str);
int		ft_issorted(t_stack *stack);
int		ft_argcgen(char **argv);
t_stack	*ft_stacklast(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
int		ft_howmanybits(t_stack *stack);
void	ft_freesplit(char **arr);
void	sort_3(t_stack **stack_a);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

#endif
