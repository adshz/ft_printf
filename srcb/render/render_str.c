/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:14:03 by szhong            #+#    #+#             */
/*   Updated: 2024/01/23 15:44:14 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_str(t_data *data, char *s)
{
	if (s == NULL)
		s = "(null)";
	set_str_padding_spaces(data, s);
	if (data->format.left_justified)
	{
		print_spaces();
		putchar_buff(' ', data->format.padding_spaces, data);
	}
	else
	{
		putchar_buff(' ', data->format.padding_spaces, data);
		print_spaces();
	}
}

static void	print_spaces(void)
{
	if (data->format.precision_value >= 0)
		putstr_buff(s, data->format.precision_value, data);
	else
		putstr_buff(s, ft_strlen(s), data);
}

static void	set_str_padding_spaces(t_data *data, char *s)
{
	int	len;
	int	temp;

	temp = 0;
	len = ft_strlen(s);
	if (data->format.width_value > 0)
	{
		if (data->format.precision_value >= 0)
		{
			if (data->format.precision >= len)
			{
				temp = data->format.width_value - len;
				data->format.padding_spaces = temp;
			}
			else
			{
				temp = data->format.width_value - data->format.precision_value;
				data->format.padding_spaces = temp;
			}
		}
	}
	else
	{
		data->format.padding_spaces = data->format.width_value - len;
	}
}
