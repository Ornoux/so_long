/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:36:35 by npatron           #+#    #+#             */
/*   Updated: 2023/07/14 22:56:19 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_big_lines(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
		{
			printf("Connard");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	while (game->map[game->line][j])
	{
		if (game->map[game->line][j] != '1')
		{
			printf("Connard");
			exit(EXIT_FAILURE);
		}
	j++;
	}
}

void	check_start(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1')
		{
			printf("Connard");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_end(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		while (game->map[i][j] < '\n')
			j++;
		if (game->map[i][j] != '1')
		{
			printf("Connard");
			exit(EXIT_FAILURE);
		}
		j = 0;
		i++;
	}
}