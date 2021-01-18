NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
SRCS = \
		ft_itoa_base.c \
		ft_parsing_page.c \
		ft_parsing_variable.c \
		ft_print_page.c \
		ft_bonus_parsing.c \
		ft_printf.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)
bonus : all
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	make -C libft
	mv libft/libft.a ./$(NAME)
	$(AR) $@ $^
clean :
	rm -f $(OBJS)
	make clean -C libft
fclean : clean
	rm -f $(NAME)
	make fclean -C libft
re : fclean all
test :
	$(CC) $(FLAGS) *.c ./libft/*.c
testclean :
	rm a.out main.c
.PHONY: all clean fclean re bonus
