NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LINK_RDLINE = $(CPPFLAGS) $(LDFLAGS) -lreadline
INC = -I includes
OBJS_PAHT = objs
SRCS_PAHT = srcs
LIBFT_PATH = libft

NO_COLOR = \033[1;36m
KILL_COLOR	= \033[0m

SRCS = \
	command/com_bin.c command/com_bin_error.c command/com_bin_set.c\
	command/com_cd.c\
	command/com_env.c\
	command/com_exit.c\
	command/com_export.c command/com_export_print.c command/com_export_error.c command/com_export_sorting.c\
	command/com_echo.c\
	command/com_pwd.c\
	command/com_unset.c command/com_unset_error.c\
	redirection/redir_append.c redirection/redir_heredoc.c redirection/redir_input.c redirection/redir_output.c\
	init/init_commands.c init/init_env_variable.c\
	parse/parse_dollar.c parse/quotation_mark.c parse/parse.c parse/parse_append.c parse/parse_greater.c parse/parse_heredoc.c\
	parse/parse_less.c parse/parse_pipe.c parse/parse_redir.c parse/parse_space.c\
	set_command/set_commands.c set_command/dup_fd.c set_command/util.c\
	signal/signal.c\
	main.c free.c terminal.c\

OBJS_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJS_PAHT)/, $(OBJS_NAME))

ifeq ($(DEBUG), 1)
	CFLAGS = -g -Wall -Wextra -Werror
endif
ifeq ($(SANI), 1)
	CFLAGS = -fsanitize=address -Wall -Wextra -Werror
endif

$(OBJS_PAHT)/%.o: $(SRCS_PAHT)/%.c
	@mkdir -p $(OBJS_PAHT)/command
	@mkdir -p $(OBJS_PAHT)/redirection
	@mkdir -p $(OBJS_PAHT)/init
	@mkdir -p $(OBJS_PAHT)/parse
	@mkdir -p $(OBJS_PAHT)/set_command
	@mkdir -p $(OBJS_PAHT)/signal
	@mkdir -p $(OBJS_PAHT)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME) : $(OBJS)
	@echo "$(NO_COLOR)make objects$(KILL_COLOR)"
	@make -C libft
	@$(CC) $(CFLAGS) $(LINK_RDLINE) $(INC) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft
	@echo "$(NO_COLOR)done$(KILL_COLOR)"
all : $(NAME)

clean :
	@make -C $(LIBFT_PATH) clean
	@echo "$(NO_COLOR)clean minishell$(KILL_COLOR)"
	@rm -rf $(OBJS_PAHT)

fclean :
	@make -C $(LIBFT_PATH) fclean
	@echo "$(NO_COLOR)fclea mknishell$(KILL_COLOR)"
	@rm -rf $(OBJS_PAHT)
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
