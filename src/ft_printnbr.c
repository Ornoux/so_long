/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:40:52 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 12:21:18 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	intmin(int nb)
{
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
