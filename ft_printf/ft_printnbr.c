/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:40:52 by nicolas           #+#    #+#             */
/*   Updated: 2023/04/18 12:06:20 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	intmin(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	return (11);
}

int	ft_printnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		i += 1;
	}
	if (nb >= 10)
		i += ft_printnbr(nb / 10);
	i += ft_printchar(nb % 10 + '0');
	return (i);
}
