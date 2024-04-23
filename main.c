/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:57 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 14:21:48 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int main()
{
	char *l = NULL;
	char *w = "hey HEY";
	int ft_len = ft_printf("l %p\n", l);
	int cl_len = printf("l %p\n", l);
	printf("ft len is %d, cl len is %d\n", ft_len, cl_len);
	ft_len = ft_printf("w %p\n", w);
	cl_len = printf("w %p\n", w);
	printf("ft len is %d, cl len is %d\n", ft_len, cl_len);
	ft_len = ft_printf("%x\n", 100000);
	cl_len = printf("%x\n", 100000);
	printf("ft len is %d, cl len is %d\n", ft_len, cl_len);
}
