/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:22:17 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:54:29 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			res = &((char *)s)[i];
		i++;
	}
	if (!s[i] && !(unsigned char)c)
		res = &((char *)s)[i];
	return (res);
}
