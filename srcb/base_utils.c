/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:54:29 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 13:43:57 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	in(const char *s, char c)
{
	if (!s)
		return (FALSE);
	while (*s)
	{
		if (*s == c)
			return (TRUE);
		s++;
	}
	return (FALSE);
}

void	set_padding_zeros(t_data *data)
{
	if (data->format.precision_value >= 0)
	{
		if (data->format.precision_value > data->format.nbrlen)
		{
			data->format.padding_zeros = data->format.precision_value - data->format.nbrlen;
			return ;
		}
	}
	if (data->format.zero_pads)
	{
		if (data->format.left_justified)
		{
			return ;
		}
		if (data->format.width_value > data->format.nbrlen)
			data->format.padding_zeros = data->format.width_value - data->format.nbrlen;
		if (data->format.specifier == 'u')
			return ;

		else if ((in("xX", data->format.specifier) &&\
					data->format.hash &&\
					data->format.buf_tmp[0] != '0') ||\
					data->format.specifier == 'p')
			data->format.padding_zeros -= 2;
		else if (data->format.is_negative ||\
				(!data->format.is_negative &&\
				 (data->format.plus || data->format.space)))
			data->format.padding_zeros--;
	}
	if (data->format.padding_zeros < 0)
		data->format.padding_zeros = 0;
}

void	set_padding_spaces(t_data *data)
{
	data->format.padding_spaces = data->format.width_value -\
				      data->format.padding_zeros -\
				      data->format.nbrlen;
	if ((in("uxXp", data->format.specifier) &&\
			data->format.hash &&\
			data->format.buf_tmp[0] != '0') ||\
				data->format.specifier == 'p')
				data->format.padding_spaces -= 2;
	if (data->format.is_negative)
	{
		data->format.padding_spaces--;
		return ;
	}
	if (!data->format.is_negative && data->format.plus)
	{
		data->format.padding_spaces--;
		return ;
	}
	if (!data->format.is_negative && data->format.space)
	{
		data->format.padding_spaces--;
		return ;
	}
}
