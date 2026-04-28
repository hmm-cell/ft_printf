int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	num_size(int n)
{
	int		size;
	long	nbr;

	nbr = n;
	size = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = -nbr;
		size++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

int	ft_putstr_fd(char *s)
{
	int	ctr;
	
	ctr = 0;
	if (!s)
		return (ctr);
	while (*s)
	{
		write(1, s, 1);
		s++;
		ctr++;
	}
	return (ctr);
}

int ft_putnbr(int n)
{
    int count;

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
