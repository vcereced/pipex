/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 01:05:02 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/13 20:23:52 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	char	*str;

	len_s = ft_strlen(s);
	str = (char *)malloc(len_s + 1);
	if (!str)
		return (NULL);
	str[len_s] = '\0';
	while (len_s-- > 0)
		str[len_s] = f(len_s, s[len_s]);
	return (str);
}
