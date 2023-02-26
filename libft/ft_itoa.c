/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:09:37 by vcereced          #+#    #+#             */
/*   Updated: 2022/12/13 21:53:53 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long	len_int(long n)
{
	long	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 0)
	{
		if (n >= 0 && n <= 9)
			return (++i);
		else
		{
			n = n / 10;
			i++;
		}
	}	
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len_n;
	long	ln;

	ln = (long)n;
	len_n = len_int(ln);
	if (ln < 0)
		ln *= -1;
	str = (char *)malloc(len_n + 1);
	if (str)
	{
		str[len_n] = '\0';
		while (len_n > 0)
		{
			str[len_n-- -1] = ln % 10 + '0';
			ln = ln / 10;
		}
	}
	else
		return (NULL);
	if (n < 0)
			str[len_n] = '-';
	return (str);
}
