/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:49:57 by svereten          #+#    #+#             */
/*   Updated: 2024/04/22 23:45:34 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int main()
{
	char *l = NULL;
	int i = ft_printf("%s%s\n", "hey HEY", "yo");
	printf("%d\n", i);
	i = ft_printf("%s\n", l);
	printf("%d\n", i);
	i = printf("%s%s\n", "hey HEY", "yo");
	printf("%d\n", i);
	i = printf("%s\n", l);
	printf("%d\n", i);
}
