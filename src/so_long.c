/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:29:58 by npatron           #+#    #+#             */
/*   Updated: 2023/10/10 12:55:25 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_game *game)
{
	(void)game;
	exit(0);
}

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		ft_exit(game);
	if (key == 119)
	{
		forward_player(game);
		ft_printf("Moves : %d\n", game->mvts);
	}
	if (key == 100)
	{
		right_player(game);
		ft_printf("Moves : %d\n", game->mvts);
	}
	if (key == 115)
	{
		backward_player(game);
		ft_printf("Moves : %d\n", game->mvts);
	}
	if (key == 97)
	{
		left_player(game);
		ft_printf("Moves : %d\n", game->mvts);
	}
	return (0);
}

int	key_release(int key, t_game *game)
{
	(void)game;
	if (key == 65307)
		ft_exit(game);
	if (key == 119)
		game->key[0] = 0;
	if (key == 100)
		game->key[1] = 0;
	if (key == 115)
		game->key[2] = 0;
	if (key == 97)
		game->key[3] = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	if (check_arg(argc, argv[1]) == 0)
		ft_exit(&game);
	line_on_map(&game, argv[1]);
	map_to_tab(&game, argv[1]);
	map_is_close(&game);
	copymap_to_tab(&game, argv[1]);
	full_filled_the_map(&game);
	path_finding(&game);
	map_is_rectangular(&game);
	map_content(&game);
	verify_content(&game);
	mlx(&game);
	return (0);
}
