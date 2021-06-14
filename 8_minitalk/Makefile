NAME = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
SRCS = \
	server.c
CLIENT_SRCS = \
	client.c
OBJS = $(SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif

%.o : %.c
	$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(CDEBUG) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)
$(CLIENT) : $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CDEBUG) -L$(LIBFT_PATH) -lft -o $(CLIENT) $(CLIENT_OBJS)


all : $(NAME) $(CLIENT)

clean :
	rm -f $(OBJS) $(CLIENT_OBJS)
	make -C $(LIBFT_PATH) clean
fclean : clean
	rm -f $(NAME) $(CLIENT)
	make -C $(LIBFT_PATH) fclean
re : fclean all

.PHONY: all clean fclean re bonus
