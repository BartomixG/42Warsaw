#include "libft.h"

char	*ft_itoa(int n)
{
	char	buf[12];
	int		i;
	int		sign;
	long	num;

	num = n;
	sign = 0;
	i = 11;
	buf[i] = '\0';
	if (num < 0)
	{
		sign = 1;
		num = -num;
	}
	if (num == 0)
		buf[--i] = '0';
	while (num > 0)
	{
		buf[--i] = '0' + (num % 10);
		num /= 10;
	}
	if (sign)
		buf[--i] = '-';
	return (ft_strdup(&buf[i]));
}
