/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svereten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:34:23 by svereten          #+#    #+#             */
/*   Updated: 2024/04/12 12:22:43 by svereten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_list	*ft_get_next(t_list *l, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*next;

	content = f(l->content);
	if (!content)
		return (NULL);
	next = ft_lstnew(content);
	if (!next)
	{
		del(content);
		return (NULL);
	}
	return (next);
}

static t_list	*ft_lstappend(t_list *last, t_list *next)
{
	if (!last)
		last = next;
	else
	{
		last->next = next;
		last = next;
	}
	return (last);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*next;
	t_list	*last;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	last = NULL;
	while (lst)
	{
		next = ft_get_next(lst, f, del);
		if (!next)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		if (!res)
			res = next;
		last = ft_lstappend(last, next);
		lst = lst->next;
	}
	return (res);
}
