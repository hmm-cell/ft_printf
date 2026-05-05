#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	ctr;

	ctr = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (*s)
	{
		write(1, s, 1);
		s++;
		ctr++;
	}
	return (ctr);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_un_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_un_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}
