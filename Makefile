NAME = push_swap
SRCS = main.c \
	push_swap.c
OPS = op_push.c \
	op_rev_rotate.c \
	op_rotate.c \
	op_swap.c \
	op_utils.c \
	use_operator_1.c \
	use_operator_2.c \
	use_operator_3.c
UTILS = init_utils.c \
	error_handlers.c \
	is_sorted.c \
	calc_a.c \
	calc_b.c \
	calc_both.c
OP_DIR = ./operators/
UTILS_DIR = ./utils/
SRCS += $(addprefix $(OP_DIR), $(OPS)) \
	$(addprefix $(UTILS_DIR), $(UTILS))
CC = cc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I ./includes -I $(LIBFT_DIR)/

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(INCLUDES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) a.out
	make fclean -C $(LIBFT_DIR)

re: fclean all

test: $(LIBFT)
	@$(CC) $(TFLAGS) $(INCLUDES) $(SRCS) -L$(LIBFT_DIR) -lft && ./a.out 1 2 48 08 09812 214 81212  12401 12841 21 098 102 1204 127 93214 31

.PHONY: all clean fclean re test