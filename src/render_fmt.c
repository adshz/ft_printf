/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:58:13 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 15:50:05 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	render_fmt(t_data *data)
{
	t_union_int	int_box;
	char		spec;

	spec = data->format.specifier;
	if (spec == '%')
		print_char(data, '%');
	else if (spec == 'c')
		print_char(data, va_arg(data->ap, int));
	else if (spec == 's')
		print_str(data, va_arg(data->ap, char *));
	int_box.int64 = 0;
	if (in("dipxXub", spec))
	{
		handle_int_spec(data, spec, &int_box);
		print_int(data, int_box);
	}
}

void	handle_int_spec(t_data *data, char spec, t_union_int *ptr_intbox)
{
	if (in("di", spec))
	{
		ptr_intbox->int64 = (long)va_arg(data->ap, int);
		data->format.signed_value = TRUE;
		if (ptr_intbox->int64 < 0)
			data->format.is_negative = TRUE;
	}
	else if (spec == 'p')
		ptr_intbox->uint64 = (unsigned long)va_arg(data->ap, void *);
	else if (in("xXub", spec))
		ptr_intbox->uint64 = (unsigned long)va_arg(data->ap, unsigned int);
	return ;
}
