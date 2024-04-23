NAME = so_long

SRC = so_long.c get_next_line_utils.c get_next_line.c ft_split.c utils.c check_map.c gui_map.c arrow_keys.c

CFLAGS = -Wall -Wextra -Werror -Imlx

OBJ = ${SRC:.c=.o}
# OBJ_BONUS = ${SRC_BONUS:.c=.o}

all : $(NAME)

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(OBJ) -Lmlx_library -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(NAME): $(OBJ)
# 		$(CC) $(OBJ) -Lmlx_linux ./minilibx-linux/libmlx_Linux.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
# bonus : $(NAME_BONUS)

# $(NAME_BONUS): $(OBJ_BONUS)
# 				cc $(CFLAGS) $^ -o $(NAME_BONUS)

clean : 
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -rf $(NAME) $(NAME_BONUS)

re : fclean all