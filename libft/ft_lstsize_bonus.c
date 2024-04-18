/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:30:05 by svereten          #+#    #+#             */
/*   Updated: 2024/04/05 17:55:56 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*cur;

	if (!lst)
		return (0);
	res = 1;
	cur = lst;
	while (cur->next)
	{
		cur = cur->next;
		res++;
	}
	return (res);
}
