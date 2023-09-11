/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:29:58 by npatron           #+#    #+#             */
/*   Updated: 2023/09/11 15:43:16 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (!fd)
		return (0);
	if (check_arg(argc, argv[1]) == 0)
		exit(EXIT_FAILURE);
	line_on_map(&game, argv[1]);
	map_to_tab(&game, argv[1]);
	map_is_rectangular(&game);
	map_is_close(&game);
	map_content(&game);
	verify_content(&game);
	return (0);
}