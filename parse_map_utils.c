/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:48:43 by npatron           #+#    #+#             */
/*   Updated: 2023/07/18 15:49:58 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_on_map(t_game *game, char *argv)
{
	int		fd;
	char	*s;

	fd = open(argv, O_DIRECTORY);
	if (fd > 0)
	{
		printf("Nique ta race");
		exit(EXIT_FAILURE);
	}
	fd = open(argv, O_RDONLY);
	s = get_next_line(fd);
	game->line = 0;
	game->count_c_line = ft_strlen(s) - 1;
	while (s)
	{
		free(s);
		game->line++;
		s = get_next_line(fd);
	}
	close(fd);
}

void	map_to_tab(t_game *game, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	game->map = malloc(sizeof(char *) * game->line);
	while (i != game->line)
		game->map[i++] = get_next_line(fd);
	game->map[i] = 0;
	close(fd);
}