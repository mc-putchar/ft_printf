/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:54:46 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/08 17:24:42 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//TODO not needed as global, also need to separate its def and init
t_handler	converter[] = {print_char, print_str, print_addr, print_int, \
print_int, print_uint, print_hex, print_uphex};

static int	indexof(char c, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (c == s[i])
			return (i);
	return (-1);
}

static void	setflag(int fl, t_specs s)
{
	if (flag > -1)
		s->flags |= 1 << fl;
}

//TODO implement read of precision specifier
static t_specs	*parse_specs(char *fmt, int *i)
{
	t_specs	*specs;
	int		tmp;

	specs = malloc(sizeof(t_specs));
	if (!specs)
		return (NULL);
	specs->width = 0;
	while (fmt[++(*i)])
	{
		tmp = indexof(fmt[*i], FT_PRINTF_SPECIFIERS);
		if (tmp != -1)
		{
			specs->specifier = tmp;
			return (specs);
		}
		if (ft_isdigit(fmt[*i]) && fmt[*i] != '0')
			while (ft_isdigit(fmt[*i]))
				specs->width = (specs->width) * 10 + fmt[(*i)++] - '0';
		tmp = indexof(fmt[*i], FT_PRINTF_FLAGS);
		setflag(tmp, specs);
	}
	return (NULL);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	size_t	i;
	va_list	ap;
	t_specs	*specs;

	count = 0;
	va_start(ap, format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			specs = parse_specs(format, &i);
			if (specs)
				count += converter[specs->specifier](va_arg(ap, void *), specs);
		}
		else
		{
			ft_putchar_fd(format[i], STDOUT_FILENO);
			++count;
		}
	}
	va_end(ap);
	return (count);
}
