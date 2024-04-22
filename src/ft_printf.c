/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:24 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 01:06:11 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_calc_num_len_base(long long n, size_t base)
{
	int	res;

	res = 1;
	if (n < 0)
		res++;
	while (base && n / base)
	{
		res++;
		n /= base;
	}
	return (res);
}

void	ft_print_unsigned_num_base(unsigned long n, const char *base)
{
	size_t	base_len;

	if (!base)
		return ;
	base_len = ft_strlen(base);
	if (n < base_len)
	{
		ft_print_char(base[n]);
		return ;
	}
	ft_print_unsigned_num_base(n / base_len, base);
	ft_print_unsigned_num_base(n % base_len, base);
}

int	ft_print_pointer_addr(unsigned long p)
{
	ssize_t bytes_written;

	if (!p)
	{
		bytes_written = write(STDOUT_FILENO, "(nil)", 5);
		return (bytes_written);
	}
	ft_print_string("0x");
	ft_print_unsigned_num_base(p, "0123456789abcdef");
	return (ft_calc_num_len_base(p, 16) + 2);
}

int	ft_format(va_list ap, char f)
{
	if (f == 'c')
		return (ft_print_char(va_arg(ap, int)));
	if (f == 's')
		return (ft_print_string(va_arg(ap, char *)));
	if (f == 'p')
		return (ft_print_pointer_addr(va_arg(ap, unsigned long)));
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
