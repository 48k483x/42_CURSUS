FLAGS = -g -Wall -Wextra -Werror
SRC = ./moves/push.c ./moves/swap.c ./moves/rotate.c ./moves/reverse_rotate.c \
		push_swap.c ./utils/atol.c ./utils/fill_stack.c ./utils/input_check.c  \
		./sorting/three.c ./sorting/stack_utils.c ./sorting/five.c ./utils/parsing.c \
		./utils/split.c ./sorting/more.c ./sorting/stack_utils_0.c 

SRCB = ./bonus/checker_bonus.c ./moves/push.c ./moves/swap.c ./moves/rotate.c ./moves/reverse_rotate.c \
		push_swap.c ./utils/atol.c ./utils/fill_stack.c ./utils/input_check.c  \
		./sorting/three.c ./sorting/stack_utils.c ./sorting/five.c ./utils/parsing.c \
		./utils/split.c ./sorting/more.c ./sorting/stack_utils_0.c \

RM = rm -f
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRCB:.c=.o)
NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_BONUS)
	cc $(FLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

clean:
	 $(RM) *.o

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SECONDARY: $(OBJ) $(OBJ_BONUS)