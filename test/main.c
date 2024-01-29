/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:46:38 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 14:01:26 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	test_c(char c)
{
	int	x;
	int	y;
	int	z;

	printf("\n--------------TEST: Character-----------------\n");
	x = printf("printf: %c\n", c);
	y = ft_printf("ft_printf: %c\n", c);
	
	printf("printf - return bytes : %d\n", x);
	printf("ft_printf - return bytes: %d\n", y);
}

void	test_s(char *s)
{
	int	x;
	int	y;
	int	z;
	
	z = printf("\n--------------TEST: String-----------------\n");
	
	printf("\nprintf:\n");
	x = printf("%s", s);
	printf("\nft_printf:\n");
	y = ft_printf("%s", s);

	printf("printf - return bytes : %d\n", x);
	printf("ft_printf - return bytes: %d\n", y);
	
}

int	main()
{
	//test_c('\n');
	test_s("Hello world!");
}
