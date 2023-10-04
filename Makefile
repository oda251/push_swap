NAME = push_swap
SRCS = main.c \
	check_integer.c \
	push_swap.c
OPS = op_push.c \
	op_rev_rotate.c \
	op_rotate.c \
	op_swap.c \
	op_utils.c \
	use_operator_1.c \
	use_operator_2.c \
	use_operator_3.c
UTILS = check_integer.c \
	is_sorted.c
OP_DIR = ./operators/
UTILS_DIR = ./utils/
SRCS += $(addprefix $(OP_DIR), $(OPS)) \
	$(addprefix $(UTILS_DIR), $(UTILS))
CC = cc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I./

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
	@$(CC) $(TFLAGS) $(SRCS) -L$(LIBFT_DIR) -lft $(INCLUDES) && ./a.out

.PHONY: all clean fclean re test