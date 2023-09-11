SOURCES = 	check_error_arg.c parse_map_utils.c parse_map_utils_2.c so_long.c get_next_line.c get_next_line_utils.c ft_strlenght.c

OBJS            = $(SOURCES:.c=.o)
NAME			= so_long
CC              = gcc
RM              = rm -rf
FLAGS          = -Wall -Wextra -Werror
ARFLAGS = -rcs

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)
src/%.o: src/%.c
		$(CC) $(FLAGS) -Imlx -c $< -o $@

all :           $(NAME)

$(NAME):        $(OBJS)
		gcc $(FLAGS) $(OBJS) -o $(NAME) 
		
clean:
				$(RM) $(OBJS)

fclean:         clean
				$(RM) $(NAME)
				
re:             fclean $(NAME)

.PHONY:         all clean fclean re