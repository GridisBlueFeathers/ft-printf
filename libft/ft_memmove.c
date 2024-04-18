/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:11:51 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:31:29 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src && n)
		return (NULL);
	while (i < n)
	{
		if (dest < src)
			((char *)dest)[i] = ((char *)src)[i];
		else
			((char *)dest)[n - i - 1] = ((char *)src)[n - i - 1];
		i++;
	}
	return (dest);
}
