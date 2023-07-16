/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:18:08 by npatron           #+#    #+#             */
/*   Updated: 2023/07/14 21:51:08 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "./gnl/get_next_line.h"

typedef struct s_game 
{
	char	**map;
	int		line;
	int		count_c_line;

}	t_game;

int			there_is_point(char *str);
int			after_point(char *s, char *s2);
int			check_arg(int argc, char *argv);
// char		**ft_split(char const *s, char c);
// static char	*copy_string(char const *s, char c, int i);
// static int	count_words(char const *s, char c);

void		line_on_map(t_game *game, char *argv);
void		map_to_tab(t_game *game, char *argv);
void		check_big_lines(t_game *game);

# endif