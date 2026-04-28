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

void	ft_putnbr_fd(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10);
	ft_putchar_fd((nbr % 10) + '0');
}
