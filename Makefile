CC = cc
CFLAGS = -g -ggdb3
CMLX = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -L libft -lft -lm -lz -g -ggdb3
SRC = mandatory/rendering/display.c mandatory/rendering/key_hook_part1.c mandatory/rendering/key_hook_part2.c \
	 	mandatory/rendering/main_mandatory.c mandatory/rendering/read_map.c \
		mandatory/parsing/check_ber.c mandatory/parsing/check_characters.c mandatory/parsing/check_rectangularity.c \
		mandatory/parsing/check_walls.c mandatory/parsing/check_path.c mandatory/parsing/free_leaks.c

OBJ = $(SRC:%.c=%.o)
NAME = so_long
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CMLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

