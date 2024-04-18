/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:26:32 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:58:36 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	new_len;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		new_len = 0;
	else if (len > s_len - start)
		new_len = s_len - start;
	else
		new_len = len;
	res = (char *)ft_calloc(new_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = start;
	while ((i < len + start) && s[i] && start < s_len)
	{
		res[i - start] = s[i];
		i++;
	}
	return (res);
}
