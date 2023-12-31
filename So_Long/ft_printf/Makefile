# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 09:06:56 by achahrou          #+#    #+#              #
#    Updated: 2023/11/22 12:53:31 by achahrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf.c ft_putchar.c \
		ft_putnbr.c ft_putstr.c \
		ft_strlen.c ft_puthexa.c ft_putptr.c ft_putunbr.c 
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
LIBC = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
