/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:12:04 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/10 18:01:26 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str_trimed;
	size_t	len;

	len = ft_strlen(s1);
	while (s1[0] != '\0' && ft_strchr(set, s1[0]))
		s1++;
	len = ft_strlen(s1);
	while (s1[0] != '\0' && ft_strrchr(set, s1[len - 1]))
		len--;
	str_trimed = ft_substr(s1, 0, len);
	return (str_trimed);
}
