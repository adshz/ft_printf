/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:05:26 by szhong            #+#    #+#             */
/*   Updated: 2024/01/23 16:10:07 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.c"

void	flush_buff(t_data *data)
{
	data->written_count += write(STDOUT_FILENO, data->buff, data->buff_indx);
	ft_memset(data->buff, 0, BUFFER_SIZE);
	data->buff_indx = 0;
}

void	write_buff(t_data *data, char c)
{
	if (data->buff_indx == BUFFER_SIZE)
		flush_buff(data);
	data->buf[data->buff_indx++] = c;
}

void	putchar_buf(char c, int precision, t_data *data)
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
