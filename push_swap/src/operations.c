#include "push_swap.h"

/* sa: swap the first 2 elements at the top of stack a */
void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "sa\n", 3);
}

/* sb: swap the first 2 elements at the top of stack b */
void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "sb\n", 3);
}

/* ss: sa and sb at the same time */
void	ss(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "ss\n", 3);
}

/* pa: push top of b to top of a */
void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

/* pb: push top of a to top of b */
void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}

/* ra: rotate stack a upwards */
void	ra(t_stack **a)
{
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	last = ft_lstlast_ps(*a);
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

/* rb: rotate stack b upwards */
void	rb(t_stack **b)
{
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	last = ft_lstlast_ps(*b);
	last->next = *b;
	*b = (*b)->next;
	last->next->next = NULL;
	write(1, "rb\n", 3);
}

/* rr: ra and rb at the same time */
void	rr(t_stack **a, t_stack **b)
{
	t_stack	*last;

	if (*a && (*a)->next)
	{
		last = ft_lstlast_ps(*a);
		last->next = *a;
		*a = (*a)->next;
		last->next->next = NULL;
	}
	if (*b && (*b)->next)
	{
		last = ft_lstlast_ps(*b);
		last->next = *b;
		*b = (*b)->next;
		last->next->next = NULL;
	}
	write(1, "rr\n", 3);
}

/* rra: reverse rotate stack a */
void	rra(t_stack **a)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

/* rrb: reverse rotate stack b */
void	rrb(t_stack **b)
{
	t_stack	*last;
	t_stack	*prev;

	if (!*b || !(*b)->next)
		return ;
	last = *b;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

/* rrr: rra and rrb at the same time */
void	rrr(t_stack **a, t_stack **b)
{
	t_stack	*last;
	t_stack	*prev;

	if (*a && (*a)->next)
	{
		last = *a;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *a;
		*a = last;
	}
	if (*b && (*b)->next)
	{
		last = *b;
		prev = NULL;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
	write(1, "rrr\n", 4);
}
