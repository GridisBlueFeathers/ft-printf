/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:54:24 by svereten          #+#    #+#             */
/*   Updated: 2024/04/22 17:00:30 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
		if (0 && fmt[i + 1] && fmt[i] == '%')
		{

			printf("hey\n");

		} 
		else
		{
			ft_putchar_fd(fmt[i], STDOUT_FILENO);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (0);
}
