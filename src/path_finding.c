/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 22:07:11 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 13:20:03 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copymap_to_tab(t_game *game, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	game->copymap = malloc(sizeof(char *) * game->line);
	while (i != game->line)
		game->copymap[i++] = get_next_line(fd);
	game->copymap[i] = 0;
	close(fd);
}

void	full_filled(t_game *game, int x, int y)
{
	if (game->copymap[x][y] != '1' && game->copymap[x][y] != 'A')
	{
		game->copymap[x][y] = 'A';
		full_filled(game, x - 1, y);
		full_filled(game, x + 1, y);
		full_filled(game, x, y - 1);
		full_filled(game, x, y + 1);
	}
}

void	full_filled_the_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i != game->line)
	{
		j = 0;
		while (j != game->count_c_line)
		{
			if (game->copymap[i][j] == 'P')
			{
				full_filled(game, i, j);
				j = 0;
			}
			j++;
		}
		i++;
	}
}

void	path_finding(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i != game->line)
	{
		j = 0;
		while (j != game->count_c_line)
		{
			if (game->copymap[i][j] == 'C' || game->copymap[i][j] == 'E')
			{
				ft_printf("your map is not solvable\n");
				ft_exit(game);
			}
			j++;
		}
		i++;
	}
}
