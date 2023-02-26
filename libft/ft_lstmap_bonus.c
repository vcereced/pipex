/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 23:09:45 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/15 20:41:09 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstmaped;

	lstmaped = 0;
	while (lst)
	{
		ft_lstadd_back(&lstmaped, ft_lstnew(f(lst ->content)));
		if (! lstmaped)
		{
			ft_lstclear(&lstmaped, del);
			return (0);
		}
		lst = lst -> next;
	}
	return (lstmaped);
}
