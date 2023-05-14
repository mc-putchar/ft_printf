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

static char	*to_hex(unsigned long long n, int off)
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

	if (!fmt->u_arg.p)
	{
		str = ft_strdup("(nil)");
		return (str);
	}
	str = to_hex((unsigned long long)fmt->u_arg.p, HEX_OFF_TO_LOWER);
	if (!str)
		return (str);
	fmt->out = ft_strjoin("0x", str);
	free(str);
	return (fmt->out);
}

char	*ft_printf_hex(t_format *fmt)
{
	char	*str;
	char	*pad;
	char	*tmp;
	int		len;

	fmt->out = to_hex(fmt->u_arg.ui, HEX_OFF_TO_LOWER);
	if (!fmt->out)
		return (NULL);
	len = fmt->prec - ft_strlen(fmt->out);
	if (len > 0)
	{
		pad = gen_padding('0', len);
		tmp = zero_padding(pad, fmt);
		free(fmt->out);
		free(pad);
		fmt->out = tmp;
	}
	if (fmt->flags & (1 << 2) && fmt->u_arg.ui)
	{
		str = ft_strjoin("0x", fmt->out);
		return (free(fmt->out), fmt->out = str);
	}
	return (fmt->out);
}

char	*ft_printf_uhex(t_format *fmt)
{
	char	*str;
	char	*pad;
	char	*tmp;
	int		len;

	fmt->out = to_hex(fmt->u_arg.ui, HEX_OFF_TO_UPPER);
	if (!fmt->out)
		return (NULL);
	len = fmt->prec - ft_strlen(fmt->out);
	if (len > 0)
	{
		pad = gen_padding('0', len);
		tmp = zero_padding(pad, fmt);
		free(fmt->out);
		free(pad);
		fmt->out = tmp;
	}
	if (fmt->flags & (1 << 2) && fmt->u_arg.ui)
	{
		str = ft_strjoin("0X", fmt->out);
		return (free(fmt->out), fmt->out = str);
	}
	return (fmt->out);
}
