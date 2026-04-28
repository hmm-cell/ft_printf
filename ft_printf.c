static	int	format_handler(const char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_un_putnbr(va_arg(args, unsigned int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned long), c));
	else if (c == 'p')
		return (ft_print_address((unsigned long)va_arg(args, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	l_ctr;

	l_ctr = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			l_ctr += format_handler(*format, args);
		}
		else
			l_ctr += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (l_ctr);
}

int main(void)
{
    ft_printf("O simokas tem %i anos e gosta de %s. \n %i", 19, "grandes serpentes", 67);
    return (0);
}
