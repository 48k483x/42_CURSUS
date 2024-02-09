NAME 	= push_swap
BNAME 	= checker
CC 		= cc
FLAGS 	= -g -Wall -Wextra -Werror #-fsanitize=address -g3
RM 		= rm -f
SRCS 	=	sources/sorting_utils/sorting_algo_0.c \
                          sources/sorting_utils/sorting_algo_1.c \
                          sources/sorting_utils/sorting_algo_2.c \
                          sources/stack_utils/stack_utils_0.c \
                          sources/stack_utils/stack_utils_1.c \
                          sources/stack_utils/stack_utils_2.c \
                          sources/operations/operations_0.c \
                          sources/operations/operations_1.c \
                          sources/operations/operations_2.c \
                          sources/parsing/error_handler.c \
                          ft_printf/ft_printf.c \
                          ft_printf/ft_putnbr.c \
                          ft_printf/ft_putstr.c \
                          ft_printf/ft_puthex.c \
                          ft_printf/ft_putadd.c \
                          ft_printf/ft_putunbr.c \
                          ft_printf/ft_putchar.c \
                          push_swap.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_bzero.c \
                          libft/ft_itoa.c \
                          libft/ft_substr.c \
                          libft/ft_strjoin.c \
                          libft/ft_strnstr.c \
                          libft/ft_isprint.c \
                          libft/ft_memcpy.c \
                          libft/ft_strncmp.c \
                          libft/ft_lstdelone.c \
                          libft/ft_isdigit.c \
                          libft/ft_lstmap.c \
                          libft/ft_memcmp.c \
                          libft/ft_strrchr.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_atoi.c \
                          libft/ft_strtrim.c \
                          libft/ft_lstsize.c \
                          libft/ft_isascii.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_lstiter.c \
                          libft/ft_isalpha.c \
                          libft/ft_isalnum.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_memchr.c \
                          libft/ft_lstlast.c \
                          libft/ft_strlcpy.c \
                          libft/ft_lstnew.c \
                          libft/ft_strchr.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_tolower.c \
                          libft/ft_striteri.c \
                          libft/ft_lstclear.c \
                          libft/ft_toupper.c \
                          libft/ft_strmapi.c \
                          libft/ft_calloc.c \
                          libft/ft_split.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlen.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_strdup.c \

BSRCS 	= sources/bonus/checker_bonus.c \
                          get_next_line/get_next_line.c \
                          get_next_line/get_next_line_utils.c \
                          sources/sorting_utils/sorting_algo_0.c \
                          sources/sorting_utils/sorting_algo_1.c \
                          sources/sorting_utils/sorting_algo_2.c \
                          sources/stack_utils/stack_utils_0.c \
                          sources/stack_utils/stack_utils_1.c \
                          sources/stack_utils/stack_utils_2.c \
                          sources/bonus/operations_0_bonus.c \
                          sources/bonus/operations_1_bonus.c \
                          sources/bonus/operations_2_bonus.c \
                          sources/operations/operations_0.c \
                          sources/operations/operations_1.c \
                          sources/operations/operations_2.c \
                          sources/parsing/error_handler.c \
                          ft_printf/ft_printf.c \
                          ft_printf/ft_putnbr.c \
                          ft_printf/ft_putstr.c \
                          ft_printf/ft_puthex.c \
                          ft_printf/ft_putadd.c \
                          ft_printf/ft_putunbr.c \
                          ft_printf/ft_putchar.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_bzero.c \
                          libft/ft_itoa.c \
                          libft/ft_substr.c \
                          libft/ft_strjoin.c \
                          libft/ft_strnstr.c \
                          libft/ft_isprint.c \
                          libft/ft_memcpy.c \
                          libft/ft_strncmp.c \
                          libft/ft_lstdelone.c \
                          libft/ft_isdigit.c \
                          libft/ft_lstmap.c \
                          libft/ft_memcmp.c \
                          libft/ft_strrchr.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_atoi.c \
                          libft/ft_strtrim.c \
                          libft/ft_lstsize.c \
                          libft/ft_isascii.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_lstiter.c \
                          libft/ft_isalpha.c \
                          libft/ft_isalnum.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_memchr.c \
                          libft/ft_lstlast.c \
                          libft/ft_strlcpy.c \
                          libft/ft_lstnew.c \
                          libft/ft_strchr.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_tolower.c \
                          libft/ft_striteri.c \
                          libft/ft_lstclear.c \
                          libft/ft_toupper.c \
                          libft/ft_strmapi.c \
                          libft/ft_calloc.c \
                          libft/ft_split.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlen.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_strdup.c 

OBJS 	= $(SRCS:.c=.o)
BOBJS 	= $(BSRCS:.c=.o)

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN 	= \033[1;36m

.c.o:
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
	@printf "$(GREEN)Compiled:$(CLR_RMV) $<\n"

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(CYAN)Compiling...$(CLR_RMV)\n"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)Compiled:$(CLR_RMV) $(NAME)\n"

bonus: $(BNAME)

$(BNAME): $(BOBJS)
	@printf "$(CYAN)Compiling...$(CLR_RMV)\n"
	@$(CC) $(FLAGS) -o $(BNAME) $(BOBJS)
	@printf "$(GREEN)Compiled:$(CLR_RMV) $(BNAME)\n"

clean:
	@printf "$(RED)Cleaning...$(CLR_RMV)\n"
	@$(RM) $(OBJS) $(BOBJS)
	@printf "$(GREEN)Cleaned successfully !$(CLR_RMV)\n"

fclean: clean
	@printf "$(RED)FULL Cleaning...$(CLR_RMV)\n"
	@$(RM) $(NAME) $(BNAME)
	@printf "$(GREEN)FULL Cleaned successfully !$(CLR_RMV)\n"

re: fclean all
