# Define compiler and flags
CC = gcc
FLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_split.c pipex.c utils.c

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
NAME = pipex

all: $(NAME)

# Compile the executable
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

# Compile individual source files to object files
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Clean everything, including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean re

# Define a target to show progress
progress:
	@echo "Uploading and downloading: 0%"
	@sleep 1
	@echo "Uploading and downloading: 25%"
	@sleep 1
	@echo "Uploading and downloading: 50%"
	@sleep 1
	@echo "Uploading and downloading: 75%"
	@sleep 1
	@echo "Uploading and downloading: 100%"

