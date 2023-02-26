/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 22:24:38 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/15 00:15:11 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer;

	while (*lst)
	{
		buffer = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = buffer;
	}
	(*lst) = NULL;
}	
