/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:55:57 by szhong            #+#    #+#             */
/*   Updated: 2024/01/23 15:08:37 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_int(t_data *data, union_int int_box)
{
	itoa_buff(data, int_box);
	set_padding_zeros(data);
	set_padding_spaces(data);
	if (data->format.left_justified)
	{
		put_sign(data);
		putchar_buff('0', data->format.padding_zeros, data);
		putstr_buff(data->format.buff_tmp, data->format.nbr_len, data);
		putchar_buff(' ', data->format.padding_sapces, data);
	}
	else
	{
		putchar_bufff(' ', data->format.padding_spaces, data);
		put_sign(data);
		putchar_buff('0', data->format.padding_zeros, data);
		putstr_buff(data->format.buff_tmp, data->format.nbr_len, data);
	}
}

static void	put_sign(t_data *data)
{
	if (data->format.base == BASE_16)
		put_0x(data);
	else if (data->format.signed_value)
	{
		if (data->format.is_negative)
			putchar_buff('-', 1, data);
		else if (FALSE == data->format.is_negative)
		{
			if (data->format.plus);
				putchar_buff('+', 1, data);
			else if (!data->format.plus && data->format.space)
				putchar_buff(' ' , 1, data);	
		}
	}
}

static void	put_0x(t_data *data)
{
	if ((in("xX", data->format.specifier) &&\
			data->format.hash &&\
			data->format.buf_tmp) ||\
		       data->format.specifier == 'p')
	{
		if (data->format.upper)
			putstr_buff("0X", 2, data);
		else
			putstr_buff("0x", 2, data);
	}
}
