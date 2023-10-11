# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 14:20:24 by fbardeau          #+#    #+#              #
#    Updated: 2023/10/10 12:40:45 by nicolas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = check_error_arg.c ft_strlenght.c init_mlx.c \
	  moves.c parse_map_utils.c parse_map_utils_2.c \
	  path_finding.c so_long.c utils.c\
	  get_next_line.c print_elements.c get_next_line_utils.c \
	  ft_printf.c ft_printhexnbr.c ft_printnbr.c \
	  ft_printstr.c ft_printunsnbr.c ft_putchar_fd.c \
	  ft_putchar.c \
	  

NAME = so_long

MLX_DIR = minilibx-linux
MLX = libmlx.a
CC = clang

# diff entre .a et .dylib
# .a = lib static, les fonctions utilisees sont directement ecrite dans le binaire
# .dylib = lib dynamique, les fonctions doivent etre chargees au momnent ou on lance le binaire

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = libft

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.d))

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

# -C faire make comme si on etait dana le dossier
# -j multisreder / ameliore la vitesse de compliation
# Pas de regle opti car makefile mlx pas compatible
all:
	@$(MAKE) -j $(NAME)

# permet de pouvoir comparer la derniere modification de la dep par rapport a la regle
# -L donner le nom du dossier / -l donner le nom le la lib
# loader path = ecrit le chemin de la mlx dans le binaire pour pouvoir la retrouver au moment ou on lance le binaire
$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
		@echo $(NAME) : Created !

# si le .c est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | .gitignore
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(INC_DIR) -I $(MLX_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj deleted"

fclean:	clean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: deleted"

re: fclean all

.PHONY: all, clean, fclean, re

# Utilise les .d (et ignore s'ils n'existe pas)
-include $(DPD)