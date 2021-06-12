NAME = ft_server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
SRCS = \
	server.c
OBJS = $(SRCS:.c=.o)

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)


all : $(NAME)

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
re : fclean all

.PHONY: all clean fclean re bonus
