/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:50:48 by svereten          #+#    #+#             */
/*   Updated: 2024/04/22 23:29:12 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(char c)
{
	ssize_t	bytes_written;

	bytes_written = write(STDOUT_FILENO, &c, 1);
	return (bytes_written);
}
