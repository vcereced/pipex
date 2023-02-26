/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:13:12 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/09 23:50:52 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)s + i);
	}
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

/*
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if ((char)c == '\0')
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
*/