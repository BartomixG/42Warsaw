#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* Stack operations */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* Stack utilities */
t_stack	*ft_lstnew_ps(int value);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
int		ft_lstsize_ps(t_stack *lst);
t_stack	*ft_lstlast_ps(t_stack *lst);
void	ft_lstclear_ps(t_stack **lst);
int		ft_stack_min(t_stack *lst);
int		ft_stack_max(t_stack *lst);
int		ft_is_sorted(t_stack *a);

/* Parsing */
t_stack	*ft_parse_args(int argc, char **argv);
int		ft_atoi_ps(const char *str, int *err);
int		ft_has_duplicates(t_stack *stack);

/* Sorting */
void	ft_sort(t_stack **a, t_stack **b);
void	ft_sort_three(t_stack **a);
void	ft_sort_small(t_stack **a, t_stack **b);
void	ft_sort_large(t_stack **a, t_stack **b);
void	ft_assign_indices(t_stack *a);
int		ft_find_best_push(t_stack *b, t_stack *a);
void	ft_rotate_to_top_a(t_stack **a, int value);
void	ft_rotate_to_top_b(t_stack **b, int value);

/* Output */
void	ft_error(t_stack **a, t_stack **b);

#endif
