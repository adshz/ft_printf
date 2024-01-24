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
	data->written_count += write(STDOUT_FILENO, data->buff, data->buffer_indx);
	ft_memset(data->buff, 0, BUFFER_SIZE);
	data->buffer_indx = 0;
}

void	write_buff(t_data *data, char c)
{
	if (data->buffer_indx == BUFFER_SIZE)
		flush_buff(data);
	data->buff[data->buffer_indx++] = c;
}

void	putchar_buff(char c, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision--)
		write_buff(data, c);
}

void	putstr_buff(char *s, int precision, t_data *data)
{
	if (precision <= 0)
		return ;
	while (precision-- && *s)
		write_buff(data, *s++);
}
