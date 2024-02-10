FLAGS = -g -Wall -Wextra -Werror
SRC = ./moves/push.c ./moves/swap.c \
        ./moves/rotate.c ./moves/reverse_rotate.c \
        push_swap.c ./utils/atol.c ./utils/fill_stack.c \
        ./utils/input_check.c ./sorting/three.c \
        ./sorting/five.c ./utils/sorting_utils.c ./utils/parsing.c ./utils/split.c
OBJ = *.o
NAME = push_swap
DURATION = 1.5  # Minimum duration to show animation (in seconds)

all: $(NAME)

$(NAME): $(OBJ)
	@./loading.sh &   # Start loading animation in the background
	@cc $(OBJ) -o $(NAME)
	@sleep $(DURATION)
	@ps -ef | grep "loading.sh" | grep -v grep | awk '{print $$2}' | xargs kill -9 >/dev/null 2>&1 || true   # Kill the loading animation once compilation is complete
	@echo -e "\e[38;2;232;226;0mCompleted\e[0m"  # Print "Completed" in the specified color

$(OBJ): $(SRC)
	@cc $(FLAGS) -c $(SRC)

clean:
	@./cleaning.sh &
	@rm -rf $(OBJ)
	@sleep $(DURATION)
	@ps -ef | grep "cleaning.sh" | grep -v grep | awk '{print $$2}' | xargs kill -9 >/dev/null 2>&1 || true   # Kill the loading animation once             compilation is complete
	@echo -e "\e[38;2;255;40;0mCleaned\e[0m"  # Print "Cleaned" in red

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
