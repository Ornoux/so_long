/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:20:52 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/10 12:39:50 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	where_is_p(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i != game->line)
	{
		j = 0;
		while (j != game->count_c_line)
		{
			if (game->map[i][j] == 'P')
			{
				game->xp = i;
				game->yp = j;
			}
			j++;
		}
		i++;
	}
}

void	forward_player(t_game *game)
{
	where_is_p(game);
	count_content(game);
	if (game->map[game->xp - 1][game->yp] != '1'
		&& game->map[game->xp - 1][game->yp] != 'E')
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp - 1][game->yp] = 'P';
		game->mvts++;
		if (game->map[game->xp - 1][game->yp] == 'C')
		{
			game->nbr_c -= 1;
			game->mvts++;
		}
	}
	if (game->map[game->xp - 1][game->yp] == 'E' && game->nbr_c == 0)
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp - 1][game->yp + 1] = 'P';
		game->mvts++;
		ft_exit(game);
	}
}

void	backward_player(t_game *game)
{
	where_is_p(game);
	count_content(game);
	if (game->map[game->xp + 1][game->yp] != '1'
		&& game->map[game->xp + 1][game->yp] != 'E')
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp + 1][game->yp] = 'P';
		game->mvts++;
		if (game->map[game->xp + 1][game->yp] == 'C')
		{
			game->nbr_c -= 1;
			game->mvts++;
		}
	}
	if (game->map[game->xp + 1][game->yp] == 'E' && game->nbr_c == 0)
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp + 1][game->yp] = 'P';
		game->mvts++;
		ft_exit(game);
	}
}

void	right_player(t_game *game)
{
	count_content(game);
	where_is_p(game);
	if (game->map[game->xp][game->yp + 1] != '1' &&
		game->map[game->xp][game->yp + 1] != 'E')
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp][game->yp + 1] = 'P';
		game->mvts++;
		if (game->map[game->xp][game->yp + 1] == 'C')
		{
			game->nbr_c -= 1;
			game->mvts++;
		}
	}
	if (game->map[game->xp][game->yp + 1] == 'E' && game->nbr_c == 0)
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp][game->yp + 1] = 'P';
		game->mvts++;
		ft_exit(game);
	}
}

void	left_player(t_game *game)
{
	where_is_p(game);
	count_content(game);
	if (game->map[game->xp][game->yp - 1] != '1'
		&& game->map[game->xp][game->yp - 1] != 'E')
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp][game->yp - 1] = 'P';
		game->mvts++;
		if (game->map[game->xp][game->yp - 1] == 'C')
		{
			game->nbr_c -= 1;
			game->mvts++;
		}
	}
	if (game->map[game->xp][game->yp - 1] == 'E' && game->nbr_c == 0)
	{
		game->map[game->xp][game->yp] = '0';
		game->map[game->xp][game->yp - 1] = 'P';
		game->mvts++;
		ft_exit(game);
	}
}
