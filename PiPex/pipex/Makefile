FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -g
SRC = ft_split.c pipex.c utils.c \
		 get_next_line.c get_next_line_utils.c check_here_doc.c
OBJ = *.o
NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	cc $(DEBUG_FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	cc $(FLAGS) $(DEBUG_FLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
