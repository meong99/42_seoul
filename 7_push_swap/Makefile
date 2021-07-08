NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = libft
INCLUDES = -I includes
OBJS_PATH = objs
SRCS_PATH = srcs

SRCS = \
	push_swap.c\
	rotate.c\
	swap_push.c\
	init.c\
	sorting.c\
	util.c\
	invalid_check.c\
	temp.c\
	quick_sort.c

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_NAME))

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif
ifeq ($(SANI), true)
	CDEBUG = -g -fsanitize=address
endif

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) $(INCLUDES) $(CDEBUG) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(CDEBUG) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)


all : $(NAME)

clean :
	rm -rf $(OBJS)
	make -C $(LIBFT_PATH) fclean
fclean : clean
	rm -rf $(NAME) $(OBJS_PATH)
re : fclean all

.PHONY: all clean fclean re bonus
