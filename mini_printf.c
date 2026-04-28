static	int	format_handler(const char c, va_list args)
{
	int	num;
	char	*s;
	char	ch;
	int	l_ctr;
	
	if (c == 'i' || c == 'd')
	{
		return (ft_putnbr(va_arg(args, int)));
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
