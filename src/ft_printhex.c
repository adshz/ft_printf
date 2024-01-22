/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:33:51 by szhong            #+#    #+#             */
/*   Updated: 2024/01/19 15:20:56 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libft.h"

int	ft_hex_len(int	num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_puthex(int	num, const char specifier)
{
	if (num > 15)
	{
		ft_puthex(num / 16, specifier);
		ft_puthex(num % 16, specifier);
	}
	else
	{
		if (num < 10)
		{
			write(1, "0", 1);
		}
		else
		{
			num -= 10;
			if (specifier == 'X')
				ft_putchar_fd((num + 'A'), 1);
			else if (specifier == 'x')
				ft_putchar_fd((num + 'a'), 1);
		}
	}
}

int	ft_printhex(int num, const char specifier)
{
	int	count;

	count = 0;
	if (num == 0)
		count += write(1, "0", 1);
	else
	{
		ft_puthex(num, specifier);
		count = ft_hex_len(num);
	}
	return (count);

}
