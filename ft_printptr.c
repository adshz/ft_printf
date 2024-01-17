/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:33:57 by szhong            #+#    #+#             */
/*   Updated: 2024/01/16 15:50:19 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putptr(uintptr_t ptr);
int	ft_digit_len(uintptr_t num);

int	ft_printptr(unsigned long long ptr)
{
	int	count;

	count = 0;
	count = write(1, "0x", 2);
	if (ptr == 0)
	{
		count = write(1, "0", 1);
	}
	else
	{
		ft_putstr(ptr);
		count += ft_digit_len(ptr);
	}
	return (count);
}

void ft_putptr(uintptr_t ptr)
{
	if (ptr > 15)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr > 9)
		{
			ft_putchar((ptr - 10 + 'a'), 1);
		}
		else
			ft_putchar((ptr + '0'), 1);
	}
}

int	ft_digit_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}
