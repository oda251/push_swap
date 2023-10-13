NAME = push_swap
CHECKER = checker
SRCS = main.c \
	push_swap.c \
	calc_small.c \
	calc_large.c \
	push_a_all.c
OPS = op_push.c \
	op_rev_rotate.c \
	op_rotate.c \
	op_swap.c \
	op_utils.c \
	use_operator_1.c \
	use_operator_2.c \
	use_operator_3.c
UTILS = interpret_args.c \
	convert_consecutives.c \
	exit_handlers.c \
	is_sorted.c \
	calc_a.c \
	calc_b.c
CHECKER_SRCS = $(addprefix $(OP_DIR), $(OPS)) \
	$(addprefix $(CHECKER_DIR), checker.c) \
	$(addprefix $(UTILS_DIR), $(UTILS))
OP_DIR = ./operators/
UTILS_DIR = ./utils/
CHECKER_DIR = ./bonus/
SRCS += $(addprefix $(OP_DIR), $(OPS)) \
	$(addprefix $(UTILS_DIR), $(UTILS))
CC = cc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I ./includes/ -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(CHECKER)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(CHECKER) $(CHECKER_SRCS)


$(CHECKER): $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(CHECKER) $(CHECKER_SRCS) -L$(LIBFT_DIR) -lft

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) a.out
	make fclean -C $(LIBFT_DIR)

re: fclean all

test: $(LIBFT)
	@$(CC) $(TFLAGS) $(INCLUDES) $(SRCS) -L$(LIBFT_DIR) -lft && ./a.out 27 10 19 12 2 17 1 22 21 28 14 0 24 9 20 26 18 29 25 15 16 7 5 8 4 6 23 13 3 11


.PHONY: all clean fclean re test bonus