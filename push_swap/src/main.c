#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	b = NULL;
	a = ft_parse_args(argc, argv);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ft_sort(&a, &b);
	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
	return (0);
}
