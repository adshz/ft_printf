/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:45:29 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 14:05:06 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printchar(char c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
}

int	ft_fmt(const char specifier, va_list ap)
{
	int	print_count;

	print_count = 0;
	if (specifier == '%')
		print_count += ft_printchar('%');
	else if (specifier == 'c')
		print_count += ft_printchar(va_arg(ap, int));
	else if (specifier == 's')
		print_count += ft_printstr(va_arg(ap, char *));
	else if (specifier == 'p')
		print_count += ft_printptr(va_arg(ap, unsigned long long));
	else if (specifier == 'd' || specifier == 'i')
		print_count += ft_printnbr(va_arg(ap, int));
	else if (specifier == 'u')
		print_count += ft_print_unsigned_decimal(va_arg(ap, unsigned int));
	else if (specifier == 'X' || specifier == 'x')
		print_count += ft_printhex(va_arg(ap, unsigned int), specifier);
	return (print_count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		written_count;
	int		i;

	va_start(ap, fmt);
	i = 0;
	written_count = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			written_count += ft_fmt(fmt[i + 1], ap);
			i++;
		}
		else
			written_count += ft_printchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (written_count);
}
