NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -Iinclude

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC         = main.c \
              parsing/parse_args.c parsing/check_args.c parsing/normalize.c \
              stack/stack_utils.c stack/stack_ops.c stack/free_stack.c \
              operations/op_swap.c operations/op_push.c operations/op_rotate.c operations/op_rev_rotate.c \
              sorting/sort_small.c sorting/sort_fresh.c sorting/sort_utils.c

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
