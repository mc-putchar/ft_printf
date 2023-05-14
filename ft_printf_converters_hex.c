/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_converters_hex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:22:53 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/13 23:22:55 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_udigits(unsigned long long n)
{
	int	d;

	d = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 16;
		++d;
	}
	return (d);
}

static char	*convert_to_hex(unsigned long long n, int off)
{
	char	*hex;
	int		i;

	i = count_udigits(n);
	hex = malloc(i + 1);
	if (!hex)
		return (hex);
	if (!n)
		hex[0] = '0';
	hex[i] = 0;
	while (n && i--)
	{
		hex[i] = (n % 16) + '0';
		if (hex[i] > '9')
			hex[i] += off;
		n /= 16;
	}
	return (hex);
}

char	*ft_printf_ptr(t_format *fmt)
{
	char	*str;
	char	*addr;

	if (!fmt->u_arg.p)
	{
		str = ft_strdup("(nil)");
		return (str);
	}
	str = convert_to_hex((unsigned long long)fmt->u_arg.p, HEX_OFF_TO_LOWER);
	if (!str)
		return (str);
	addr = malloc(ft_strlen(str) + 3);
	if (!addr)
		return (free(str), addr);
	addr[0] = '0';
	addr[1] = 'x';
	addr[2] = 0;
	ft_strlcat(addr, str, ft_strlen(str) + 3);
	free(str);
	return (addr);
}

char	*ft_printf_hex(t_format *fmt)
{
	char	*str;

	str = convert_to_hex(fmt->u_arg.ui, HEX_OFF_TO_LOWER);
	return (str);
}

char	*ft_printf_uhex(t_format *fmt)
{
	char	*str;

	str = convert_to_hex(fmt->u_arg.ui, HEX_OFF_TO_UPPER);
	return (str);
}
