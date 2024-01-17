/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:41:53 by szhong            #+#    #+#             */
/*   Updated: 2024/01/15 18:42:50 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
//	char	*s = "%\nno goal no score%c, what this string? it is %s";
	char	*test = "\n I am a test!";
	void	*p;

	//ft_printf(s, '-', test);
	//printf("\n below is printf\n");
//	printf(s, test, '-');
	//printf(" \nprintf\n this is a pointer: %p", test);
	p = &test;
	int n = 1234;
//	ft_printf("\nft_printf\n this is a pointer:%p", p);
	printf("\nprintf\n this is a decimal number:%d\n", n);
	printf("\nprintf\n this is a pointer pointer:%p", p);
	printf("\nprintf\n this is a pointer test:%p", test);
	
}
