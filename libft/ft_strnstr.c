/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:11:29 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/13 22:05:28 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_needle;

	i = 0;
	len_needle = ft_strlen(needle);
	if (len_needle > len && haystack != NULL)
		return (NULL);
	if (!*needle)
		return (((char *)haystack));
	while (haystack[i] != '\0' && i <= (len - len_needle) && len != 0)
	{
		if ((ft_strncmp(&haystack[i], needle, len_needle) == 0))
			return (((char *)&haystack[i]));
		i++;
	}
	return (NULL);
}
