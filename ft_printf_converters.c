/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:19:16 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/13 22:19:19 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_int(t_format *fmt)
{
	char	*str;

	str = ft_itoa(fmt->u_arg.i);
	return (str);
}

char	*ft_printf_uint(t_format *fmt)
{
	char	*str;

	str = ft_uitoa(fmt->u_arg.ui);
	return (str);
}

int	ft_printf_char(t_format *fmt)
{
	unsigned char	c;

	c = (unsigned char)fmt->u_arg.i;
	return (write(STDOUT_FILENO, &c, 1));
}

char	*ft_printf_str(t_format *fmt)
{
	char	*str;

	if (!fmt->u_arg.p)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	str = ft_strdup((const char *)fmt->u_arg.p);
	return (str);
}
