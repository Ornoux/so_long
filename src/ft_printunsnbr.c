/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:22:31 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 12:15:10 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_printunsnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_printunsnbr(nb / 10);
	i += ft_printchar(nb % 10 + '0');
	return (i);
}
