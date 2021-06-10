NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_PATH = ./libft
SRCS = \
	push_swap.c\
	rotate.c\
	swap_push.c\
	init.c\
	sorting.c\
	util.c\
	invalid_check.c\
	quick_sort.c
OBJS = $(SRCS:.c=.o)

ifeq ($(DEBUG), true)
	CDEBUG = -g
endif

%.o : %.c
	$(CC) $(CFLAGS) $(DEBUG) -c $< -o $@

$(NAME) : $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(DEBUG) -L$(LIBFT_PATH) -lft -o $(NAME) $(OBJS)


all : $(NAME)

clean :
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
fclean : clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
re : fclean all

.PHONY: all clean fclean re bonus
