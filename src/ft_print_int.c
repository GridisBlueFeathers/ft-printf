/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:48:13 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 15:48:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_print_int_worker(int n, int mod)
{
	ssize_t	bytes_written;
	ssize_t	res;

	res = 0;
	if ((mod == -1 && n > -10) || (mod == 1 && n < 10))
	{
		bytes_written = ft_print_char((n * mod) + '0');
		return (bytes_written);
	}
	bytes_written = ft_print_int_worker(n / 10, mod);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	bytes_written = ft_print_int_worker(n % 10, mod);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}

int	ft_print_int(int n)
{
	ssize_t	res;
	ssize_t	bytes_written;
	int		mod;

	mod = 1;
	res = 0;
	if (n < 0)
	{
		bytes_written = ft_print_char('-');
		if (bytes_written == -1)
			return (bytes_written);
		mod = -1;
		res += bytes_written;
	}
	bytes_written = ft_print_int_worker(n, mod);
	if (bytes_written == -1)
		return (bytes_written);
	res += bytes_written;
	return (res);
}
