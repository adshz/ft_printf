/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_undecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:33:31 by szhong            #+#    #+#             */
/*   Updated: 2024/01/19 17:17:27 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_unitoa(unsigned int num)
{
	char	*str_nbr;
	int		len;

	len = ft_digit_len(num);
	str_nbr = malloc((len + 1) * sizeof(char));
	if (!str_nbr)
		return (NULL);
	str_nbr[len--] = '\0';
	if (num == 0)
		str_nbr[0] = '0';
	while (num > 0)
	{
		str_nbr[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str_nbr);
}

int	ft_print_unsigned_decimal(unsigned int num)
{
	char	*nbr_s;
	int		count;

	count = 0;
	if (num == 0)
		count += write(1, "0", 1);
	else
	{
		nbr_s = ft_unitoa(num);
		count += ft_printstr(nbr_s);
		free(nbr_s);
	}
	return (count);
}
