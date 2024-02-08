/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:26:01 by szhong            #+#    #+#             */
/*   Updated: 2024/01/31 17:05:48 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	printf_atoi(t_data *data);
static void	get_value(t_data *data, int *value);
static void	parse_flags(t_data *data);
int			parse_fmt(t_data *data);

static void	parse_flags(t_data *data)
{
	char	flag;
	t_format	*fmt;

	fmt = &data->format;
	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '-')
			fmt->left_justified = TRUE;
		else if (flag == '#')
			fmt->hash = TRUE;
		else if (flag == ' ')
			fmt->space = TRUE;
		else if (flag == '+')
			fmt->plus = TRUE;
		else if (flag == '0' && fmt->left_justified == 0 )
			data->format.zero_pads = TRUE;
		data->s++;
	}
	return ;
}

static void	get_value(t_data *data, int *value)
{
	int	nbrlen;
	char	*nbstr;

	nbstr = (char *)data->s;
	nbrlen = 0;
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		++data->s;
		return ;
	}
	while (in(NUMBERS, *nbstr))
	{
		nbstr++;
		nbrlen++;
	}
	if (nbrlen < 2)
	{
		*value = ft_atoi(data->s);
		if (*value != 0)
			data->s++;
		return ;
	}
	else
	{
		*value = printf_atoi(data);
		return ; 
	}
}

int	parse_fmt(t_data *data)
{
	ft_memset(&data->format, 0, sizeof(t_format));
	data->format.precision_value = -1;
	parse_flags(data);
	get_value(data, &data->format.width_value);
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->format.precision_value);
	if (!in(SPECIFIERS, *data->s))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
		if (in("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (in("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper = TRUE;
		}
		else if ('b' == data->format.specifier)
			data->format.base = BASE_2;
	}
	return (SUCCESS);
}

static int	printf_atoi(t_data *data)
{
	int	value;

	value = 0;
	while(in(NUMBERS, *data->s))
	{
		value = (value * 10) + (*data->s - '0');
		data->s++;
	}
	return (value);
}
