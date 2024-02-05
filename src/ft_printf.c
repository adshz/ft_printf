/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:45:29 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 19:41:09 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		written_count;
	char	*dup;

	if (!fmt || *fmt == '\0')
		return (FORMAT_STRING_EMPTY);
	dup = ft_strdup(fmt);
	if (!dup || *dup == '\0')
		return (FORMAT_STRING_EMPTY);
	written_count = 0;
	va_start(ap, fmt);
	written_count = parse_fmt(dup, ap);
	va_end(ap);
	free(dup);
	return (written_count);
}

#if defined(__linux__) || defined(__gnu_linux__)

int	parse_fmt(char *dup, va_list ap)
{
	int	i;
	int	x;
	int	count;
	t_data	data;

	i = -1;
	count = 0;
	while (dup[++i])
	{
		data = data_init();
		if (dup[i] == '%' && dup[i + 1] != '\0')
		{
			x = parse_flags(dup, i, ap, &data);
			if (data.spec > 0)
				i = x;
			if (dup[i] != '\0' && data.spec > 0 && ft_istype(dup[i]))
				count += print_arg(dup[i], ap, data);
			else if (dup[i] != '\0')
				count += ft_printchar(dup[i]);
		}
		else
			count += ft_printchar(dup[i]);
	}
	return (count);
}

#else

int	parse_fmt(char *dup, va_list ap)
{
	int	i;
	int	count;
	t_data	data;

	i = -1;
	count = 0;
	while(dup[++i])
	{
		data = data_init();
		if (dup[i] == '%' && dup[i + 1] != '\0')
		{
			i = parse_flags(dup, i, ap, &data);
			if (dup[i] != '\0' && data.spec > 0 && ft_istype(dup[i]))
				count += print_arg(dup[i], ap, data);
			else if (dup[i] != '\0')
				count += print_char(dup[i], data);
		}
		else
			count += ft_printchar(dup[i]);
	}
	return (count);
}

#endif

t_data data_init(void)
{
	t_data	data;

	data.spec = 0;
	data.width = 0;
	data.left = 0;
	data.zero = 0;
	data.star = 0;
	data.precision = -1;
	data.hash = 0;
	data.space = 0;
	data.plus = 0;
	return (data);
}

int	parse_flags(const char *str, int i, va_list ap, t_data *data)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*data = flag_left(*data);
		if (str[i] == '#')
			data->hash = 1;
		if (str[i] == ' ')
			data->space = 1;
		if (str[i] == '+')
			data->plus = 1;
		if (str[i] == '0' && data->left == 0 && data->width == 0)
			data->zero = 1;
		if (str[i] == '.')
			i = flag_precision(str, i, ap, data);
		if (str[i] == '*')
			*data = flag_width(ap, *data);
		if (ft_isdigit(str[i]))
			*data = flag_digit(str[i], *data);
		if (ft_istype(str[i]))
		{
			data->spec = str[i];
			break ;
		}
	}
	return (i);
}

int	print_arg(char specifier, va_list ap, t_data data)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += print_char('%', data);
	else if (specifier == 'c')
		count += print_char(va_arg(ap, int), data);
	else if (specifier == 's')
		count += print_str(va_arg(ap, const char *), data);
	else if (specifier == 'd' || specifier == 'i')
		count += print_int(va_arg(ap, int), data);
	else if (specifier == 'x')
		count += print_hex(va_arg(ap, unsigned int), 0, data);
	else if (specifier == 'X')
		count += print_hex(va_arg(ap, unsigned int), 1, data);
	else if (specifier == 'u')
		count += print_unsigned(va_arg(ap, unsigned int), data);
	else if (specifier == 'p')
		count += print_ptr((unsigned long int)va_arg(ap, void *), data);
	return (count);
}

