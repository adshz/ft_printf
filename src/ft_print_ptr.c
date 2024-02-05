/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:37:42 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 18:46:19 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long int n, t_data data)
{
	int	count;

	count = 0;
	if (n == 0)
		data.width -= ft_strlen("(nil)") - 1;
	else
		data.width -= 2;
	if (data.left == 1)
		count += ft_print_p(n);
	count += ft_pad_width(data.width, ft_ptr_len(n), 0);
	if (data.left == 0)
		count += ft_print_p(n);
	return (count);
}

int	ft_print_p(unsigned long int n)
{
	int	count;

	count == 0;
	if (n == 0)
	{
		count += ft_print_s("(nill)");
		return (count);
	}
	count += ft_print_s("0x");
	ft_print_adr(n);
	count += ft_ptr_len(n);
	return (count);
}

void	ft_print_adr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
	{
		if (n < 10)
			print_char(n + '0');
		else if (n >= 10)
			print_char((n - 10) + 'a');
	}
}
