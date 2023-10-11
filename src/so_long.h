/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 21:18:08 by npatron           #+#    #+#             */
/*   Updated: 2023/10/11 03:12:28 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *s);

int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int nb);
int		ft_printunsnbr(unsigned int nb);
void	ft_putchar(char c);
int		ft_printhexbnbr(unsigned long long nb);
int		ft_printhexlnbr(unsigned long long nb);
int		ft_printchar(char c);

typedef struct s_game
{
	char	**map;
	char	**copymap;
	int		line;
	int		count_c_line;
	int		nbr_c;
	int		nbr_e;
	int		nbr_p;
	void	*mlx_ptr;
	void	*win_ptr;
	int		*key;
	void	*player;
	void	*floor;
	void	*collect;
	void	*exit;
	void	*wall;
	int		xp;
	int		yp;
	int		mvts;
}	t_game;

int		there_is_point(char *str);
int		after_point(char *s, char *s2);
int		check_arg(int argc, char *argv);
// char		**ft_split(char const *s, char c);
// static char	*copy_string(char const *s, char c, int i);
// static int	count_words(char const *s, char c);

void	line_on_map(t_game *game, char *argv);
void	map_to_tab(t_game *game, char *argv);
void	check_end(t_game *game);
void	check_start(t_game *game);
void	map_is_close(t_game *game);
void	map_is_rectangular(t_game *game);
int		ft_strlenght(char *s);
void	map_content(t_game *game);
void	verify_content(t_game *game);
void	count_content(t_game *game);
int		run_game(t_game *game);
int		ft_exit(t_game *game);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	put_img(t_game *game, void	*img, int x, int y);
void	*ft_img(t_game *game, char *name);
void	init_mlx(t_game *game);
void	mlx(t_game *game);
void	init(t_game *game);
void	forward_player(t_game *game);
void	backward_player(t_game *game);
void	left_player(t_game *game);
void	right_player(t_game *game);
void	where_is_p(t_game *game);
void	path_finding(t_game *game);
void	full_filled_the_map(t_game *game);
void	full_filled(t_game *game, int x, int y);
int		run_game_2(t_game *game);
void	copymap_to_tab(t_game *game, char *argv);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	*ft_calloc(size_t nmemb, size_t size);

#endif