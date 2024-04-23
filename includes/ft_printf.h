/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:46:03 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 14:24:17 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);

int		ft_print_char(char c);
int		ft_print_string(const char *s);
int		ft_print_pointer_addr(void *p);

int		ft_printf(const char *fmt, ...);

#endif
