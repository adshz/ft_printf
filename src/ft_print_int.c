/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:06:11 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 19:52:22 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_int(int n, t_data data)
{
	char	*nbstr;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (data.zero == 0)
			data.width--;
	}
	if (data.precision == 0 && n == 0)
	{
		count += ft_pad_width(data.width, 0, 0);
		return (count);
	}
	nbstr = ft_print_itoa(nb);
	if (!nbstr)
		return (0);
	count += ft_print_integer(nbstr, n, data);
	free(nbstr);
	return (count);
}

int	ft_print_integer(char *nbstr, int n, t_data data)
{
	int	count;

	count = 0;
	if (data.zero == 1)
		count += ft_print_sign_precision(n, &data);
	if (data.left == 1)
		count += ft_print_i(nbstr, n, data);
	if (data.precision >= 0 && (size_t)data.precision < ft_strlen(nbstr))
		data.precision = ft_strlen(nbstr);
	if (data.precision >= 0)
	{
		data.width -= data.precision;
		if (n < 0 && data.left == 0)
			data.width -= 1;
		count += ft_pad_width(data.width, 0, 0);
	}
	else
		count += ft_pad_width(data.width - data.plus - data.space, \
				ft_strlen(nbstr), data.zero);
	if (data.left == 0)
		count += ft_print_i(nbstr, n, data);
	return (count);
}

int	ft_print_sign_precision(int n, t_data *data)
{
	int	count;

	count = 0;
	if (n < 0 && data->precision == -1)
	{
		count += ft_printchar('-');
		data->width--;
	}
	else if (data->plus == 1)
		count += ft_printchar('+');
	else if (data->space == 1)
	{
		count += ft_printchar(' ');
		data->width--;
	}
	return (count);

}

int	ft_print_i(char *nbstr, int n, t_data data)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (data.zero == 0 || data.precision >= 0)
			count += ft_printchar('-');
	}
	else if (data.plus == 1 && data.zero == 0)
		count += ft_printchar('+');
	else if (data.space == 1 && data.zeo == 0)
		count += ft_printchar(' ');
	if (data.precision >= 0)
		count += ft_pad_width(data.precision - 1,\
			       	ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

int	ft_print_s(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
