NAME = push_swap
CHECKER = checker
SRC = main.c \
	push_swap.c \
	calc_small.c
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
	calc_b.c \
	calc_times_to_rotate.c \
	push_a_all.c \
	ps_strcmp.c \
	convert_str_arg.c
CHECKER_SRC = checker.c \
	get_next_line.c \
	get_next_line_utils.c
CHECKER_SRCS = $(addprefix $(OP_DIR), $(OPS)) \
	$(addprefix $(CHECKER_DIR), $(CHECKER_SRC)) \
	$(addprefix $(UTILS_DIR), $(UTILS))
SRC_DIR = src/
OP_DIR = operators/
UTILS_DIR = utils/
CHECKER_DIR = bonus/
SRCS = $(addprefix $(SRC_DIR), $(SRC)) \
	$(addprefix $(OP_DIR), $(OPS)) \
	$(addprefix $(UTILS_DIR), $(UTILS))
CC = cc
CFLAGS = -Wall -Wextra -Werror
TFLAGS = -Wall -Wextra -g -fsanitize=address
LIBFT_DIR = libft/
LIBFT =  $(addprefix $(LIBFT_DIR), libft.a)
INCLUDES = -I includes/ -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(SRCS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(CHECKER)

$(CHECKER): $(LIBFT) $(CHECKER_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(CHECKER) $(CHECKER_SRCS) -L$(LIBFT_DIR) -lft

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(CHECKER) a.out
	make fclean -C $(LIBFT_DIR)

re: fclean all

test: $(LIBFT) $(CHECKER) $(SRCS)
	@$(CC) $(TFLAGS) $(INCLUDES) $(SRCS) -o $(NAME) -L$(LIBFT_DIR) -lft
	@python3 push_swap_tester.py

.PHONY: all clean fclean re test bonus