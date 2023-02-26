/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 21:24:53 by vcereced          #+#    #+#             */
/*   Updated: 2023/02/07 18:18:34 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_printf(char c, int *length)
{
	write(1, &c, 1);
	*length += 1;
}

void	ft_condition_printf( va_list args, char fmt, int *len)
{
	if (fmt == 'c')
		ft_putchar_printf(va_arg(args, int), len);
	else if (fmt == 's')
		ft_putstr_printf(va_arg(args, char *), len);
	else if (fmt == 'd' || fmt == 'i' || fmt == 'u')
		ft_putnbr_printf(va_arg(args, int), "0123456789", len, fmt);
	else if (fmt == 'x' || fmt == 'X' || fmt == 'p')
		ft_putnbr_printf(va_arg(args, long), "0123456789ABCDEF", len, fmt);
	else if (fmt == '%')
		ft_putchar_printf('%', len);
}

int	ft_printf(char const *fmt, ...)
{
	va_list	args;
	int		len;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, fmt);
	len = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			ft_condition_printf(args, *fmt, &len);
		}
		else
			ft_putchar_printf(*fmt, &len);
		fmt++;
	}
	va_end(args);
	return (len);
}
