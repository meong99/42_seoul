NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes
OBJS_PATH = objs
SRCS_PATH = srcs

SRCS = \
	main.c\
	error_check.c\
	init_all.c\
	thread_philo.c\
	free_all.c\
	util.c

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Wall -Wextra -Werror
endif
ifeq ($(SANI), 1)
	CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror
endif

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all : $(NAME)

clean :
	rm -rf $(OBJS_PATH)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re bonus