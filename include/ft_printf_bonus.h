/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:51:53 by szhong            #+#    #+#             */
/*   Updated: 2024/01/23 15:47:39 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 4096
# define TRUE 1;
# define FALSE 0;
# define SPECIFIERS "cspudixX%"

typedef struct s_data
{
	const char	*s;
	va_list		ap;
	int	written_count;
	char	*buff;
	int	buffer_indx;
	t_format format;
}	t_data;

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

typedef enum
{
	OK = 1;
	MALLOC_FAIL = -1989;
	PARSE_ERROR = -2010;
}	e_error;

typedef union
{
	unsinged long	uint64;
	long int	int64;
}	union_int;

#endif
