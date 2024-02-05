/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:48:04 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 17:15:31 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_char(char c, t_data data)
{
	int	count;

	count = 0;
	if (data.left == 1)
		count += ft_printchar(c);
	count += ft_pad_width(data.width, 1, data.zero);
	if (data.left == 0)
		count += ft_printchar(c);
	return (count);
}

