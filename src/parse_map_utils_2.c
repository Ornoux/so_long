/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:36:35 by npatron           #+#    #+#             */
/*   Updated: 2023/10/10 12:22:21 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_is_close(t_game *game)
{
	int	i;

	i = 0;
	while (i <= game->count_c_line - 1)
	{
		if ((game->map[0][i] != '1' || game->map[game->line - 1][i] != '1'))
		{
			ft_printf("please man, your map is not close\n");
			ft_exit(game);
		}
		i++;
	}
	i = 0;
	while (i <= game->line - 1)
	{
		if (game->map[i][0] != '1' ||
			game->map[i][game->count_c_line - 1] != '1')
		{
			ft_printf("please man, your map is not close\n");
			ft_exit(game);
		}
		i++;
	}
}

void	map_is_rectangular(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlenght(game->map[0]);
	while (i != game->line)
	{
		if (ft_strlenght(game->map[i]) != len)
		{
			ft_printf("please man, your map is not rectangular\n");
			ft_exit(game);
		}
		i++;
	}
}

void	map_content(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i != game->line - 1)
	{
		while (j != game->count_c_line - 1)
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'P' &&
				game->map[i][j] != 'E' && game->map[i][j] != '1' &&
				game->map[i][j] != '0')
			{
				ft_printf("please man, check your content's map\n");
				ft_exit(game);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	count_content(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->nbr_c = 0;
	game->nbr_p = 0;
	game->nbr_e = 0;
	while (i != game->line)
	{
		while (j != game->count_c_line)
		{
			if (game->map[i][j] == 'C')
				game->nbr_c += 1;
			if (game->map[i][j] == 'P')
				game->nbr_p += 1;
			if (game->map[i][j] == 'E')
				game->nbr_e += 1;
			j++;
		}
		j = 0;
		i++;
	}
}

void	verify_content(t_game *game)
{
	count_content(game);
	if (game->nbr_c < 1 || game->nbr_p != 1 || game->nbr_e < 1)
	{
		ft_printf("please man, check your content's number\n");
		ft_exit(game);
	}
}
