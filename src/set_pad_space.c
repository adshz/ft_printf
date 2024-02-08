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

void	set_padding_spaces(t_data *data)
{
	cal_padding_space(data);
	adj_space_special(data);
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

void	cal_padding_space(t_data *data)
{
	int	width;
	int	padding_zeros;
	int	len;

	width = data->format.width_value;
	padding_zeros = data->format.padding_zeros;
	len = data->format.nbrlen;
	data->format.padding_spaces = width - padding_zeros - len;
	return ;
}

void	adj_space_special(t_data *data)
{
	char	spec;
	int		is_hash;
	char	terminator;

	spec = data->format.specifier;
	is_hash = data->format.hash;
	terminator = data->format.buf_tmp[0];
	if ((in("uxXp", spec) && is_hash && terminator != '0') || \
			spec == 'p')
		data->format.padding_spaces -= 2;
	return ;
}
