/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:24:18 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:27:59 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*res;

	i = 0;
	while (i < n && ((unsigned char *)s)[i] != (unsigned char)c)
		i++;
	if (i == n)
		return (NULL);
	res = &((unsigned char *)s)[i];
	return (res);
}
