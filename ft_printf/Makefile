# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achahrou <achahrou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 09:06:56 by achahrou          #+#    #+#              #
#    Updated: 2023/11/20 09:09:11 by achahrou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_printf_C.c ft_printf_D.c ft_printf_S.c \
	ft_putchar.c ft_putnbr.c ft_putstr.c \
	ft_strlen.c \
		
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
