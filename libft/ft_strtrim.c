/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:17:48 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:56:04 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_isinset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(set) && c != set[i])
		i++;
	if (!set[i])
		return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_isinset(set, s1[i]))
		i++;
	start = i;
	while (s1[i])
	{
		if (!ft_isinset(set, s1[i]))
			end = i;
		i++;
	}
	return (ft_substr(s1, start, end - start + 1));
}
