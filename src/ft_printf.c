/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:24 by svereten          #+#    #+#             */
/*   Updated: 2024/04/22 22:31:15 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_print_char(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
	return (1);
}

int ft_print_string(const char *s)
{
	size_t	len;

	if (!s)
	{
		ft_putstr_fd("(nil)", STDOUT_FILENO);
		return (5);
	}
	len = ft_strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}

int	ft_format(va_list ap, char f)
{
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_string(va_arg(ap, char *)));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	i;
	size_t	len;

	if (!fmt)
		return (-1);
	i = 0;
	len = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i + 1] && fmt[i] == '%')
		{
			len += ft_format(ap, fmt[i + 1]);
			i++;
		} 
		else
		{
			ft_putchar_fd(fmt[i], STDOUT_FILENO);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
