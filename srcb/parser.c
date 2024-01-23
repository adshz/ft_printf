/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:26:01 by szhong            #+#    #+#             */
/*   Updated: 2024/01/23 13:51:09 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static void parse_flags(t_data *data)
{
	char	flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '0')
			data->format.zero_pads = TRUE;
		else if (flag == '-')
			data->format.left_justified = TRUE;
		else if (flag == ' ')
			data->format.space = TRUE;
		else if (flag == '#')
			data->format.hash = TRUE;
		else if (flag == '+')
			data->format.plus = TRUE;
		data->s++;
	}
	return ;
}

static void get_value(t_data *data, int *value)
{
	if (data->s == '*')
	{
		*value = va_arg(data->ap, int);
		++data->s;
		return ;
	}
	*value = ft_atoi(data->s);
}

int	parse_format(t_data *data)
{
	ft_memset(&data->format, 0 , sizeof(t_format));
	data->format.precision_value = 1;
	parse_flags(data);
	get_value(data, data->format.width_value);
	if (*data->s == '.' && *(++data->s))
		get_value(data, data->format.precision_value);
	if (!in(SPECIFIERS, *data->format))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
		if (in("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (in('X', data->format.specifier))
			data->format.upper = TRUE;
		else if (in('b' == data->format.specifier))
			data->format.base = BASE_2;
	}
	return (OK);
}
