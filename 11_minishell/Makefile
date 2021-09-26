NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK_RDLINE = -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -lreadline
INC = -I includes
OBJS_PAHT = objs
SRCS_PAHT = srcs
LIBFT_PATH = libft

SRCS = \
	error.c\
	exe_commands.c\
	heredoc.c\
	init_all.c\
	main.c\
	pipe.c\
	quotation_mark.c\
	run_c_process.c\
	run_p_process.c\
	split_and_parsing.c

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PAHT)/, $(OBJS_NAME))

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Wall -Wextra -Werror
endif
ifeq ($(SANI), 1)
	CFLAGS = -fsanitize=address -Wall -Wextra -Werror
endif

$(OBJS_PAHT)/%.o: $(SRCS_PAHT)/%.c
	@mkdir -p $(OBJS_PAHT)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(LINK_RDLINE) $(INC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft
all : $(NAME)

clean :
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS_PAHT)

fclean :
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS_PAHT)
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re