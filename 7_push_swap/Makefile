NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c

OBJS = $(SRCS:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)


all : $(NAME)

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re bonus
