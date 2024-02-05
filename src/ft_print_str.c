/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:52:40 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 19:50:25 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_string(const char *str, t_data data);

int	print_str(const char *str, t_data data)
{
	int	count;

	count = 0;
	if (str == NULL && data.precision >= 0 && data.precision < 6)
	{
		count += ft_pad_width(data.width, 0, 0);
		return (count);
	}
	if (str == NULL)
		str = "(null)";
	if (data.precision >= 0 && (size_t)data.precision > ft_strlen(str))
		data.precision = ft_strlen(str);
	if (data.left == 1)
		count += print_string(str, data);
	if (data.precision >= 0)
		count += ft_pad_width(data.width, data.precision, 0);
	else
		count += ft_pad_width(data.width, ft_strlen(str), 0);
	if (data.left == 0)
		count += print_string(str, data);
	return (count);
}

static int	print_string(const char *str, t_data data)
{
	int	count;

	count = 0;
	if (data.precision >= 0)
	{
		count += ft_pad_width(data.precision, ft_strlen(str), 0);
		count += print_precision(str, data.precision);
	}
	else
		count += print_precision(str, ft_strlen(str));
	return (count);
}

int	print_precision(const char *str, int precision)
{
	int	count;

	count = 0;
	if (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}
