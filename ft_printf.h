#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/*
** Main function
*/
int	ft_printf(const char *format, ...);

/*
** Helper functions
*/
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_un_putnbr(unsigned int n);
int	ft_puthex(unsigned long n, char format);
int	ft_print_address(unsigned long n, char format);

#endif
