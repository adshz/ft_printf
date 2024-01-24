/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:02:46 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 15:53:38 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

int	data_init(t_data *data, const char *fmt)
{
	if (!fmt || *fmt == '\0')
	       return (0);
	data->s = fmt;
	data->written_count = 0;
	data->buff = malloc(BUFFER_SIZE *sizeof(char));
	if (data->buff == NULL)
		return (MALLOC_FAIL);
	data->buffer_indx = 0;
	ft_memset(data->buff, 0, BUFFER_SIZE * sizeof(char));
	return (OK);
	
}

int	ft_printf(const char *fmt, ...)
{
	t_data	data;

	if (data_init(&data, fmt) != OK)
		return (-1);
	va_start(data.ap, fmt);
	while (*data.s)
	{
		if (*data.s == '%' && *++data.s)
		{
			
			if (parse_fmt(&data) != OK)
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
