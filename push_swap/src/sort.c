#include "push_swap.h"

/* Find position in a where value should be inserted (circular ascending order)
** Returns position of first element > value in circular sorted a.
** Both new max and new min go just after current max (at the break point). */
static int	ft_target_pos_in_a(t_stack *a, int value)
{
	t_stack	*cur;
	int		pos;
	int		max_pos;
	int		size;

	size = ft_lstsize_ps(a);
	max_pos = 0;
	pos = 0;
	cur = a;
	while (cur)
	{
		if (cur->value == ft_stack_max(a))
			max_pos = pos;
		pos++;
		cur = cur->next;
	}
	if (value > ft_stack_max(a) || value < ft_stack_min(a))
		return ((max_pos + 1) % size);
	cur = a;
	pos = 0;
	while (cur && cur->next)
	{
		if (cur->value <= value && cur->next->value > value)
			return (pos + 1);
		pos++;
		cur = cur->next;
	}
	return (0);
}

/* Insert element from top of b into correct position in a */
static void	ft_insert_to_a(t_stack **a, t_stack **b)
{
	int	target;
	int	pos;
	int	size;

	target = ft_target_pos_in_a(*a, (*b)->value);
	size = ft_lstsize_ps(*a);
	pos = target;
	if (pos == 0)
	{
		pa(a, b);
		return ;
	}
	if (pos <= size / 2)
	{
		while (target--)
			ra(a);
	}
	else
	{
		pos = size - pos;
		while (pos--)
			rra(a);
	}
	pa(a, b);
}

/* Large sort: push all but 3 to b, then insert back */
void	ft_sort_large(t_stack **a, t_stack **b)
{
	int		best;

	/* Push all but 3 elements to b */
	while (ft_lstsize_ps(*a) > 3)
		pb(a, b);
	ft_sort_three(a);
	/* Insert each element from b to correct position in a */
	while (*b)
	{
		best = ft_find_best_push(*b, *a);
		ft_rotate_to_top_b(b, best);
		ft_insert_to_a(a, b);
	}
	/* Rotate a to bring minimum to top */
	ft_rotate_to_top_a(a, ft_stack_min(*a));
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size;

	if (ft_is_sorted(*a))
		return ;
	size = ft_lstsize_ps(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		ft_sort_three(a);
	else if (size <= 5)
		ft_sort_small(a, b);
	else
		ft_sort_large(a, b);
}
