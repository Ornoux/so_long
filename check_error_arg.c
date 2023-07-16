/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:14:33 by npatron           #+#    #+#             */
/*   Updated: 2023/07/13 10:45:24 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int there_is_point(char *str)
{
	int i;
	int j;

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

int after_point(char *s, char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc == 2 && after_point(&argv[1], ".ber") == 1)
	{
		printf("Success");
		return (1);
	}
	else
	{
		printf("Impossible d'accord ?");
		return (0);
	}
}
