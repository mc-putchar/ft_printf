/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 03:59:44 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/14 03:59:46 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prefix(char *str, char *prefix)
{}

void	ft_printf_handle_flags(t_format *f)
{
	char	*tmp;
	if (f->flags & (1 << 2) && (f->specifier == 5 || f->specifier == 6))
		;// prepend 0x or 0X
	if (f->flags & (1 << 4))
		;// prepend sign
	else if (f->flags & (1 << 3))
		;// prepend space
}
