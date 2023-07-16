/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:57:53 by npatron           #+#    #+#             */
/*   Updated: 2023/04/18 12:10:58 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printhexlnbr(unsigned long long nb)
{
	int			i;
	char const	*s;

	i = 0;
	s = "0123456789abcdef";
	if (nb >= 16)
		i = ft_printhexlnbr(nb / 16);
	ft_putchar(s[nb % 16]);
	i++;
	return (i);
}

int	ft_printhexbnbr(unsigned long long nb)
{
	int			i;
	char const	*s;

	i = 0;
	s = "0123456789ABCDEF";
	if (nb >= 16)
		i = ft_printhexbnbr(nb / 16);
	ft_putchar(s[nb % 16]);
	i++;
	return (i);
}
/*
int main()
{
	printf("%d", ft_printhexlnbr(-1));
	return (0);
}
*/