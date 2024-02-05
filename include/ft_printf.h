/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:04:07 by szhong            #+#    #+#             */
/*   Updated: 2024/02/05 19:53:57 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

typedef enum t_e_error
{
	FORMAT_STRING_EMPTY = 0,
}	t_e_rror;

typedef struct s_data
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_data;

t_data	data_init(void);
t_data	flag_left(t_data data);
t_data	flag_width(va_list ap, t_data data);
t_data	flag_digit(char c, t_data data);
int	flag_precision(const char *str, int pos, \
		va_list args, t_data *data);

/*------------PRINTF----------------------*/
int	ft_printf(const char *fmt, ...);
int	parse_fmt(char *dup, va_list ap);
int	parse_flags(const char *str, int i, va_list ap, t_data *data);
int	print_arg(char specifier, va_list ap, t_data data);
int	ft_printchar(char c);
int	print_char(char c, t_data data);
int	print_hex(unsigned int n, int is_upper, t_data data);
int	ft_print_hexadec(char *nbstr, int n, int is_upper, t_data data);
int	ft_print_x(char *nbstr, int n, int is_upper, t_data);
int	ft_print_x_prefix(int is_upper);
int	print_int(int n, t_data data);
int	ft_print_integer(char *nbstr, int n, t_data data);
int	ft_print_sign_precision(int n, t_data *data);
int	ft_print_i(char *nbstr, int n, t_data data);
int	ft_print_s(const char *str);
int	print_str(const char *str, t_data data);
int	print_precision(const char *str, int precision);
int	print_ptr(unsigned long int n, t_data data);
int	ft_print_p(unsigned long int n);
void	ft_print_adr(unsigned long int n);
int	ft_ptr_len(unsigned long int n);
int	ft_unint_len(unsigned int n);
int	ft_hex_len(unsigned int n);
int	print_unsigned(unsigned n, t_data data);
int	ft_print_unint(char *nbstr, t_data data);
int	ft_print_u(char *nbstr, t_data data);

/*------------HEPLER----------------------*/
char	*ft_printf_itoa(long nb);
char	*ft_printf_utoa(unsigned int nb);
char	*ft_printf_xtoa(unsigned long int nb, int is_upper);
int		ft_unint_len(unsigned int n);
int		ft_hex_len(unsigned int n);
int		ft_ptr_len(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);
int		ft_pad_width(int total_width, int size, int zero);
#endif
