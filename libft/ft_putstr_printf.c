/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:32:47 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/07 18:11:43 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_printf(char c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

void	ft_putstr_printf(char *s, int *length)
{
	size_t	i;

	i = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		*length += 6;
	}
	else
	{
		while (s[i] != '\0')
		{
			ft_putchar_printf(s[i], length);
			i++;
		}
	}
}
