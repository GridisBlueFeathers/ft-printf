/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:55:15 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:52:49 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && n)
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			|| !s1[i] || !s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	if (i > 0 && i == n)
		return (((unsigned char *)s1)[i - 1] - ((unsigned char *)s2)[i - 1]);
	return (0);
}
