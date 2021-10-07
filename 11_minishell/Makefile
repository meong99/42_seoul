NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK_RDLINE = $(CPPFLAGS) $(LDFLAGS) -lreadline
INC = -I includes
OBJS_PAHT = objs
SRCS_PAHT = srcs
LIBFT_PATH = libft

SRCS = \
	commands/com_bin.c\
	commands/com_cd.c\
	commands/com_env.c\
	commands/com_exit.c\
	commands/com_export.c commands/com_export_print.c commands/com_export_error.c commands/com_export_sorting.c\
	commands/com_echo.c\
	commands/com_pwd.c\
	commands/com_unset.c commands/com_unset_error.c\
	init_commands.c init_env_variable.c\
	error.c\
	exe_commands.c\
	heredoc.c\
	main.c\
	pipe.c\
	quotation_mark.c\
	split_and_pars.c\
	temp.c

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PAHT)/, $(OBJS_NAME))

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Wall -Wextra -Werror
endif
ifeq ($(SANI), 1)
	CFLAGS = -fsanitize=address -Wall -Wextra -Werror
endif

$(OBJS_PAHT)/%.o: $(SRCS_PAHT)/%.c
	@mkdir -p $(OBJS_PAHT)/commands
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
