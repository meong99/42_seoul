NAME = server
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
INCLUDES = -I includes
OBJS_PATH = objs

SRCS = \
	server.c\
	server_util.c
CLIENT_SRCS = \
	client.c

BONUS_SRCS = \
	server_bonus.c\
	server_util_bonus.c
BONUS_CLIENT_SRCS = \
	client_bonus.c\
	client_util_bonus.c


ifeq ($(BONUS), true)
	SRCS_PATH = bonus
	OBJS_NAME = $(BONUS_SRCS:.c=.o)
	OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
	CLIENT_OBJS_NAME = $(BONUS_CLIENT_SRCS:.c=.o)
	CLIENT_OBJS = $(addprefix $(OBJS_PATH)/, $(CLIENT_OBJS_NAME))
else
	SRCS_PATH = srcs
	OBJS_NAME = $(SRCS:.c=.o)
	OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))
	CLIENT_OBJS_NAME = $(CLIENT_SRCS:.c=.o)
	CLIENT_OBJS = $(addprefix $(OBJS_PATH)/, $(CLIENT_OBJS_NAME))
endif

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif
ifeq ($(SANI), true)
	CDEBUG = -g -fsanitize=address
endif

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(CDEBUG) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS) $(CLIENT)
	$(CC) $(CFLAGS) $(CDEBUG) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)
$(CLIENT) : $(CLIENT_OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(CDEBUG) -L$(LIBFT_PATH) -lft -o $(CLIENT) $(CLIENT_OBJS)


all : $(NAME)

clean :
	rm -rf $(OBJS_PATH)
	make -C $(LIBFT_PATH) fclean
fclean : clean
	rm -f $(NAME) $(CLIENT)
re : fclean all

bonus :
	make BONUS=true all
.PHONY: all clean fclean re bonus
