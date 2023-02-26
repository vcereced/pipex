/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:30:22 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/09 00:29:30 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	str = (char *)malloc(len_s1 + 1);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s1, len_s1);
	str[len_s1] = '\0';
	return (str);
}
