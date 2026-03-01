/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgorski <bgorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:51:47 by bgorski           #+#    #+#             */
/*   Updated: 2026/02/22 17:01:33 by bgorski          ###   ########.fr       */
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
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
int		ft_howmanybits(t_stack *stack);
void	ft_freesplit(char **arr);
#endif
