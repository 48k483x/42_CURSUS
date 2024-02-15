FLAGS = -g -Wall -Wextra -Werror
SRC = ./moves/push.c ./moves/swap.c ./moves/rotate.c ./moves/reverse_rotate.c \
        push_swap.c ./utils/atol.c ./utils/fill_stack.c ./utils/input_check.c  \
		./sorting/three.c ./sorting/stack_utils.c ./sorting/five.c ./utils/parsing.c \
		./utils/split.c ./sorting/more.c ./sorting/stack_utils_0.c 

SRCB = ./bonus/checker_bonus.c ./moves/push.c ./moves/swap.c ./moves/rotate.c ./moves/reverse_rotate.c \
        push_swap.c ./utils/atol.c ./utils/fill_stack.c ./utils/input_check.c  \
		./sorting/three.c ./sorting/stack_utils.c ./sorting/five.c ./utils/parsing.c \
		./utils/split.c ./sorting/more.c ./sorting/stack_utils_0.c \


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRCB:.c=.o)
NAME = push_swap
BONUS_NAME = checker
all: $(NAME)

$(NAME): $(OBJ)
	@cc $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	@cc $(FLAGS) -c $(SRC)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	@cc $(OBJ_BONUS) -o $(BONUS_NAME)

clean:
	@rm -rf $(OBJ)
fclean:
	@rm -rf $(OBJ)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
