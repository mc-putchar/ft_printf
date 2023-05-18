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

char	*zero_padding(t_format *f, int len)
{
	char	*str;
	char	*tmp;
	char	*pad;

	pad = gen_padding('0', len);
	if (!pad)
		return (NULL);
	if (f->out[0] == '-')
	{
		tmp = ft_strjoin("-", pad);
		if (!tmp)
			return (free(pad), NULL);
		str = ft_strjoin(tmp, f->out + 1);
		return (free(pad), free(tmp), str);
	}
	str = ft_strjoin(pad, f->out);
	return (free(pad), str);
}

int	ft_printf_handle_flags(t_format *f)
{
	char	*tmp;
	char	*str;

	str = NULL;
	tmp = NULL;
	if (f->width <= (int)ft_strlen(f->out))
		return (ft_print(f->out, 0, ft_strlen(f->out)));
	if (f->flags & 1)
	{
		tmp = gen_padding(' ', f->width - ft_strlen(f->out));
		str = ft_strjoin(f->out, tmp);
	}
	else if (f->flags & (1 << 1) && f->prec < 0 && f->specifier < 7)
		str = zero_padding(f, f->width - ft_strlen(f->out));
	else
	{
		tmp = gen_padding(' ', f->width - ft_strlen(f->out));
		str = ft_strjoin(tmp, f->out);
	}
	if (tmp)
		free(tmp);
	free(f->out);
	f->out = str;
	return (ft_print(f->out, 0, ft_strlen(f->out)));
}

int	ft_printf_char_flags(t_format *f)
{
	char	*pad;
	int		c;

	if (f->width < 2)
		return (write(STDOUT_FILENO, &(f->out[0]), 1));
	c = 0;
	pad = gen_padding(' ', f->width - 1);
	if (!pad)
		return (0);
	if (f->flags & 1)
	{
		c += write(STDOUT_FILENO, &(f->out[0]), 1);
		c += write(STDOUT_FILENO, pad, f->width - 1);
	}
	else
	{
		c += write(STDOUT_FILENO, pad, f->width - 1);
		c += write(STDOUT_FILENO, &(f->out[0]), 1);
	}
	return (free(pad), c);
}
