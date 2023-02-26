/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:50:49 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/07 18:11:21 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_printf(char c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

static void	recursiva_long(long nbr, long size, char *base, int *length)
{
	if (nbr >= size)
	{
		recursiva_long((nbr / size), size, base, length);
		ft_putchar_printf(base[nbr % size], length);
	}
	else
		ft_putchar_printf(base[nbr % size], length);
}

static void	recursiva_unsig_int(unsigned int n, unsigned int size, \
char *base, int *len)
{
	if (n >= size)
	{
		recursiva_unsig_int((n / size), size, base, len);
		ft_putchar_printf(base[n % size], len);
	}
	else
		ft_putchar_printf(base[n % size], len);
}

static void	recursiva_unsig_long(size_t n, size_t siz, char *bas, int *len)
{
	if (n >= siz)
	{
		recursiva_unsig_long((n / siz), siz, bas, len);
		ft_putchar_printf(bas[n % siz], len);
	}
	else
		ft_putchar_printf(bas[n % siz], len);
}

void	ft_putnbr_printf(long nbrl, char *base, int *len, char ptr)
{
	long	size;

	size = 0;
	if (ptr == 'p' || ptr == 'x')
		base = "0123456789abcdef";
	while (base[size] != '\0')
		size++;
	if (ptr == 'd' || ptr == 'i' )
	{
		if (nbrl < 0)
		{
			ft_putchar_printf('-', len);
			nbrl = nbrl * -1;
		}
	}
	if (ptr == 'p')
	{
		ft_putchar_printf('0', len);
		ft_putchar_printf('x', len);
		recursiva_unsig_long(nbrl, size, base, len);
	}
	else if (ptr == 'd' || ptr == 'i')
		recursiva_long(nbrl, size, base, len);
	else if (ptr != 'p')
		recursiva_unsig_int(nbrl, size, base, len);
}
