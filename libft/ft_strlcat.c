/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:05:49 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/09 23:47:40 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;
	size_t	len_dst;

	i = 0;
	n = 0;
	len_dst = ft_strlen(dst);
	if (len_dst < (dstsize -1) && dstsize > 0)
	{
		while (dst[i] != '\0')
			i++;
		while (src[n] != '\0' && i < (dstsize -1))
			dst[i++] = src[n++];
		dst[i] = '\0';
	}
	if (len_dst >= dstsize)
		len_dst = dstsize;
	return (len_dst + ft_strlen(src));
}
