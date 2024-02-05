/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:28:59 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 19:53:44 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	print_unsigned(unsigned n, t_data data)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (data.precision == 0 && n == 0)
	{
		count += ft_pad_width(data.width, 0, 0);
		return (count);
	}
	nbstr = ft_printf_utoa(n);
	if (!nbstr)
		return (0);
	count += ft_print_unint(nbstr, data);
	free(nbstr);
	return (count);
}

int	ft_print_unint(char *nbstr, t_data data)
{
	int	count;

	count = 0;
	if (data.left == 0)
		count += ft_print_u(nbstr, data);
	if (data.precision >= 0 && (size_t)data.precision < ft_strlen(nbstr))
		data.precision = ft_strlen(nbstr);
	if (data.precision >= 0)
	{
		data.width -= data.precision;
		count += ft_pad_width(data.width, 0, 0);
	}
	else
		count += ft_pad_width(data.width, ft_strlen(nbstr), data.zero);
	if (data.left == 0)
		count += ft_print_u(nbstr, data);
	return (count);
}

int	ft_print_u(char *nbstr, t_data data)
{
	int	count;
	
	count = 0;
	if (data.precision >= 0)
		count += ft_pad_width(data.precision - 1, \
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}
