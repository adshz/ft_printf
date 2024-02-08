/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:02:46 by szhong            #+#    #+#             */
/*   Updated: 2024/01/31 18:45:24 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	data_init(t_data *data, const char *fmt)
{
	char	*buffer;

	if (!fmt || *fmt == '\0')
		return (FORMAT_STRING_EMPTY);
	data->s = fmt;
	data->written_count = 0;
	buffer = (char *)ft_calloc(BUFFER_SIZE, sizeof(char));
	if (buffer == NULL)
		return (MALLOC_FAIL);
	data->buff = buffer;
	data->buffer_indx = 0;
	return (SUCCESS);
}

int	ft_printf(const char *fmt, ...)
{
	t_data	data;

	if (data_init(&data, fmt) != SUCCESS)
		return (INITIALIZATION_ERROR);
	va_start(data.ap, fmt);
	while (*data.s)
	{
		if (*data.s == '%' && *++data.s)
		{
			if (parse_fmt(&data) != SUCCESS)
				return (PARSE_ERROR);
			render_fmt(&data);
		}
		else
			write_buff(&data, *data.s);
		++data.s;
	}
	flush_buff(&data);
	va_end(data.ap);
	free(data.buff);
	return (data.written_count);
}
