/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:48:43 by npatron           #+#    #+#             */
/*   Updated: 2023/10/11 03:17:56 by nicolas          ###   ########.fr       */
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
		ft_printf("man...\n");
		ft_exit(game);
	}
	fd = open(argv, O_RDONLY);
	s = get_next_line(fd);
	if (!s)
	{
		ft_printf("man...\n");
		ft_exit(game);
	}
	game->line = 0;
	game->count_c_line = ft_strlen(s) - 1;
	while (s)
	{
		free(s);
		game->line++;
		s = get_next_line(fd);
	}
}

void	map_to_tab(t_game *game, char *argv)
{
	int		fd;
	int		i;

	fd = open(argv, O_RDONLY);
	i = 0;
	game->mvts = 0;
	game->map = malloc(sizeof(char *) * game->line);
	while (i != game->line)
		game->map[i++] = get_next_line(fd);
	game->map[i] = 0;
	close(fd);
}
