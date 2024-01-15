FLAGS = -Wall -Wextra -Werror
SRC = ft_split.c pipex.c utils.c
OBJ = *.o
NAME = pipex

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
