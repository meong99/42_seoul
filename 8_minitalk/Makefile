NAME = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
INCLUDES = includes
OBJS_PATH = objs
SRCS_PATH = srcs

SRCS = \
	server.c\
	server_util.c
CLIENT_SRCS = \
	client.c
OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
CLIENT_OBJS_NAME = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(OBJS_PATH)/, $(CLIENT_OBJS_NAME))

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif
ifeq ($(SANI), true)
	CDEBUG = -g -fsanitize=address
endif

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) $(CDEBUG) -I $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS) $(CLIENT)
	$(CC) $(CFLAGS) $(CDEBUG) -I $(INCLUDES) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)
$(CLIENT) : $(CLIENT_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(CDEBUG) -I $(INCLUDES) -L$(LIBFT_PATH) -lft -o $(CLIENT) $(CLIENT_OBJS)


all : $(NAME)

clean :
	rm -f $(OBJS) $(CLIENT_OBJS)
	make -C $(LIBFT_PATH) fclean
fclean : clean
	rm -f $(NAME) $(CLIENT)
re : fclean all

.PHONY: all clean fclean re bonus
