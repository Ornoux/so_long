/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:55:51 by nicolas           #+#    #+#             */
/*   Updated: 2023/10/03 11:33:39 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, void	*img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img, x, y);
}

void	*ft_img(t_game *game, char *name)
{
	int		a;
	void	*new;

	new = mlx_xpm_file_to_image(game->mlx_ptr, name, &a, &a);
	if (!new)
		exit(0);
	return (new);
}

void	init_mlx(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->count_c_line * 64, \
	game->line * 64, "so_long");
	mlx_loop_hook(game->mlx_ptr, run_game, game);
	mlx_hook(game->win_ptr, 33, 1L << 17, ft_exit, game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, key_release, game);
	mlx_loop(game->mlx_ptr);
}

void	init(t_game *game)
{
	game->key = ft_calloc(5, sizeof(int));
	game->mlx_ptr = mlx_init();
	game->floor = ft_img(game, "./img/floor.xpm");
	game->player = ft_img(game, "./img/player.xpm");
	game->wall = ft_img(game, "./img/wall.xpm");
	game->collect = ft_img(game, "./img/collect.xpm");
	game->exit = ft_img(game, "./img/exit.xpm");
}

void	mlx(t_game *game)
{
	init(game);
	init_mlx(game);
}
