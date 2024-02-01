/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:51:53 by szhong            #+#    #+#             */
/*   Updated: 2024/01/24 16:02:04 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define FLAGS "+ 0-#"
# define BUFFER_SIZE 4096
# define TRUE 1
# define FALSE 0
# define SPECIFIERS "cspudixX%"
# define UP_HEX "0123456789ABCDEF" 
# define LO_HEX "0123456789abcdef"

typedef union
{
	unsigned long	uint64;
	long int	int64;
}	union_int;

typedef enum
{
	SUCCESS = 1,
	MALLOC_FAIL = -1989,
	PARSE_ERROR = -2010,
	FORMAT_STRING_EMPTY = 0,
	INITIALIZATION_ERROR = -1
}	e_error;

typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16
}	e_base;

typedef struct s_format
{
	int	zero_pads;
	int	left_justified;
	int	plus;
	int	space;
	int	hash;
	int	width_value;
	int	precision_value;
	char	specifier;
	char	buf_tmp[64];
	int	nbrlen;
	e_base	base;
	int	upper;
	int	padding_spaces;
	int	padding_zeros;
	int	signed_value;
	int	is_negative;
	int	is_converted;
}	t_format;

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int	written_count;
	char	*buff;
	int	buffer_indx;
	t_format format;
}	t_data;

int	data_init(t_data *data, const char *fmt);
int	ft_printf(const char *fmt, ...);
int	parse_fmt(t_data *data);
void	flush_buff(t_data *data);
void	write_buff(t_data *data, char c);
void	putchar_buff(char c, int precision, t_data *data);
void	putstr_buff(char *s, int precision, t_data *data);
void	itoa_buff(t_data *data, union_int int_box);
void	print_char(t_data *data, int c);
void	render_fmt(t_data *data);
void	print_int(t_data *data, union_int int_box);
void	print_str(t_data *data, char *s);
int	in(const char *s, char c);
void	set_padding_zeros(t_data *data);
void	set_padding_spaces(t_data *data);
void	cal_precision_padding(t_data *data);
void	cal_width_padding(t_data *data);
void	adj_zero_special(t_data *data);
void	cal_padding_space(t_data *data);
void	adj_space_special(t_data *data);
void	handle_int_spec(t_data *data, char spec, union_int *ptr_intbox);
void	convert_digit(t_data *data, union_int int_box);
#endif
