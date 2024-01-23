/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:58:13 by szhong            #+#    #+#             */
/*   Updated: 2024/01/23 14:53:17 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

void	render_format(t_data *data, char specifier)
{
	union_int	int_box;

	if (specifier == '%')
		print_char(data, '%');
	else if (specifier == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		print_str(data, va_arg(data->ap, char *));
	int_box.int64 = 0;
	if (in("dipxXub", specifier))
	{
		if (in("di", specifier))
		{
			int_box.int64 = (long)va_arg(data->ap, int);
			data->format.signed_value = TRUE;
			if (int_box.int64 < 0)
				data->format.is_negative = TRUE;
		}
		else if (specifier == 'p')
			int_box.uint64 = (unsigned long)va_arg(data->ap, void *);
		else if (in("xXub", specifier))
			int_box.uint64 = (unsigned long)va_arg(data->ap, unsigned int);
		print_int(data, int_box);
	}
}
