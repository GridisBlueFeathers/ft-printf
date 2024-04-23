/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:24 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 14:22:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

ssize_t	ft_print_pointer_value(unsigned long n)
{
	ssize_t	bytes_written;
	ssize_t	res;
	char *base;

	base = "0123456789abcdef";
	res = 0;
	if (n < 16)
	{
		bytes_written = ft_print_char(base[n]);
		return (bytes_written);
	}
	bytes_written = ft_print_pointer_value(n / 16);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_pointer_value(n % 16);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}

int	ft_print_pointer_addr(void *p)
{
	ssize_t bytes_written;
	ssize_t	res;

	if (!p)
	{
		bytes_written = write(STDOUT_FILENO, "(nil)", 5);
		return (bytes_written);
	}
	res = 0;
	bytes_written = ft_print_string("0x");
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_pointer_value((unsigned long)p);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}

int	ft_format(va_list ap, char f)
{
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_string(va_arg(ap, char *)));
	if (f == 'p')
		return (ft_print_pointer_addr(va_arg(ap, void *)));
	return (-1);
}

int	ft_iterate_print(va_list ap, const char *fmt)
{
	size_t	len;
	size_t	i;
	ssize_t	bytes_written;

	i = 0;
	len = 0;
	while (fmt && fmt[i])
	{
		if (fmt[i + 1] && fmt[i] == '%')
		{
			bytes_written = ft_format(ap, fmt[i + 1]);
			i++;
		}
		else
			bytes_written = ft_print_char(fmt[i]);
		i++;
		if (bytes_written == -1)
			return (bytes_written);
		len += bytes_written;
	}
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	size_t	len;

	if (!fmt)
		return (-1);
	len = 0;
	va_start(ap, fmt);
	len = ft_iterate_print(ap, fmt);
	va_end(ap);
	return (len);
}
