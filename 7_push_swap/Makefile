NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFT_PATH = ./libft
SRCS = \
	push_swap.c\
	swap_stack.c\
	ft_strncmp.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)


all : $(NAME)

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re bonus
