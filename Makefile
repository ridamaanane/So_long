CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CMLX = -lmlx -lXext -lX11

SRC = display.c key_hook_part1.c key_hook_part2.c \
      main_mandatory.c read_map.c \
      check_ber.c check_characters.c check_rectangularity.c \
      check_walls.c check_path.c free_leaks.c

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
