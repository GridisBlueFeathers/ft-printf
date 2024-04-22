/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:57 by svereten          #+#    #+#             */
/*   Updated: 2024/04/23 01:01:32 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int main()
{
	char *l = NULL;
	int ft_len = ft_printf("hey %p\n", l);
	int cl_len = printf("hey %p\n", l);
	printf("ft len is %d, cl len is %d\n", ft_len, cl_len);
	ft_len = ft_printf("%x\n", 100000);
	cl_len = printf("%x\n", 100000);
	printf("ft len is %d, cl len is %d\n", ft_len, cl_len);
}
