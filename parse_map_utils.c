/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:48:43 by npatron           #+#    #+#             */
/*   Updated: 2023/07/14 20:40:25 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_on_map(t_game *game, char *argv)
{
	int		fd;
	char	*s;

	printf("bonjour");
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
	printf("%d", game->line);
	close(fd);
}

void	map_to_tab(t_game *game, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	game->map = malloc(sizeof(char *) * game->line);
	while (i <= game->line)
		game->map[i++] = get_next_line(fd);
	game->map[i] = 0;
	printf("%s\n", game->map[0]);
	printf("%s\n", game->map[1]);
	printf("%s\n", game->map[2]);
	printf("%s\n", game->map[3]);
	printf("%s\n", game->map[4]);
}