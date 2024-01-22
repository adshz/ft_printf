/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:04:07 by szhong            #+#    #+#             */
/*   Updated: 2024/01/19 17:10:14 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int	ft_printchar(char c);
int	ft_fmt(const char specifier, va_list ap);
int	ft_printf(const char *fmt, ...);
int	ft_hext_len(int num);
void	ft_puthex(int num, const char specifier);
int	ft_printhex(int num, const char specifier);
char	*ft_unitoa(unsigned int num);
int	ft_print_unsigned_decimal(unsigned int num);
int	ft_putstr(char *str);
int	ft_printstr(char *str);
int	ft_printnbr(int n);
void	ft_putptr(uintptr_t ptr);
int	ft_printptr(unsigned long long ptr);
void	ft_putptr(uintptr_t ptr);
int	ft_printf(const char *fmt, ...);
#endif
