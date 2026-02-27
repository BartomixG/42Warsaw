#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\f' || c == '\v');
}

int	ft_atoi_ps(const char *str, int *err)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
	{
		*err = 1;
		return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
		{
			*err = 1;
			return (0);
		}
		str++;
	}
	if (*str != '\0')
	{
		*err = 1;
		return (0);
	}
	return ((int)(sign * result));
}

int	ft_has_duplicates(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

t_stack	*ft_parse_args(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*node;
	int		err;
	int		val;
	int		i;

	stack = NULL;
	err = 0;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi_ps(argv[i], &err);
		if (err)
		{
			ft_lstclear_ps(&stack);
			return (NULL);
		}
		node = ft_lstnew_ps(val);
		if (!node)
		{
			ft_lstclear_ps(&stack);
			return (NULL);
		}
		ft_lstadd_back_ps(&stack, node);
		i++;
	}
	if (ft_has_duplicates(stack))
	{
		ft_lstclear_ps(&stack);
		return (NULL);
	}
	return (stack);
}
