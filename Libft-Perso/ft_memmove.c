/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:47:53 by npatron           #+#    #+#             */
/*   Updated: 2023/03/28 12:06:09 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	void	*temp;

	i = 0;
	temp = 0;
	while (i <= n)
	{
		((unsigned char *)temp)[i] = ((unsigned char *)src)[i];
		((unsigned char *)dest)[i] = ((unsigned char *)temp)[i];
		i++;
	}
	return (dest);
}
