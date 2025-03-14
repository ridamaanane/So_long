CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CMLX = -lmlx -lXext -lX11

SRC = mandatory/rendering/display.c mandatory/rendering/key_hook_part1.c mandatory/rendering/key_hook_part2.c \
      mandatory/rendering/main_mandatory.c mandatory/rendering/read_map.c \
      mandatory/parsing/check_ber.c mandatory/parsing/check_characters.c mandatory/parsing/check_rectangularity.c \
      mandatory/parsing/check_walls.c mandatory/parsing/check_path.c mandatory/parsing/free_leaks.c

SRCB = bonus/rendering/display_bonus.c bonus/rendering/key_hook_part1_bonus.c bonus/rendering/key_hook_part2_bonus.c \
       bonus/rendering/main_bonus_bonus.c bonus/rendering/read_map_bonus.c \
       bonus/parsing/check_ber_bonus.c bonus/parsing/check_characters_bonus.c bonus/parsing/check_rectangularity_bonus.c \
       bonus/parsing/check_walls_bonus.c bonus/parsing/check_path_bonus.c bonus/parsing/free_leaks_bonus.c bonus/rendering/animation_bonus.c

OBJ = $(SRC:%.c=%.o)
OBJB = $(SRCB:%.c=%.o)

BONUS = .bns

NAME = so_long
RM = rm -f

all: libft_rule $(NAME)

bonus: libft_rule $(BONUS)

$(BONUS): $(OBJB)
	@touch $(BONUS)
	$(CC) $(OBJB) $(CMLX) -L$(LIBFT_DIR) -lft -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CMLX) -L$(LIBFT_DIR) -lft -o $(NAME)

libft_rule:
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ) $(OBJB)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@$(RM) $(BONUS)
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	

re: fclean all

.SECONDARY: $(OBJ) $(OBJB)
.PHONY: all clean fclean re bonus
