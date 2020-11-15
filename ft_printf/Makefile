NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRCS = \
		ft_itoa_base.c \
		ft_list_ctrl.c \
		ft_parsing_page.c \
		ft_parsing_variable.c \
		ft_print_page.c \
		ft_printf.c \
		./libft/ft_putchar_fd.c \
		./libft/ft_putstr_fd.c \
		./libft/ft_strlcpy.c \
		./libft/ft_strlen.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	ar rcs $@ $^
bonus: $(BOBJS)
	ar rcs $(NAME) $^
clean :
	rm -f $(BOBJS) $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all clean fclean re bonus
