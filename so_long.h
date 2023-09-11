/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:18:08 by npatron           #+#    #+#             */
/*   Updated: 2023/09/11 15:43:42 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_game 
{
	char	**map;
	int		line;
	int		count_c_line;
	int		nbr_c;
	int		nbr_e;
	int		nbr_p;
}	t_game;

int			there_is_point(char *str);
int			after_point(char *s, char *s2);
int			check_arg(int argc, char *argv);
// char		**ft_split(char const *s, char c);
// static char	*copy_string(char const *s, char c, int i);
// static int	count_words(char const *s, char c);

void		line_on_map(t_game *game, char *argv);
void		map_to_tab(t_game *game, char *argv);
void		check_end(t_game *game);
void		check_start(t_game *game);
void		map_is_close(t_game *game);
void		map_is_rectangular(t_game *game);
int			ft_strlenght(char *s);
void		map_content(t_game *game);
void		verify_content(t_game *game);
void		count_content(t_game *game);

# endif