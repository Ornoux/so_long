/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:26:00 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/11 03:11:47 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_whattype(va_list arg, const char str)
{
	int	count;

	count = 0;
	if (str == 'c')
		count += ft_printchar(va_arg(arg, int));
	if (str == 's')
		count += ft_printstr(va_arg(arg, char *));
	if (str == 'd')
		count += ft_printnbr(va_arg(arg, int));
	if (str == 'i')
		count += ft_printnbr(va_arg(arg, int));
	if (str == 'u')
		count += ft_printunsnbr(va_arg(arg, int));
	if (str == 'x')
		count += ft_printhexlnbr(va_arg(arg, unsigned int));
	if (str == 'X')
		count += ft_printhexbnbr(va_arg(arg, unsigned int));
	if (str == 'p')
	{
		write(1, "0x", 2);
		count += ft_printhexlnbr(va_arg(arg, unsigned long long)) + 2;
	}
	else if (str == '%')
		count += ft_printchar('%');
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_whattype(arg, str[i + 1]);
			i++;
		}
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
