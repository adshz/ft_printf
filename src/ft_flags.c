/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:19:09 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 16:27:15 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_data flag_left(t_data data)
{
	data.left = 1;
	data.zero = 0;
	return (data);
}

int	flag_precision(const char *str, int pos, va_list ap, t_data *data)
{
	int	i;

	i = pos + 1;
	if (str[i] == '*')
	{
		data->precision = va_arg(ap, int);
		return (i++);
	}
	data->precision = 0;
	while (ft_isdigit(str[i]))
	{
		data->precision = (data->precision * 10) (str[i] - '0');
		i++;
	}
	return (i);
}

t_data	flag_width(va_list ap, t_data data);
{
	data.star = 1;
	data.width = va_arg(ap, int);
	if (data.width < 0)
	{
		data.left = 1;
		data.width *= -1;
	}
	return (data);
}

t_data	flag_digit(char c, t_data data)
{
	if (data.star == 1)
		data.width = 0;
	data.width = (data.width * 10) + (c - '0');
	return (data);
}

