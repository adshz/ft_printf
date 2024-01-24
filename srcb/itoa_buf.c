/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:48:41 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 16:01:19 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	itoa_buff(t_data *data, union_int int_box)
{
	union_int	tmp;

	if (data->format.base < 2 || data->format.base > 16)
		return ;
	if (data->format.is_negative && !data->format.is_converted)
	{
		int_box.int64 = -(int_box.int64);
		data->format.is_converted = TRUE;
		itoa_buff(data, int_box);
	}
	else if (int_box.uint64 < data->format.base)
	{
		if (data->format.upper)
			data->format.buf_tmp[data->format.nbrlen++] = UP_HEX[int_box.uint64];
		else 
			data->format.buf_tmp[data->format.nbrlen++] = LO_HEX[int_box.uint64];
	}
	else
	{
		tmp.uint64 = int_box.uint64 / data->format.base;
		itoa_buff(data, tmp);
		tmp.uint64 = int_box.uint64 % data->format.base;
		itoa_buff(data, tmp);
	}
}
