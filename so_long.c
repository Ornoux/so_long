/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:29:58 by npatron           #+#    #+#             */
/*   Updated: 2023/07/13 11:23:50 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	int		i;
	t_game	game;
	int		fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (check_arg(argc, argv[1]) == 0)
		exit(EXIT_FAILURE);
	line_on_map(&game, argv[1]);
	map_to_tab(&game, argv[1]);
	return (0);
}