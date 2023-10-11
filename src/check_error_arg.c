/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:14:33 by npatron           #+#    #+#             */
/*   Updated: 2023/10/10 12:06:44 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	there_is_point(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.')
			j++;
		i++;
	}
	if (j != 1)
		return (0);
	return (1);
}

int	after_point(char *s, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (there_is_point(s) == 0)
		return (0);
	while (s[i] != '.')
		i++;
	while (s[i] || s2[j])
	{
		if (s[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int	check_arg(int argc, char *argv)
{
	if (argc == 2 && after_point(&argv[1], ".ber") == 1)
		return (1);
	else
	{
		ft_printf("please man, check your args\n");
		return (0);
	}
}
