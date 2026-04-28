#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	num_size(int n)
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

int	ft_putstr_fd(char *s, int fd)
{
	int	ctr;
	
	ctr = 0;
	if (!s)
		return (ctr);
	while (*s)
	{
		write(fd, s, 1);
		s++;
		ctr++;
	}
	return (ctr);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(fd, "-", 1);
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10) + '0', fd);
}

static	int	format_handler(const char c, va_list args)
{
	int	num;
	char	*s;
	char	ch;
	int	l_ctr;
	
	if (c == 'i')
	{
		num = va_arg(args, int);
		l_ctr += num_size(n);
		ft_putnbr_fd(n, 1);
	}
	else if (c == 's')
	{
		s = va_arg(args, char *);
		l_ctr += ft_putstr_fd(s, 1);
	}
	else if (c == 'c')
	{
		ch = (char)va_arg(args, int);
		ft_putchar_fd(c, 1);
		l_ctr++;
	}
	else
	{
		ft_putchar_fd(*format, 1);
		l_ctr++;
	}
	
}

int	mini_printf(const char *format, ...)
{
	int	l_ctr;
	
	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			l_ctr = format_handler(*format, args);
		}
		format++;
	}
	va_end(args);
	return (l_ctr);
}

int main(void)
{
    mini_printf("O simokas tem %i anos e gosta de %s. \n %i", 19, "grandes serpentes", 67);
    return (0);
}
