FLAGS = -g -Wall -Wextra -Werror
SRC = ./moves/push.c ./moves/swap.c \
		./moves/rotate.c ./moves/reverse_rotate.c \
		push_swap.c ./utils/atoi.c ./utils/fill_stack.c \
		./utils/input_check.c ./sorting/three.c \
		./sorting/five.c
OBJ = *.o
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	cc $(OBJ) -o $(NAME)
$(OBJ): $(SRC)
	cc $(FLAGS) -c $(SRC)
clean: $(OBJ)
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re