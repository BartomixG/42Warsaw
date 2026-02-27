#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	if (num >= 10)
		count += ft_putnbr(num / 10);
	count += ft_putchar('0' + (num % 10));
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putunbr(n / 10);
	count += ft_putchar('0' + (n % 10));
	return (count);
}

int	ft_puthex(unsigned long n, int uppercase)
{
	const char	*hex_lower = "0123456789abcdef";
	const char	*hex_upper = "0123456789ABCDEF";
	const char	*digits;
	int			count;

	digits = uppercase ? hex_upper : hex_lower;
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	count += ft_putchar(digits[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr, 0);
	return (count);
}
