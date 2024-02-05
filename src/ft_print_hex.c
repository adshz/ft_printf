/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:18:25 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 19:52:51 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_hex(unsigned int n, int is_upper, t_data data)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (data.precision == 0 && n == 0)
	{
		count += ft_pad_width(data.width, 0, 0);
		return (count);
	}
	nbstr = ft_printf_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_print_hexadec(nbstr, n, is_upper, data);
	free(nbstr);
	return (count);
}

int	ft_print_hexadec(char *nbstr, int n, int is_upper, t_data data)
{
	int	count;

	count = 0;
	if (data.zero == 1 && data.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (data.left == 1)
		count += ft_print_x(nbstr, n, is_upper, data);
	if (data.precision >= 0 && (size_t)data.precision < ft_strlen(nbstr))
		data.precision = ft_strlen(nbstr);
	if (data.precision >= 0)
	{
		data.width -= data.precision;
		count += ft_pad_width(data.width, 0, 0);
	}
	else
		count += ft_pad_width(dta.width, \
				ft_strlen(nbstr) + (data.hash * 2), data.zero);
	if (data.left == 0)
		count += ft_print_x(nbstr, n, is_upper, data);
	return (count);
}

int	ft_print_x(char *nbstr, int n, int is_upper, t_data data)
{
	int	count;

	count = 0;
	if (data.zero == 0 && data.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (data.precision >= 0)
		count += ft_pad_width(data.precision -1, \
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_s("0X");
	else
		ft_print_s("0x");
	return (2);
}
