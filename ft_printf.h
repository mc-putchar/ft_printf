/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 01:41:02 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/08 17:23:53 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# define FT_PRINTF_SPECIFIERS "%cspdiuxX"
# define FT_PRINTF_FLAGS "0-# +"

/* Flags bits 
[position] value
[0]	padded;	[1]	rjustified;	[2]	altform;	[3]	fblank;	[4]	fsign;
*/
typedef struct s_specs
{
	int	width;
	int	precision;
	int	specifier;
	int	flags;
}		t_specs;

typedef int	(*t_handler)();

int	ft_printf(const char *format, ...);

int	print_char(int c, t_specs sp);
int	print_str(char *s, t_specs sp);
int	print_addr(void *p, t_specs sp);
int	print_int(int i, t_specs sp);
int	print_uint(unsigned int u, t_specs sp);
int	print_hex(int i, t_specs sp);
int	print_uphex(int i, t_specs sp);

#endif
