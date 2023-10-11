/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:57:53 by npatron           #+#    #+#             */
/*   Updated: 2023/10/10 12:21:07 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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