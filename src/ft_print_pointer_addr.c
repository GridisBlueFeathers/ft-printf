/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_addr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:23:32 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 14:24:02 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static ssize_t	ft_print_pointer_value(unsigned long n)
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
