/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:02 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/08 22:44:31 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define FT_PRINTF_SPECIFIERS "%cdiuxXsp"
# define FT_PRINTF_FLAGS "-0# +"
# define PRINTF_CONVERTERS 8
# define HEX_OFF_TO_LOWER 39
# define HEX_OFF_TO_UPPER 7

/* 
** Flags bits:
** [0] left align(-); [1] zero padded(0); [2] alternate form(#);
** [3] prefix blank( ); [4] prefix sign(+);
*/
typedef struct s_format
{
	int		width;
	int		precision;
	int		specifier;
	int		flags;
	union
	{
		int				i;
		unsigned int	ui;
		void			*p;
	}		u_arg;
	char	*out;
}		t_format;

typedef char	*(*t_converter)(struct s_format *);

int		ft_printf(const char *format, ...);
int		ft_printf_char(t_format *fmt);
char	*ft_printf_int(t_format *fmt);
char	*ft_printf_uint(t_format *fmt);
char	*ft_printf_str(t_format *fmt);
char	*ft_printf_ptr(t_format *fmt);
char	*ft_printf_hex(t_format *fmt);
char	*ft_printf_uhex(t_format *fmt);

int		ft_print(const char *str, int s, int e);
int		indexof(char c, char *str);
int		get_min_width(const char *fmt, int *i);
int		get_precision(const char *fmt, int *i);

#endif
