/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsnbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 19:22:31 by nicolas           #+#    #+#             */
/*   Updated: 2023/04/18 12:08:33 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printunsnbr(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb >= 10)
		i += ft_printunsnbr(nb / 10);
	i += ft_printchar(nb % 10 + '0');
	return (i);
}
