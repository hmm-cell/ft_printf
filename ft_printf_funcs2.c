/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_funcs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: side-oli <side-oli@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:45:51 by side-oli          #+#    #+#             */
/*   Updated: 2026/05/05 10:50:56 by side-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	if ((n % 16) < 10)
		count += ft_putchar(n % 16 + '0');
	else if (format == 'X')
		count += ft_putchar((n % 16) - 10 + 'A');
	else if (format == 'x')
		count += ft_putchar((n % 16) - 10 + 'a');
	return (count);
}

int	ft_print_address(unsigned long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (ft_putstr("(nil)"));
	else
	{
		count += ft_putstr("0x");
		count += ft_puthex(n, 'x');
	}
	return (count);
}
