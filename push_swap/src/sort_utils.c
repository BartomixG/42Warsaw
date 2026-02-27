#include "push_swap.h"

/* Sort exactly 3 elements in stack a */
void	ft_sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && top > bot && mid < bot)
		ra(a);
	else if (top > mid && top > bot && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top < mid && top < bot && mid > bot)
	{
		sa(a);
		ra(a);
	}
	else if (top > mid && top < bot)
		sa(a);
	else if (top < mid && top > bot)
		rra(a);
}

/* Sort 4 or 5 elements */
void	ft_sort_small(t_stack **a, t_stack **b)
{
	int	min;

	while (ft_lstsize_ps(*a) > 3)
	{
		min = ft_stack_min(*a);
		while ((*a)->value != min)
			ra(a);
		pb(a, b);
	}
	ft_sort_three(a);
	while (*b)
		pa(a, b);
}

/* Assign sorted indices to stack elements */
void	ft_assign_indices(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	int		rank;

	i = a;
	while (i)
	{
		rank = 0;
		j = a;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

/* Find position of value in stack (from top) */
static int	ft_find_pos(t_stack *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

/* Rotate a to bring value to top optimally */
void	ft_rotate_to_top_a(t_stack **a, int value)
{
	int	size;
	int	pos;

	size = ft_lstsize_ps(*a);
	pos = ft_find_pos(*a, value);
	if (pos <= size / 2)
	{
		while ((*a)->value != value)
			ra(a);
	}
	else
	{
		while ((*a)->value != value)
			rra(a);
	}
}

/* Rotate b to bring value to top optimally */
void	ft_rotate_to_top_b(t_stack **b, int value)
{
	int	size;
	int	pos;

	size = ft_lstsize_ps(*b);
	pos = ft_find_pos(*b, value);
	if (pos <= size / 2)
	{
		while ((*b)->value != value)
			rb(b);
	}
	else
	{
		while ((*b)->value != value)
			rrb(b);
	}
}

/* Find the value in b that costs least moves to push to correct position in a */
int	ft_find_best_push(t_stack *b, t_stack *a)
{
	t_stack	*cur;
	int		best_val;
	int		best_cost;
	int		cost;
	int		pos_b;
	int		size_b;
	int		size_a;
	t_stack	*tmp;
	int		pos_a;

	cur = b;
	best_val = b->value;
	best_cost = INT_MAX;
	size_b = ft_lstsize_ps(b);
	size_a = ft_lstsize_ps(a);
	pos_b = 0;
	while (cur)
	{
		/* Cost to rotate b */
		if (pos_b <= size_b / 2)
			cost = pos_b;
		else
			cost = size_b - pos_b;
		/* Find where this value goes in a (target pos) */
		tmp = a;
		pos_a = 0;
		while (tmp)
		{
			if (tmp->value > cur->value)
				break ;
			pos_a++;
			tmp = tmp->next;
		}
		/* Cost to rotate a */
		if (pos_a <= size_a / 2)
			cost += pos_a;
		else
			cost += size_a - pos_a;
		if (cost < best_cost)
		{
			best_cost = cost;
			best_val = cur->value;
		}
		pos_b++;
		cur = cur->next;
	}
	return (best_val);
}
