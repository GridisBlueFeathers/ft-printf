/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:02:46 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:47:45 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_appendstr(char *res, char const *s, int start)
{
	int	j;

	j = start;
	while (s[j - start])
	{
		res[j] = s[j - start];
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;
	size_t	s1_len;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	len = s1_len + ft_strlen(s2);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	ft_appendstr(res, s1, 0);
	ft_appendstr(res, s2, s1_len);
	return (res);
}
