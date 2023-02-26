/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:23:01 by vcereced          #+#    #+#             */
/*   Updated: 2023/01/13 20:20:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str_jointed;

	str_jointed = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str_jointed)
	{
		i = 0;
		j = 0;
		while (s1[i] != '\0')
		{
			((unsigned char *)str_jointed)[i] = ((unsigned char *)s1)[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			((unsigned char *)str_jointed)[i + j] = ((unsigned char *)s2)[j];
			j++;
		}
		((unsigned char *)str_jointed)[i + j] = '\0';
		return (str_jointed);
	}
	else
		return (NULL);
}
