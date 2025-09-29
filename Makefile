NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinclude

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC         = main.c \
              parsing/parsing.c parsing/check_args.c parsing/normalize.c \
              stack/stack_utils.c stack/stack_utils_2.c \
              operations/push.c operations/reverse_rotate.c operations/rotate.c operations/swap.c \
              sorting/sort_small.c sorting/sort_fresh.c sorting/rotation_utils.c sorting/LIS.c sorting/insertion_utils.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
