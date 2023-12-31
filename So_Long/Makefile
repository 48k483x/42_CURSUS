# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahrou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/31 11:47:08 by achahrou          #+#    #+#              #
#    Updated: 2023/12/31 11:47:13 by achahrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lX11 -lXext -lmlx  
SRC = so_long.c ./utils/mapsReading.c ./utils/get_next_line_utils.c ./utils/get_next_line.c 
OBJ = *.o
NAME = so_long

all: $(NAME)

$(NAME): $(OBJ)
	cc $(MLXFLAGS) $(OBJ) -o $(NAME)
$(OBJ): $(SRC)
	cc $(FLAGS) -c $(SRC)
clean: $(OBJ)
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re
