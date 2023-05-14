/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcutura <mcutura@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:21:50 by mcutura           #+#    #+#             */
/*   Updated: 2023/05/13 22:21:52 by mcutura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print(const char *str, int s, int e)
{
	return (write(STDOUT_FILENO, str + s, e - s));
}

int	indexof(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_min_width(const char *fmt, int *i)
{
	int	width;

	width = 0;
	while (ft_isdigit(fmt[*i]))
		width = width * 10 + fmt[(*i)++] + '0';
	return (width);
}

int	get_precision(const char *fmt, int *i)
{
	int	precision;

	precision = -1;
	while (ft_isdigit(fmt[++(*i)]))
		precision = precision * 10 + fmt[*i] + '0';
	return (precision);
}
