/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:54:46 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/09 00:55:54 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_flags(const char *fmt, int *i)
{
	int	flags;
	int	j;

	flags = 0;
	j = 0;
	while (fmt[*i] && j != -1)
	{
		j = indexof(fmt[*i], FT_PRINTF_FLAGS);
		if (j == -1)
			break ;
		flags |= 1 << j;
		++(*i);
	}
	return (flags);
}

/*
**	This function parses the format string, moving the index along
**	to the specifier at the end.
**	Returns the struct for the required format of next argument.
**	Use free() to deallocate the struct.
**	Format: %[flags][width][.precision]type
**	[size] not implemented
*/
static t_format	*parse_format(const char *fmt, int *i)
{
	t_format	*f;
	int			j;

	f = malloc(sizeof(t_format));
	if (!f)
		return (NULL);
	if (fmt[*i])
	{
		f->flags = parse_flags(fmt, i);
		if (ft_isdigit(fmt[*i]))
			f->width = get_min_width(fmt, i);
		if (fmt[*i] == '.')
			f->precision = get_precision(fmt, i);
		j = indexof(fmt[*i], FT_PRINTF_SPECIFIERS);
		if (j != -1)
			return (f->specifier = j, f);
	}
	return (NULL);
}

int	ft_printf_format(t_format *f, va_list ap)
{
	static t_converter	con[PRINTF_CONVERTERS] = {&ft_printf_int, \
	&ft_printf_int, &ft_printf_uint, &ft_printf_hex, &ft_printf_uhex, \
	&ft_printf_str, &ft_printf_ptr};
	int					c;

	if (!f || !ap)
		return (0);
	if (!(f->specifier))
		return (write(STDOUT_FILENO, &"%", 1));
	if (f->specifier > 6)
		f->u_arg.p = va_arg(ap, void *);
	else if (f->specifier > 3)
		f->u_arg.ui = (unsigned int)va_arg(ap, unsigned int);
	else
		f->u_arg.i = va_arg(ap, int);
	if (f->specifier == 1)
		return (ft_printf_char(f));
	f->out = con[f->specifier - 2](f);
	if (!f->out)
		return (0);
	ft_printf_handle_flags(f);
	c = ft_print(f->out, 0, ft_strlen(f->out));
	free(f->out);
	return (c);
}

int	ft_printf(const char *format, ...)
{
	int			c;
	int			s;
	int			i;
	va_list		ap;
	t_format	*f;

	c = 0;
	i = -1;
	s = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (i++ > s)
				c += ft_print(format, s, i - 1);
			f = parse_format(format, &i);
			c += ft_printf_format(f, ap);
			free(f);
			s = i + 1;
		}
	}
	if (i > s)
		c += ft_print(format, s, i);
	return (va_end(ap), c);
}
