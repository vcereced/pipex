/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:34:01 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/13 20:18:29 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*substr;	

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (len > (len_s - start))
	{
		substr = (char *)malloc((len_s - start) + 1);
		len = len_s - start;
	}
	else
		substr = (char *)malloc(len + 1);
	if (substr)
	{
		ft_strlcpy(substr, &s[start], len + 1);
	}
	else
		return (NULL);
	return (substr);
}
