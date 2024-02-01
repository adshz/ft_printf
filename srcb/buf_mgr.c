/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_mgr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:26 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 15:55:10 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	flush_buff(t_data *data)
{
	int	bytes_written;

	bytes_written = write(STDOUT_FILENO, data->buff, data->buffer_indx);
	data->written_count += bytes_written
	ft_memset(data->buff, 0, BUFFER_SIZE);
	data->buffer_indx = 0;
}

void	write_buff(t_data *data, char c)
{
	if (data->buffer_indx == BUFFER_SIZE)
		flush_buff(data);
	data->buff[data->buffer_indx] = c;
	data->buffer_indx++;s
}

void	putchar_buff(char c, int precision, t_data *data)
{
	int	count;

	if (precision <= 0)
		return ;
	count = precision;
	while (count > 0)
	{
		write_buff(data, c);
		count--;
	}
}

void	putstr_buff(char *s, int precision, t_data *data)
{
	int	count;

	if (precision <= 0 || s == NULL)
		return ;
	count = precision;
	while (count > 0 && *s)
	{
		write_buff(data, *s);
		s++;
		count--;
	}
}
