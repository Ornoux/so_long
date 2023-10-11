/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:29:28 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/03 11:27:02 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	run_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->line)
	{
		j = 0;
		while (j < game->count_c_line)
		{
			if (game->map[i][j] == '0' || game->map[i][j] == 'C'
				|| game->map[i][j] == 'P' || game->map[i][j] == 'E')
				put_img(game, game->floor, j * 64, i * 64);
			if (game->map[i][j] == 'P')
				put_img(game, game->player, j * 64, i * 64);
			if (game->map[i][j] == 'C')
				put_img(game, game->collect, j * 64, i * 64);
			if (game->map[i][j] == '1')
				put_img(game, game->wall, j * 64, i * 64);
			if (game->map[i][j] == 'E')
				put_img(game, game->exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}
